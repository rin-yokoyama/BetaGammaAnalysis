#ifndef __EURICA_BETA_TSSCANNER_H__
#define __EURICA_BETA_TSSCANNER_H__

#include "TSScannerBase.hpp"
#include "EuricaMergerData.hpp"

namespace eurica
{
	class BetaTSScanner;
}

class eurica::BetaTSScanner : public TSScannerBase<eurica::MergedData>
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
		return true;
	}
};
#endif /// __EURICA_BETA_TSSCANNER_H__