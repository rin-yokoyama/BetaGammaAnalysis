
#ifndef __TTREE_EVENT_LOADER_BASE__
#define __TTREE_EVENT_LOADER_BASE__

#include <TChain.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include "MergerExceptions.h"
#include "YamlReader.hpp"

class TTreeEventLoaderBase
{
public:
    TTreeEventLoaderBase() : ts_(0) {}
    TTreeEventLoaderBase(const YAML::Node &node, const std::string &name);
    virtual ~TTreeEventLoaderBase()
    {
        if(chain_)
        {
            delete chain_;
        }
    }

    virtual void Init(const YAML::Node &node);
    virtual void SetBranchAddress() {}

    /**
     * @brief virtual function to load timestamp of the current event
     * 
     */
    virtual void LoadTS() {}
    /**
     * @brief virtual function to load the next event
     * 
     * @return true 
     * @return false 
     */
    virtual bool GetNext(){}
    virtual bool GetEoF() const { return eof_; }
    /**
     * @brief Get the current timestamp
     * 
     * @return const double& 
     */
    const double &GetTS() const { return ts_; }
    /**
     * @brief Get the First Timestamp value in the TChain
     * This method resets the file pointer to the begining 
     * @return const double& 
     */
    const double &GetFirstTS();
    /**
     * @brief Get the Last Timestamp value in the TChain
     * This method resets the file pointer to the begining 
     * @return const double& 
     */
    const double &GetLastTS();

    const std::string &GetName() const {return name_;}
    void Restart() {reader_->Restart();}
protected:
    std::string name_; /// The name of this object
    TChain *chain_ = nullptr; /// A pointer to the raw data tree chain
    double ts_;
    bool eof_ = false; /// The eof flag
    std::string branch_name_;
    TTreeReader *reader_ = nullptr;
};

#endif ///__TTREE_EVENT_LOADER_BASE__