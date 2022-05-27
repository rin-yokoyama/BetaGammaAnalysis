#include "SH13PIDTSScanner.h"

const std::string SH13PIDTSScanner::kMsgPrefix("[SH13PIDTSScanner]:");

void SH13PIDTSScanner::SetReader()
{
	TSScannerBase<art::TMergerData>::SetReader();
	std::string br_name = yaml_reader_->GetString("BranchName");
	tree_data_ = new TTreeReaderValue<art::TMergerData>(*tree_reader_, br_name.c_str());
	std::cout << kMsgPrefix << "TTreeReaderValue: " << br_name << " created." << std::endl;
	return;
}

Bool_t SH13PIDTSScanner::IsInGate()
{
	return true;
}