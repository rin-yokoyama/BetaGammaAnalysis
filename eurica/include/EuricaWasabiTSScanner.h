#ifndef __EURICA_WASABI_TSSCANNER_H__
#define __EURICA_WASABI_TSSCANNER_H__

#include "TSScannerBase.hpp"
#include "Data_wasabi.h"

namespace eurica
{
	class WasabiTSScanner;
}

class eurica::WasabiTSScanner : public TSScannerBase<eurica::Data_wasabi>
{
public:
	const static std::string kMsgPrefix;
	WasabiTSScanner() {}
	virtual ~WasabiTSScanner() {}
	void SetReader();
	virtual Bool_t IsInGate();

protected:
	ULong64_t GetTS() const
	{
		return true;
	}
};
#endif /// __EURICA_WASABI_TSSCANNER_H__