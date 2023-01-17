#include "EuricaBetaTreeMerger.h"

const std::string eurica::BetaTreeMerger::kMsgPrefix("[BetaTreeMerger]:");

eurica::BetaTreeMerger::BetaTreeMerger() : TreeMerger<BetaMergedData, MergedData, MergedData>()
{
}

eurica::BetaTreeMerger::BetaTreeMerger(TSScannerBase<MergedData> *input1, TSScannerBase<MergedData> *input2)
    : TreeMerger<BetaMergedData, MergedData, MergedData>(input1, input2)
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

bool eurica::BetaTreeMerger::IsInGate(const MergedData &in1, const MergedData &in2)
{
    return true;
}