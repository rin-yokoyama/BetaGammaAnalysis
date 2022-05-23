#include <iostream>
#include "APV8104Decoder.h"

APVSingleData *APV8104Decoder::DecodeAnEvent(char *buff)
{
	uint16_t word0 = *(uint16_t *)buff;
	uint16_t word1 = *(uint16_t *)(buff + 2);
	uint16_t word2 = *(uint16_t *)(buff + 4);
	uint16_t word3 = *(uint16_t *)(buff + 6);
	uint16_t word4 = *(uint16_t *)(buff + 8);
	ULong64_t tdc = 0;
	tdc += ((ULong64_t)word0 << 40) & 0x00ffff0000000000;
	tdc += ((ULong64_t)word1 << 24) & 0x000000ffff000000;
	tdc += ((ULong64_t)word2 << 8) & 0x0000000000ffff00;
	tdc += ((ULong64_t)word3 >> 8) & 0x00000000000000ff;
	Int_t tdcfp = 0;
	tdcfp += word3 & 0x000000ff;
	Int_t ch = 0;
	ch += (word4 >> 13) & 0x00000007;
	Int_t qdc = 0;
	qdc += word4 & 0x00001fff;

	Double_t charge = (Double_t)qdc;
	Double_t timing = tdc_bin2ns_ * ((Double_t)tdc + (Double_t)tdcfp / (Double_t)kTDCFPBins);

	return new APVSingleData(run_number_, event_id_, ch, timing, charge);
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
