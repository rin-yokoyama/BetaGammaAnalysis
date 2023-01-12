#include "APV8008EventLoader.h"

APV8008EventLoader::APV8008EventLoader(const YAML::Node &node, const std::string &name) : TTreeEventLoaderBase(node, name)
{
    // data_reader_ = new TTreeReaderValue<TClonesArray>(*reader_, branch_name_.c_str());
    chain_->SetBranchAddress<TClonesArray>(branch_name_.c_str(), &array_);
    evt_ = 0;
}

bool APV8008EventLoader::GetNext()
{
    /*
    if (!reader_->Next())
    {
        eof_ = true;
        return false;
    }
    else
    {
        array = *data_reader_->Get();
        if (array.GetEntriesFast())
        {
            data_ = (art::TAPV8008Data *)array.At(0);
            if (data_)
            {
                ts_ = data_->GetTiming();
                return true;
            }
        }
        array_ = data_reader_->Get();
        if (!array_)
        {
            return false;
        }
        if (array_->GetEntriesFast())
        {
            data_ = (art::TAPV8008Data *)array_->At(0);
            if (data_)
            {
                ts_ = data_->GetTiming();
                return true;
            }
        }
    }
    */
    ++evt_;
    if (evt_ == chain_->GetEntries())
    {
        eof_ = true;
        return false;
    }
    else
    {
        chain_->GetEntry(evt_);
        if (!array_)
        {
            return false;
        }
        if (array_->GetEntries())
        {
            data_ = (art::TAPV8008Data *)array_->At(0);
            if (data_)
            {
                ts_ = data_->GetTiming();
                return true;
            }
        }
    }
    return false;
}

void APV8008EventLoader::LoadTS()
{
    array_ = data_reader_->Get();
    if (array_)
    {
        if (array_->GetEntries())
        {
            auto data = (art::TAPV8008Data *)array_->At(0);
            if (data)
            {
                ts_ = data->GetTiming();
            }
        }
    }
}

const double &APV8008EventLoader::GetLastTS()
{
    chain_->GetEntry(chain_->GetEntries() - 1);
    this->LoadTS();
    return this->GetTS();
}