#ifndef __S2PLUS_TSSCANNER_H__
#define __S2PLUS_TSSCANNER_H__

#include "TSScannerBase.hpp"
#include "SH13S2PlusData.h"

class S2PlusTSScanner : public TSScannerBase<SH13S2PlusData>
{
public:
	const static std::string kMsgPrefix;
	S2PlusTSScanner() {}
	virtual ~S2PlusTSScanner() {}
	void SetReader();
	virtual Bool_t IsInGate();

protected:
	ULong64_t GetTS() const
	{
		if (!tree_data_)
			throw kMsgPrefix + "In GetTS(), tree_data_ is null";
		if (!tree_data_->Get())
			throw kMsgPrefix + "In GetTS(), tree_data_->Get() returned null";
		if (!tree_data_->Get()->GetSHTrig8008Ptr())
			throw kMsgPrefix + "In GetTS(), GetSHTrig8008Ptr() returned null";
		if (!tree_data_->Get()->GetSHTrig8008Ptr()->empty())
			throw kMsgPrefix + "In GetTS(), SHTrig8008 is empty";
		return tree_data_->Get()->GetSHTrig8008Ptr()->at(0);
	}
};
#endif /// __S2PLUS_TSSCANNER_H__