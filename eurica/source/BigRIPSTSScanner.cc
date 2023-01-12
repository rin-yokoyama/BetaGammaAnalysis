#include "EuricaBigRIPSTSScanner.h"

const std::string eurica::BigRIPSTSScanner::kMsgPrefix("[EuricaBigRIPSTSScanner]:");

void eurica::BigRIPSTSScanner::SetReader()
{
    TSScannerBase<eurica::Data_bigrips>::SetReader();
    std::string br_name = yaml_reader_->GetString("BranchName");
    tree_data_ = new TTreeReaderValue<eurica::Data_bigrips>(*tree_reader_, br_name.c_str());
    std::cout << kMsgPrefix << "TreeReaderValue: " << br_name << " created." << std::endl;
    return;
}

Bool_t eurica::BigRIPSTSScanner::IsInGate()
{
    return true;
}
