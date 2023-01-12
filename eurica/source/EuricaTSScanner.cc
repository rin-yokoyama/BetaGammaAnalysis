#include "EuricaTSScanner.h"

const std::string eurica::EuricaTSScanner::kMsgPrefix("[EuricaTSScanner]:");

void eurica::EuricaTSScanner::SetReader()
{
    TSScannerBase<eurica::Data_eurica>::SetReader();
    std::string br_name = yaml_reader_->GetString("BranchName");
    tree_data_ = new TTreeReaderValue<eurica::Data_eurica>(*tree_reader_, br_name.c_str());
    std::cout << kMsgPrefix << "TreeReaderValue: " << br_name << " created." << std::endl;
    return;
}

Bool_t eurica::EuricaTSScanner::IsInGate()
{
    return true;
}
