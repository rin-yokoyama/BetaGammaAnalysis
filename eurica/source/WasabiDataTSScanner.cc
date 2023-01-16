#include "EuricaWasabiDataTSScanner.h"

const std::string eurica::WasabiDataTSScanner::kMsgPrefix("[WasabiDataTSScanner]:");

void eurica::WasabiDataTSScanner::SetReader()
{
    TSScannerBase<eurica::WasabiData>::SetReader();
    std::string br_name = yaml_reader_->GetString("BranchName");
    tree_data_ = new TTreeReaderValue<eurica::WasabiData>(*tree_reader_, br_name.c_str());
    std::cout << kMsgPrefix << "TreeReaderValue: " << br_name << " created." << std::endl;
    return;
}

Bool_t eurica::WasabiDataTSScanner::IsInGate()
{
    return true;
}
