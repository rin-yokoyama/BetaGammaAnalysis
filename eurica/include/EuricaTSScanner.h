#ifndef __EURICA_TSSCANNER_H__
#define __EURICA_TSSCANNER_H__

#include "TSScannerBase.hpp"
#include "EuricaMergerData.hpp"

namespace eurica
{
	class EuricaTSScanner;
}

class eurica::EuricaTSScanner : public TSScannerBase<eurica::ClusterData>
{
public:
	const static std::string kMsgPrefix;
	EuricaTSScanner() {}
	virtual ~EuricaTSScanner() {}
	void SetReader();
	virtual Bool_t IsInGate();

protected:
	ULong64_t GetTS() const
	{
		if (!tree_data_)
			throw kMsgPrefix + "In GetTS(), tree_data_ is null";
		if (!tree_data_->Get())
			throw kMsgPrefix + "In GetTS(), tree_data_->Get() returned null";
		return tree_data_->Get()->ts_;
	}
};
#endif /// __EURICA_TSSCANNER_H__