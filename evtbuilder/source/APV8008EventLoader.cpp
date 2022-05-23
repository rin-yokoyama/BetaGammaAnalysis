#include "APV8008EventLoader.h"

APV8008EventLoader::APV8008EventLoader(const YAML::Node &node, const std::string &name) : TTreeEventLoaderBase(node,name)
{
    data_reader_ = new TTreeReaderValue<art::TAPV8008Data>(*reader_, branch_name_.c_str());
}

bool APV8008EventLoader::GetNext()
{
    if(!reader_->Next()){
        eof_ = true;
        return false;
    }
    else
    {
        data_ = data_reader_->Get();
        return true;
    }
}

void APV8008EventLoader::LoadTS()
{
    ts_ = data_reader_->Get()->GetTiming();
}
