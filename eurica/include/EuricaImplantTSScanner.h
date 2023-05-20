#ifndef __EURICA_Implant_TSSCANNER_H__
#define __EURICA_Implant_TSSCANNER_H__

#include "TSScannerBase.hpp"
#include "EuricaMergerData.hpp"

namespace eurica
{
	class ImplantTSScanner;
}

class eurica::ImplantTSScanner : public TSScannerBase<eurica::ImplantData>
{
public:
	const static std::string kMsgPrefix;
	ImplantTSScanner() {}
	virtual ~ImplantTSScanner() {}
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
#endif /// __EURICA_Implant_TSSCANNER_H__