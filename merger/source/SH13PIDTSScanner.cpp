#include "SH13PIDTSScanner.h"

const std::string SH13PIDTSScanner::kMsgPrefix("[SH13PIDTSScanner]:");

void SH13PIDTSScanner::SetReader()
{
	TSScannerBase<ULong64_t>::SetReader();
	std::string br_name = yaml_reader_->GetString("BranchName");
	tree_data_ = new TTreeReaderValue<ULong64_t>(*tree_reader_, br_name.c_str());
	std::cout << kMsgPrefix << "TTreeReaderValue: " << br_name << " created." << std::endl;
	return;
}

Bool_t SH13PIDTSScanner::IsInGate()
{
	return true;
}