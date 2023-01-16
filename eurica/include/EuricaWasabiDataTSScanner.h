#ifndef __EURICA_WASABI_DATA_TSSCANNER_H__
#define __EURICA_WASABI_DATA_TSSCANNER_H__

#include "TSScannerBase.hpp"
#include "EuricaMergerData.hpp"

namespace eurica
{
	class WasabiDataTSScanner;
}

class eurica::WasabiDataTSScanner : public TSScannerBase<eurica::WasabiData>
{
public:
	const static std::string kMsgPrefix;
	WasabiDataTSScanner() {}
	virtual ~WasabiDataTSScanner() {}
	void SetReader();
	virtual Bool_t IsInGate();

protected:
	ULong64_t GetTS() const
	{
		return true;
	}
};
#endif /// __EURICA_WASABI_DATA_TSSCANNER_H__