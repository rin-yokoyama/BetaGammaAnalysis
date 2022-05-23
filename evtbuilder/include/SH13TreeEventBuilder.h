#ifndef __SH13_TREE_EVENT_BUILDER__
#define __SH13_TREE_EVENT_BUILDER__

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
        if (!output_tree_)
        {
            delete output_tree_;
        }
    }

    void Configure(const std::string &node_name) override;
    void Loop();

private:
    SH13S2PlusData data_;
    TTree *output_tree_ = nullptr;
};

#endif /// __SH13_TREE_EVENT_BUILDER__
