#include <iostream>
#include "APV8104Decoder.h"

APVSingleData *APV8104Decoder::DecodeAnEvent(char *buff)
{
	ULong64_t tdc0 = (unsigned char)buff[0];
	ULong64_t tdc1 = (unsigned char)buff[1];
	ULong64_t tdc2 = (unsigned char)buff[2];
	ULong64_t tdc3 = (unsigned char)buff[3];
	ULong64_t tdc4 = (unsigned char)buff[4];
	ULong64_t tdc5 = (unsigned char)buff[5];
	ULong64_t tdc6 = (unsigned char)buff[6];
	ULong64_t tdc = tdc0 << 48;
	tdc += tdc1 << 40;
	tdc += tdc2 << 32;
	tdc += tdc3 << 24;
	tdc += tdc4 << 16;
	tdc += tdc5 << 8;
	tdc += tdc6;
	UInt_t high_tdc = (UInt_t)buff[0];
	UInt_t tdcfp = (UInt_t)buff[7];
	UInt_t qdc = (((uint16_t)((unsigned char)buff[8] & 0x1f)) << 8) & 0xff00;
	qdc += (unsigned char)buff[9];
	Int_t ch = ((unsigned char)buff[8] & 0xe0) >> 5;

	if (ch > 7)
	{
		return new APVSingleData();
	}
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
