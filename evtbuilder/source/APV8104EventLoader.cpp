#include "APV8104EventLoader.h"

APV8104EventLoader::APV8104EventLoader(const YAML::Node &node, const std::string &name) : TTreeEventLoaderBase(node, name)
{
    data_reader_ = new TTreeReaderValue<APVMultiData>(*reader_, branch_name_.c_str());
}

bool APV8104EventLoader::GetNext()
{
    /// A function to load next APVMultiData event
    auto loadNextEvent = [this]()
    {
        if(!reader_->Next())
        {
            eof_ = true;
            return false;
        }
        data_vec_ = data_reader_->Get();
        itr_ = data_vec_->GetData().begin();
        if(itr_ == data_vec_->GetData().end())
        {
            return false;
        }
        ts_ = (*itr_)->GetTiming();
        return true;
    };

    if(!data_vec_)
    {
        /// First event
        return loadNextEvent();
    }
    else if(itr_==data_vec_->GetData().end())
    {
        /// End of an event
        return loadNextEvent();
    }
    else
    {
        /// Middle of an event
        ++itr_;
        ts_ = (*itr_)->GetTiming();
        return true;
    }
}

void APV8104EventLoader::LoadTS()
{
    data_reader_->Get()->GetData().back()->GetTiming();
}