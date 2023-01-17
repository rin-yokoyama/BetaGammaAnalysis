/**
 * @file EuricaMergerData.hpp
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief
 * @version 0.1
 * @date 2023-01-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __EURICA_MERGER_DATA_HPP__
#define __EURICA_MERGER_DATA_HPP__

#include "OutputTreeData.hpp"
#include "Data_bigrips.h"
#include "Data_wasabi.h"
#include "Data_eurica.h"

namespace eurica
{
    class BigRIPSData;
    class WasabiData;
    class ClusterData;
    // typedef OutputTreeData<eurica::Data_wasabi, eurica::Data_eurica> WasabiData;
    // typedef OutputTreeData<WasabiData, eurica::Data_bigrips> BigRIPSData;
    // typedef OutputTreeData<BigRIPSData, BigRIPSData> MergedData;
    // using WasabiData = OutputTreeData<eurica::Data_wasabi, eurica::Data_eurica>;
    // using MergedData = OutputTreeData<WasabiData, eurica::Data_bigrips>;
    // using BetaMergedData = OutputTreeData<MergedData, MergedData>;
}

/**
 * @brief Data container class for a BigRIPS event
 *
 */
class eurica::BigRIPSData
{
public:
    BigRIPSData() : aoq_(0), zet_(0), ts_(0), evtnumber_(0), runnumber_(0){};
    BigRIPSData(const BigRIPSData &rhs)
    {
        aoq_ = rhs.aoq_;
        zet_ = rhs.zet_;
        ts_ = rhs.ts_;
        evtnumber_ = rhs.evtnumber_;
        runnumber_ = rhs.runnumber_;
    };
    virtual ~BigRIPSData(){};

    Double_t aoq_;
    Double_t zet_;
    ULong64_t ts_;
    ULong64_t evtnumber_;
    Int_t runnumber_;
};

class eurica::WasabiData
{
public:
    WasabiData(){};
    WasabiData(const WasabiData &rhs)
    {
    }
    virtual ~WasabiData() {}
};

class eurica::ClusterData
{
public:
    ClusterData() {}
    ClusterData(const ClusterData &rhs)
    {
    }
    virtual ~ClusterData() {}
};

#endif //__EURICA_MERGER_DATA_HPP__