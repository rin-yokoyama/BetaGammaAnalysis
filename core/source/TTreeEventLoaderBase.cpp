#include "TTreeEventLoaderBase.h"

TTreeEventLoaderBase::TTreeEventLoaderBase(const YAML::Node &node, const std::string &name) : ts_(0), name_(name)
{
    Init(node);
}

void TTreeEventLoaderBase::Init(const YAML::Node &node)
{
    if (chain_)
    {
        delete chain_;
    }

    chain_ = new TChain(node["TreeName"].as<std::string>().c_str());
    branch_name_ = node["BranchName"].as<std::string>();
    auto files = node["FileNames"].as<std::vector<std::string>>();
    for(const auto &file : files){
        chain_->Add(file.c_str());
    }

    if(reader_)
    {
        delete reader_;
    }
    reader_ = new TTreeReader(chain_);
}

const double &TTreeEventLoaderBase::GetFirstTS()
{
    reader_->Restart();
    GetNext();
    return GetTS();
}

const double &TTreeEventLoaderBase::GetLastTS()
{
    chain_->GetEntry(chain_->GetEntries()-1);
    LoadTS();
    return GetTS();
}