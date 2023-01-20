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
    class WasabiHitData;
    class WasabiData;
    class ClusterHitData;
    class BetaPLData;
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
    BigRIPSData() : pid_(0), aoq_(0), zet_(0), ts_(0), evtnumber_(0), runnumber_(0){};
    BigRIPSData(const BigRIPSData &rhs)
    {
        pid_ = rhs.pid_;
        aoq_ = rhs.aoq_;
        zet_ = rhs.zet_;
        ts_ = rhs.ts_;
        evtnumber_ = rhs.evtnumber_;
        runnumber_ = rhs.runnumber_;
    };
    virtual ~BigRIPSData(){};

    Int_t pid_;
    Double_t aoq_;
    Double_t zet_;
    ULong64_t ts_;
    ULong64_t evtnumber_;
    Int_t runnumber_;
};

class eurica::WasabiHitData
{
public:
    WasabiHitData() : energy_(0), time_(0), layer_(0), id_(0) {}
    WasabiHitData(const WasabiHitData &rhs)
    {
        energy_ = rhs.energy_;
        time_ = rhs.time_;
        layer_ = rhs.layer_;
        id_ = rhs.id_;
    }
    virtual ~WasabiHitData() {}

    Double_t energy_;
    Double_t time_;
    Int_t layer_;
    Int_t id_;
};
class eurica::WasabiData
{
public:
    WasabiData() : ts_(0), evtnumber_(0), runnumber_(0){};
    WasabiData(const WasabiData &rhs)
    {
        x_ = rhs.x_;
        y_ = rhs.y_;
        ts_ = rhs.ts_;
        evtnumber_ = rhs.evtnumber_;
        runnumber_ = rhs.runnumber_;
    }
    virtual ~WasabiData() {}

    virtual void Clear()
    {
        x_.clear();
        y_.clear();
    }

    std::vector<WasabiHitData *> x_;
    std::vector<WasabiHitData *> y_;
    ULong64_t ts_;
    ULong64_t evtnumber_;
    Int_t runnumber_;
};

class eurica::ClusterHitData
{
public:
    ClusterHitData() {}
    ClusterHitData(const ClusterHitData &rhs)
    {
        energy_ = rhs.energy_;
        time_ = rhs.time_;
        det_id_ = rhs.det_id_;
        crystal_id_ = rhs.crystal_id_;
    }
    virtual ~ClusterHitData() {}

    Double_t energy_;
    Double_t time_;
    Int_t det_id_;
    Int_t crystal_id_;
};

class eurica::BetaPLData
{
public:
    BetaPLData() {}
    BetaPLData(const BetaPLData &rhs) {}
    virtual ~BetaPLData() {}

    std::vector<ClusterHitData *> hits_;
    Double_t energy_;
    Double_t time_;
    Int_t id_;
};
class eurica::ClusterData
{
public:
    ClusterData() {}
    ClusterData(const ClusterData &rhs)
    {
        singles_ = rhs.singles_;
        addback_ = rhs.addback_;
        labr_ = rhs.labr_;
        beta_pl_ = rhs.beta_pl_;
    }
    virtual ~ClusterData() {}
    void Clear()
    {
        singles_.clear();
        addback_.clear();
        labr_.clear();
    }
    std::vector<ClusterHitData *> singles_;
    std::vector<ClusterHitData *> addback_;
    std::vector<ClusterHitData *> labr_;
    BetaPLData beta_pl_;
    ULong64_t ts_;
    ULong64_t evtnumber_;
    Int_t runnumber_;
};

#endif //__EURICA_MERGER_DATA_HPP__