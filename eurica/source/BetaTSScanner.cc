#include "EuricaBetaTSScanner.h"

const std::string eurica::BetaTSScanner::kMsgPrefix("[BetaTSScanner]:");

void eurica::BetaTSScanner::SetReader()
{
    TSScannerBase<eurica::MergedData>::SetReader();
    std::string br_name = yaml_reader_->GetString("BranchName");
    tree_data_ = new TTreeReaderValue<eurica::MergedData>(*tree_reader_, br_name.c_str());
    std::cout << kMsgPrefix << "TreeReaderValue: " << br_name << " created." << std::endl;
    return;
}

Bool_t eurica::BetaTSScanner::IsInGate()
{
    return true;
}
