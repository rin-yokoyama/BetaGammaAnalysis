#ifndef __EURICA_Implant_TSSCANNER_H__
#define __EURICA_Implant_TSSCANNER_H__

#include "TSScannerBase.hpp"
#include "EuricaMergerData.hpp"

namespace eurica
{
	class ImplantTSScanner;
}

class eurica::ImplantTSScanner : public TSScannerBase<eurica::MergedData>
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
		return true;
	}
};
#endif /// __EURICA_Implant_TSSCANNER_H__