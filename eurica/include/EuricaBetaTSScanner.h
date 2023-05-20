#ifndef __EURICA_BETA_TSSCANNER_H__
#define __EURICA_BETA_TSSCANNER_H__

#include "TSScannerBase.hpp"
#include "EuricaMergerData.hpp"

namespace eurica
{
	class BetaTSScanner;
}

class eurica::BetaTSScanner : public TSScannerBase<eurica::ImplantData>
{
public:
	const static std::string kMsgPrefix;
	BetaTSScanner() {}
	virtual ~BetaTSScanner() {}
	void SetReader();
	virtual Bool_t IsInGate();

protected:
	ULong64_t GetTS() const
	{
		if (!tree_data_)
			throw kMsgPrefix + "In GetTS(), tree_data_ is null";
		if (!tree_data_->Get())
			throw kMsgPrefix + "In GetTS(), tree_data_->Get() returned null";
		return tree_data_->Get()->input_.input_.ts_;
	}
};
#endif /// __EURICA_BETA_TSSCANNER_H__