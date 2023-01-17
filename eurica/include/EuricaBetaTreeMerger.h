#ifndef __EURICA_BETATREEMERGER_HPP__
#define __EURICA_BETATREEMERGER_HPP__

#include "TreeMerger.hpp"
#include "TSScannerBase.hpp"
#include "EuricaMergerData.hpp"

/** merger class **/
// input_2 events will be merged to a vector in input_1

namespace eurica
{
    class BetaTreeMerger;
}

class eurica::BetaTreeMerger : public TreeMerger<BetaMergedData, MergedData, MergedData>
{
public:
    const static std::string kMsgPrefix;

    BetaTreeMerger();
    BetaTreeMerger(TSScannerBase<MergedData> *input1, TSScannerBase<MergedData> *input2);
    virtual ~BetaTreeMerger();

    // void Configure(const std::string &yaml_node_name); // loads configuration from yaml
    // void Merge(); // merge events from input2 to input1
    // void Write(); // writes tree to the file
    virtual bool IsInGate(const MergedData &in1, const MergedData &in2);

protected:
    Double_t correlation_radius_;
};

#endif /* __EURICA_BETATREEMERGER_HPP__ */