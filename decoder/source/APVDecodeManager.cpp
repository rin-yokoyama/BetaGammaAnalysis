#include "APVDecodeManager.h"
#include <iostream>

const unsigned int APVDecodeManager::kPrintFreq = 128000*40;
const unsigned int APVDecodeManager::kNWorkers = 4;

APVDecodeManager::~APVDecodeManager()
{
	fin_.close();
	rootfile_.Close();
	if (buffer_)
		delete[] buffer_;
	if (decoder_)
		delete decoder_;
	if (prog_printer_)
		delete prog_printer_;
}

void APVDecodeManager::Init(std::string module_type)
{
	/// check if files are open
	if (!fin_)
	{
		std::cout << "[APVDecodeManager]: Input file is not open." << std::endl;
		return;
	}
	if (!rootfile_.IsOpen())
	{
		std::cout << "[APVDecodeManager]: Output root file is not open." << std::endl;
		return;
	}

	fin_.seekg(0, fin_.end);
	prog_printer_ = new ProgressPrinter(0, (double)fin_.tellg(), kPrintFreq);
	fin_.seekg(0, fin_.beg);

	/// Create a root tree and add a branch for the APVSingleData
	output_tree_ = new TTree("APVTree", "APVTree");
	output_tree_->Branch("APVMultiData", "APVMultiData", &block_data_);

	/// Allocate buffer with the size of block_size_
	buffer_ = new char[block_size_ * kNWorkers];

	/// Create kNWorkers decoder instances
	if (module_type == "APV8104" || module_type == "APV8508")
	{
		for (int i = 0; i < kNWorkers; ++i)
		{
			auto decoder = new APV8104Decoder();
			decoder->SetAPVModuleType(module_type);
			//auto decoder_base = (APVDecoderBase<APVSingleData> *)decoder;
			decoders_.emplace_back(*decoder);
		}
		loop_ready_ = true;
	}
	else
	{
		std::cout << "[APVDecodeManager]: Invalid module type " << module_type << std::endl;
	}
}

void APVDecodeManager::Loop()
{
	if (!loop_ready_)
	{
		std::cout << "[APVDecodeManager]: The loop is not ready. Exiting..." << std::endl;
		return;
	}
	std::cout << "[APVDecodeManager]: Starting the main loop..." << std::endl;
	double ts_max = 0;
	std::vector<APVSingleData *> last_block;

	/// main loop: read untill eof
	while (!fin_.read(buffer_, sizeof(char) * kNWorkers * block_size_).eof())
	{
		std::vector<std::thread> threads;
		auto func = [this](int i){decoders_[i].Decode(buffer_+i*block_size_, block_size_);};
		for (int i = 0; i < kNWorkers; i++)
		{
			//threads.emplace_back(func, i);
			func(i);
		}

		//for (auto &th : threads)
		//{
		//	th.join();
		//}
		/// combine vectors from each thread
		std::vector<APVSingleData *> decoded;
		for (auto &decoder : decoders_)
		{
			decoded.insert(decoded.end(), decoder.GetDataVec().begin(), decoder.GetDataVec().end());
		}

		std::sort(decoded.begin(), decoded.end(), [](APVSingleData *x, APVSingleData *y)
				  { return x->GetTiming() < y->GetTiming(); });

		/// A function to insert elements that have smaller time stamps
		/// than the last element of the previous block
		auto moveElem = [&last_block](APVSingleData *x)
		{
			last_block.insert(
				std::find_if(last_block.begin(), last_block.end(), [x](APVSingleData *a)
							 { return a->GetTiming() > x->GetTiming(); }),
				//last_block.end(),
				x);
		};

		/// The iterator to the first element with a timestamp grater than ts_max
		auto first_elem = std::find_if(decoded.begin(), decoded.end(), [&ts_max](APVSingleData *x)
									   {return x->GetTiming() > ts_max; });

		if (first_elem == decoded.begin())
		{
			if(!last_block.empty())
			{
				block_data_.SetData(last_block);
				output_tree_->Fill();
			}
			if(!decoded.empty())
			{
				last_block = decoded;
				ts_max = last_block.back()->GetTiming();
			}
		}
		else
		{

			//std::for_each(decoded.begin(), first_elem - 1, moveElem);
			last_block.insert(last_block.end(), decoded.begin(), first_elem - 1);
			std::sort(last_block.begin(), last_block.end(), [](APVSingleData *x, APVSingleData *y)
					  { return x->GetTiming() < y->GetTiming(); });

			//for(const auto& dec: last_block){
			//	std::cout << std::fixed << std::setprecision(4) << dec->GetTiming() << std::endl;
			//}
			if(!last_block.empty()){
				block_data_.SetData(last_block);
				output_tree_->Fill();
			}
			//std::cout << last_block.size() << std::endl;
			last_block = std::vector<APVSingleData *>(first_elem, decoded.end());
			if(!last_block.empty()){
				ts_max = last_block.back()->GetTiming();
			}
		}

		prog_printer_->PrintProgress(fin_.tellg());
	}
	output_tree_->Write();
}
