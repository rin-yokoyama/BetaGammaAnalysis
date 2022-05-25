#include <iostream>
#include "APV8104Decoder.h"

APVSingleData *APV8104Decoder::DecodeAnEvent(char *buff)
{
	ULong64_t tdc = ((ULong64_t)buff[1]) << 40;
	tdc += ((ULong64_t)buff[2]) << 32;
	tdc += ((ULong64_t)buff[3]) << 24;
	tdc += ((ULong64_t)buff[4]) << 16;
	tdc += ((ULong64_t)buff[5]) << 8;
	tdc += buff[6];
	Int_t high_tdc = buff[0];
	Int_t tdcfp = buff[7];
	Int_t qdc = (buff[8] & 0x1f) << 8;
	qdc += buff[9];
	Int_t ch = (buff[8] & 0xe0) >> 5;

	Double_t charge = (Double_t)qdc;
	Double_t timing = tdc_bin2ns_ * ((Double_t)tdc + (Double_t)tdcfp / (Double_t)kTDCFPBins);

	return new APVSingleData(run_number_, event_id_, ch, timing, charge, high_tdc);
}

void APV8104Decoder::SetAPVModuleType(std::string name)
{
	if (bin2ns_map_.count(name) == 0)
	{
		std::cout << "[APV8104Decoder]: invalid key name " << name << ". Default type APV8104 is used." << std::endl;
		return;
	}
	tdc_bin2ns_ = (Double_t)bin2ns_map_[name];
}
