/**
 * @file APV8104EventLoader.h
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief   A class to handle a data file from APV8104 
 * @version 0.1
 * @date 2022-05-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __APV8104__EVENT_LOADER__
#define __APV8104__EVENT_LOADER__

#include "TTreeEventLoaderBase.h"
#include "APVMultiData.h"
#include <TTreeReaderValue.h>

class APV8104EventLoader : public TTreeEventLoaderBase
{
public:
    APV8104EventLoader() {}
    virtual ~APV8104EventLoader()
    {
        if(data_reader_)
            delete data_reader_;
    }
    /**
     * @brief Construct a new APV8104EventLoader object
     * 
     * @param node : YAML node for TTreeEventLoaderBase initialization
     */
    APV8104EventLoader(const YAML::Node &node, const std::string &name);

    void LoadTS() override;
    /**
     * @brief Load the Next APVSingleData object
     *  
     * @return false if eof/ true if sucess
     */
    bool GetNext() override;

    /**
     * @brief Get the Event object
     * 
     * @return APVSingleData* 
     */
    APVSingleData* GetEvent() {return *itr_;}
private:
    APVMultiData *data_vec_ = nullptr;  /// A pointer to the current APVMultiData object
    std::vector<APVSingleData*>::iterator itr_; /// An iterater of the data vector of data_vec_
    TTreeReaderValue<APVMultiData> *data_reader_ = nullptr; /// A pointer to the TTreeReaderValue object
};

#endif /// __APV8104__EVENT_LOADER__