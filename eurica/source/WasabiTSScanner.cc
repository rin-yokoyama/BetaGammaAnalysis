#include "EuricaWasabiTSScanner.h"

const std::string eurica::WasabiTSScanner::kMsgPrefix("[EuricaWasabiTSScanner]:");

void eurica::WasabiTSScanner::SetReader()
{
    TSScannerBase<eurica::Data_wasabi>::SetReader();
    std::string br_name = yaml_reader_->GetString("BranchName");
    tree_data_ = new TTreeReaderValue<eurica::Data_wasabi>(*tree_reader_, br_name.c_str());
    std::cout << kMsgPrefix << "TreeReaderValue: " << br_name << " created." << std::endl;
    return;
}

Bool_t eurica::WasabiTSScanner::IsInGate()
{
    return true;
}
