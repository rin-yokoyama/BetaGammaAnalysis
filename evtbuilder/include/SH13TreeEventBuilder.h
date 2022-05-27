#ifndef __SH13_TREE_EVENT_BUILDER__
#define __SH13_TREE_EVENT_BUILDER__

#include <TFile.h>
#include <TTree.h>
#include "SH13S2PlusData.h"
#include "TTreeEventBuilder.h"
#include "APVMultiData.h"
#include "APV8104EventLoader.h"
#include "APV8008EventLoader.h"

class SH13TreeEventBuilder : public TTreeEventBuilder
{
public:
    SH13TreeEventBuilder() {}
    virtual ~SH13TreeEventBuilder()
    {
        if (!output_file_)
        {
            delete output_file_;
        }
    }

    void Configure(const std::string &node_name) override;
    void Loop();

private:
    SH13S2PlusData data_;
    TFile *output_file_ = nullptr;
    TTree *output_tree_ = nullptr;
};

#endif /// __SH13_TREE_EVENT_BUILDER__
