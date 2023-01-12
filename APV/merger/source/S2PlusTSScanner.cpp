#include "S2PlusTSScanner.h"

const std::string S2PlusTSScanner::kMsgPrefix("[S2PlusTSScanner]:");

void S2PlusTSScanner::SetReader()
{
	TSScannerBase<SH13S2PlusData>::SetReader();
	std::string br_name = yaml_reader_->GetString("BranchName");
	tree_data_ = new TTreeReaderValue<SH13S2PlusData>(*tree_reader_, br_name.c_str());
	std::cout << kMsgPrefix << "TTreeReaderValue: " << br_name << " created." << std::endl;
	return;
}

Bool_t S2PlusTSScanner::IsInGate()
{
	return true;
}