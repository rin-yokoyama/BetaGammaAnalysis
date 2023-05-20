#ifndef __EURICA_BETATREEMERGER_HPP__
#define __EURICA_BETATREEMERGER_HPP__

#include "TreeMerger.hpp"
#include "EuricaBetaTSScanner.h"
#include "EuricaImplantTSScanner.h"
#include "EuricaMergerData.hpp"

/** merger class **/
// input_2 events will be merged to a vector in input_1

namespace eurica
{
    class BetaTreeMerger;
    struct WasabiHit
    {
        Int_t x_ = -1;
        Int_t y_ = -1;
        Int_t layer_ = -1;
    };
}

class eurica::BetaTreeMerger : public TreeMerger<eurica::BetaData, eurica::ImplantData, eurica::ImplantData>
{
public:
    const static std::string kMsgPrefix;

    BetaTreeMerger();
    BetaTreeMerger(eurica::BetaTSScanner *input1, eurica::ImplantTSScanner *input2);
    virtual ~BetaTreeMerger();

    // void Configure(const std::string &yaml_node_name); // loads configuration from yaml
    // void Merge(); // merge events from input2 to input1
    // void Write(); // writes tree to the file
    virtual bool IsInGate(const eurica::ImplantData &in1, const eurica::ImplantData &in2);

protected:
    Double_t correlation_radius_;
    eurica::WasabiHit CalculateImplantPosition(const eurica::WasabiData &data);
    std::vector<eurica::WasabiHit> CalculateBetaPosition(const eurica::WasabiData &data);
};

#endif /* __EURICA_BETATREEMERGER_HPP__ */