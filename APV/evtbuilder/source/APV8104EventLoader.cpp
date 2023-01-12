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
        if (!reader_->Next())
        {
            eof_ = true;
            return false;
        }
        APVMultiData *mdata = data_reader_->Get();
        data_vec_ = mdata->GetData();
        itr_ = data_vec_->begin();
        if (itr_ == data_vec_->end())
        {
            return false;
        }
        ts_ = (*itr_).GetTiming();
        data_ = (*itr_);
        return true;
    };

    if (!data_vec_)
    {
        /// First event
        return loadNextEvent();
    }
    else if (itr_ == data_vec_->end())
    {
        /// End of an event
        return loadNextEvent();
    }
    else
    {
        /// Middle of an event
        ++itr_;
        if (itr_ < data_vec_->end())
        {
            ts_ = (*itr_).GetTiming();
            data_ = (*itr_);
            return true;
        }
        return loadNextEvent();
    }
}

void APV8104EventLoader::LoadTS()
{
    ts_ = data_reader_->Get()->GetData()->back().GetTiming();
}