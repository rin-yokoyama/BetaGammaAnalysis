#ifndef __SH13PID_TSSCANNER_H__
#define __SH13PID_TSSCANNER_H__

#include "TSScannerBase.hpp"
#include "TMergerData.h"

class SH13PIDTSScanner : public TSScannerBase<art::TMergerData>
{
public:
	const static std::string kMsgPrefix;
	SH13PIDTSScanner() {}
	virtual ~SH13PIDTSScanner() {}
	void SetReader();
	virtual Bool_t IsInGate();

protected:
	ULong64_t GetTS() const
	{
		if (!tree_data_)
			throw kMsgPrefix + "In GetTS(), tree_data_ is null";
		if (!tree_data_->Get())
			throw kMsgPrefix + "In GetTS(), tree_data_->Get() returned null";
		return tree_data_->Get()->GetULongTimestamp();
	}
};
#endif /// __SH13PID_TSSCANNER_H__