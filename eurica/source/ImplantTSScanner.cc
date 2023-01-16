#include "EuricaImplantTSScanner.h"

const std::string eurica::ImplantTSScanner::kMsgPrefix("[ImplantTSScanner]:");

void eurica::ImplantTSScanner::SetReader()
{
    TSScannerBase<eurica::MergedData>::SetReader();
    std::string br_name = yaml_reader_->GetString("BranchName");
    tree_data_ = new TTreeReaderValue<eurica::MergedData>(*tree_reader_, br_name.c_str());
    std::cout << kMsgPrefix << "TreeReaderValue: " << br_name << " created." << std::endl;
    return;
}

Bool_t eurica::ImplantTSScanner::IsInGate()
{
    return true;
}
