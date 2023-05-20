#include "EuricaBetaTSScanner.h"

const std::string eurica::BetaTSScanner::kMsgPrefix("[BetaTSScanner]:");

void eurica::BetaTSScanner::SetReader()
{
    TSScannerBase<eurica::ImplantData>::SetReader();
    std::string br_name = yaml_reader_->GetString("BranchName");
    tree_data_ = new TTreeReaderValue<eurica::ImplantData>(*tree_reader_, br_name.c_str());
    std::cout << kMsgPrefix << "TreeReaderValue: " << br_name << " created." << std::endl;
    return;
}

Bool_t eurica::BetaTSScanner::IsInGate()
{
    const auto data = tree_data_->Get();
    // skip event if bigrips data is NOT empty
    if (!data->output_vec_.empty())
        return false;
    return true;
}
