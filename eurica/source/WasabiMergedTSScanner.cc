#include "EuricaWasabiMergedTSScanner.h"

const std::string eurica::WasabiMergedTSScanner::kMsgPrefix("[WasabiMergedTSScanner]:");

void eurica::WasabiMergedTSScanner::SetReader()
{
    TSScannerBase<eurica::EuricaWasabiData>::SetReader();
    std::string br_name = yaml_reader_->GetString("BranchName");
    tree_data_ = new TTreeReaderValue<eurica::EuricaWasabiData>(*tree_reader_, br_name.c_str());
    std::cout << kMsgPrefix << "TreeReaderValue: " << br_name << " created." << std::endl;
    return;
}

Bool_t eurica::WasabiMergedTSScanner::IsInGate()
{
    return true;
}
