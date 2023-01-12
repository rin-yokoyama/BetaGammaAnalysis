#ifndef __EURICA_BIGRIPS_TSSCANNER_H__
#define __EURICA_BIGRIPS_TSSCANNER_H__

#include "TSScannerBase.hpp"
#include "Data_bigrips.h"

namespace eurica
{
	class BigRIPSTSScanner;
}

class eurica::BigRIPSTSScanner : public TSScannerBase<eurica::Data_bigrips>
{
public:
	const static std::string kMsgPrefix;
	BigRIPSTSScanner() {}
	virtual ~BigRIPSTSScanner() {}
	void SetReader();
	virtual Bool_t IsInGate();

protected:
	ULong64_t GetTS() const
	{
		return true;
	}
};
#endif /// __EURICA_BIGRIPS_TSSCANNER_H__