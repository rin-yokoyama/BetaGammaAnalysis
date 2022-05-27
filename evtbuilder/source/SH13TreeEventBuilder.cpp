#include "SH13TreeEventBuilder.h"

void SH13TreeEventBuilder::Configure(const std::string &node_name)
{
	TTreeEventBuilder::Configure(node_name);
	if (output_file_)
	{
		delete output_file_;
	}
	std::string fname = yaml_reader_->GetString("OutputFileName");
	output_file_ = new TFile(fname.c_str(), "recreate");
	if (output_tree_)
	{
		delete output_tree_;
	}
	output_tree_ = new TTree("SH13S2PlusTree", "SH13S2PlusTree");
	output_tree_->Branch("SH13S2PlusData", "SH13S2PlusData", &data_);

	auto node = yaml_reader_->GetNode("EventLoaders");
	event_loaders_.emplace_back(new APV8104EventLoader(node["APV8104Loader"], "APV8104"));
	event_loaders_.emplace_back(new APV8104EventLoader(node["APV8508Loader"], "APV8508"));
	event_loaders_.emplace_back(new APV8008EventLoader(node["APV8008Loader"], "APV8008"));

	print_freq_ = yaml_reader_->GetDouble("PrintFrequency", false, 1000000);
}

void SH13TreeEventBuilder::Loop()
{
	TTreeEventBuilder::Loop();
	Sort();
	double timestamp = 0;
	bool event_open = false;
	while (!CheckEoF())
	{
		auto loader = *event_loaders_.begin();
		if (!event_open)
		{
			data_.Clear();
			timestamp = (loader)->GetTS();
			event_open = true;
		}
		if ((loader)->GetName() == "APV8104")
		{
			APVSingleData event(((APV8104EventLoader *)loader)->GetData());
			int id = event.GetID();
			event.SetID(id + 10);
			if (id == 0 || id == 1)
			{
				data_.GetStopperPtr()->emplace_back(event);
			}
			else if (id == 2)
			{
				data_.GetCeBrPtr()->emplace_back(event);
			}
			else if (id == 3)
			{
				data_.GetSHTrig8104Ptr()->emplace_back(event.GetTiming());
			}
		}
		else if ((loader)->GetName() == "APV8508")
		{
			auto event = (((APV8104EventLoader *)loader)->GetData());
			int id = event.GetID();
			event.SetID(id + 20);
			if (id == 0 || id == 1)
			{
				data_.GetStopperPtr()->emplace_back(event);
			}
			else if (id == 2)
			{
				data_.GetCeBrPtr()->emplace_back(event);
			}
			else if (id == 3)
			{
				data_.GetSHTrig8508Ptr()->emplace_back(event.GetTiming());
			}
		}
		else if ((loader)->GetName() == "APV8008")
		{
			auto event = ((APV8008EventLoader *)loader)->GetEvent();
			const int id = event->GetID();
			if (id == 0 || id == 1 || id == 2 || id == 3)
			{
				data_.GetGePtr()->emplace_back(*event);
			}
			if (id == 4)
			{
				data_.GetSHTrig8008Ptr()->emplace_back(event->GetTiming());
			}
		}
		else
		{
			std::cout << "[SH13TreeEventBuilder]: Unkown event loader" << std::endl;
		}

		if (!(loader)->GetNext())
		{
			event_loaders_.erase(event_loaders_.begin());
		}
		Sort();
		loader = *event_loaders_.begin();
		if ((loader)->GetTS() > timestamp + time_window_)
		{
			output_tree_->Fill();
			event_open = false;
			prog_->PrintProgress(timestamp);
		}
		timestamp = (loader)->GetTS();
	}

	std::cout << "[SH13TreeEventBuilder]: Main loop done" << std::endl;
	output_tree_->Write();
	output_file_->Close();
}