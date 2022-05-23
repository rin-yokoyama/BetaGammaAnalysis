#ifndef __APV8008__EVENT_LOADER__
#define __APV8008__EVENT_LOADER__

#include "TTreeEventLoaderBase.h"
#include "TAPV8008Data.h"
#include <TTreeReaderValue.h>

class APV8008EventLoader : public TTreeEventLoaderBase
{
public:
    APV8008EventLoader(){}
    virtual ~APV8008EventLoader()
    {
        if(data_reader_)
            delete data_reader_;
    }
    APV8008EventLoader(const YAML::Node &node, const std::string &name);

    void LoadTS() override;
    bool GetNext() override;

    art::TAPV8008Data* GetEvent() {return data_;}
private:

    art::TAPV8008Data *data_ = nullptr;
    TTreeReaderValue<art::TAPV8008Data> *data_reader_;
};

#endif ///__APV8008__EVENT_LOADER__