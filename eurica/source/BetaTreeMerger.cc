#include "EuricaBetaTreeMerger.h"

const std::string eurica::BetaTreeMerger::kMsgPrefix("[BetaTreeMerger]:");

eurica::BetaTreeMerger::BetaTreeMerger() : TreeMerger<eurica::BetaData, eurica::ImplantData, eurica::ImplantData>()
{
}

eurica::BetaTreeMerger::BetaTreeMerger(eurica::BetaTSScanner *input1, eurica::ImplantTSScanner *input2)
    : TreeMerger<eurica::BetaData, eurica::ImplantData, eurica::ImplantData>(input1, input2)
{
    YamlReader yaml_reader("BetaTreeMerger");
    correlation_radius_ = yaml_reader.GetDouble("CorrelationRadius");
}

eurica::BetaTreeMerger::~BetaTreeMerger()
{
}
/*
template <class TOUT, class TIN1, class TIN2>
void BetaTreeMerger<TOUT,TIN1,TIN2>::Configure(const std::string &yaml_node_name)
   : TreeMerger(yaml_node_name)
{
}
template <class TOUT, class TIN1, class TIN2>
void BetaTreeMerger<TOUT,TIN1,TIN2>::Merge()
{
    return;
}
template <class TOUT, class TIN1, class TIN2>
void BetaTreeMerger<TOUT,TIN1,TIN2>::Write()
{
    return;
}
*/

bool eurica::BetaTreeMerger::IsInGate(const eurica::ImplantData &in1, const eurica::ImplantData &in2)
{
    const auto pid = in2.output_vec_.at(0);
    const auto wasabi_implant = in2.input_.input_;
    const auto wasabi_beta = in1.input_.input_;

    // skip event if pid_ is not in any isotope gate
    if (!pid.pid_)
        return false;

    const auto implant = CalculateImplantPosition(wasabi_implant);
    if (implant.layer_ < 0)
        return false;
    const auto beta = CalculateBetaPosition(wasabi_beta);

    if (std::any_of(beta.begin(), beta.end(), [&implant](const WasabiHit &x)
                    { return x.x_ == implant.x_ && x.y_ == implant.y_ && x.layer_ == implant.layer_; }))
        return true;
    else
        return false;
}

eurica::WasabiHit eurica::BetaTreeMerger::CalculateImplantPosition(const eurica::WasabiData &data)
{
    eurica::WasabiHit implant;

    // searching for the eariest x and y of the 1st layer
    const Double_t EThresh = 3800;
    const Double_t TThresh = -10000;

    // Filter hits by layer, energy, and time
    std::vector<eurica::WasabiHitData> filteredX;
    std::vector<eurica::WasabiHitData> filteredY;
    auto filterFunc = [&EThresh, &TThresh](const eurica::WasabiHitData &x)
    {
        return (x.layer_ == 0) && (x.energy_ > EThresh) && (x.time_ > TThresh);
    };
    std::copy_if(data.x_.begin(), data.x_.end(), std::back_inserter(filteredX), filterFunc);
    std::copy_if(data.y_.begin(), data.y_.end(), std::back_inserter(filteredY), filterFunc);

    if (filteredX.empty() || filteredY.empty())
        return implant;

    // sort hits by time
    auto sortFunc = [](const eurica::WasabiHitData &a, const eurica::WasabiHitData &b)
    {
        return a.time_ > b.time_; // descending order
    };
    std::sort(filteredX.begin(), filteredX.end(), sortFunc);
    std::sort(filteredY.begin(), filteredY.end(), sortFunc);

    implant.x_ = filteredX.at(0).id_;
    implant.y_ = filteredY.at(0).id_;

    std::vector<eurica::WasabiHitData> hitsInPosition;
    std::copy_if(data.x_.begin(), data.x_.end(), std::back_inserter(hitsInPosition), [&implant, &EThresh](const eurica::WasabiHitData &x)
                 { return (x.id_ == implant.x_) && (x.energy_ > EThresh); });
    std::sort(hitsInPosition.begin(), hitsInPosition.end(), [](const eurica::WasabiHitData &a, const eurica::WasabiHitData &b)
              { return a.layer_ > b.layer_; });
    implant.layer_ = hitsInPosition.at(0).layer_;

    return implant;
}

std::vector<eurica::WasabiHit> eurica::BetaTreeMerger::CalculateBetaPosition(const eurica::WasabiData &data)
{
    const Double_t OverflowThresh = 5000;
    const Double_t LowThresh = 50; // delayed_ba6
    // const Double_t LowThresh=10;
    // const Double_t LowThresh=100; //delayed_ba4, delayed_ba5, delayed_nd2
    const Double_t TThresh = -10000; // delayed_ba6

    // Filter hits by layer, energy, and time
    std::vector<eurica::WasabiHitData> filteredX;
    std::vector<eurica::WasabiHitData> filteredY;
    auto filterFunc = [&OverflowThresh, &LowThresh, &TThresh](const eurica::WasabiHitData &x)
    {
        return (x.energy_ < OverflowThresh) && (x.energy_ > LowThresh) && (x.time_ > TThresh);
    };
    std::copy_if(data.x_.begin(), data.x_.end(), std::back_inserter(filteredX), filterFunc);
    std::copy_if(data.y_.begin(), data.y_.end(), std::back_inserter(filteredY), filterFunc);

    std::vector<eurica::WasabiHit> beta_vec;
    for (const auto hit_x : filteredX)
    {
        for (const auto hit_y : filteredY)
        {
            if (hit_x.layer_ == hit_y.layer_)
            {
                eurica::WasabiHit hit;
                hit.x_ = hit_x.id_;
                hit.y_ = hit_y.id_;
                hit.layer_ = hit_x.layer_;
                beta_vec.emplace_back(hit);
            }
        }
    }

    return beta_vec;
}
