/**
 * @file TTreeEventBuilder.h
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief
 * @version 0.1
 * @date 2022-05-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __TTREE_EVENT_BUILDER__
#define __TTREE_EVENT_BUILDER__

#include <vector>
#include "TTreeEventLoaderBase.h"
#include "YamlReader.hpp"
#include "ProgressPrinter.h"

class TTreeEventBuilder
{
public:
    TTreeEventBuilder() {}
    virtual ~TTreeEventBuilder()
    {
        if(prog_)
        {
            delete prog_;
        }
    }

    virtual void Configure(const std::string &node_name);
    virtual void Loop();
    /**
     * @brief Return if all the file stream reached eof
     * 
     * @return true all event_loaders_ entry has eof
     * @return false 
     */
    virtual bool CheckEoF();
    /**
     * @brief Restart all the TChain event
     * 
     */
    virtual void Restart();
    /**
     * @brief Sort the event_loaders_ by the current timestamp
     * 
     */
    virtual void Sort();
protected:
    YamlReader *yaml_reader_ = nullptr;
    double time_window_;
    std::vector<TTreeEventLoaderBase> event_loaders_;
    ProgressPrinter* prog_ = nullptr;
    double print_freq_;
};

#endif /// __TTREE_EVENT_BUILDER__