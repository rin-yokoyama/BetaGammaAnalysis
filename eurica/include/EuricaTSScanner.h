#ifndef __EURICA_TSSCANNER_H__
#define __EURICA_TSSCANNER_H__

#include "TSScannerBase.hpp"
#include "Data_eurica.h"

namespace eurica
{
	class EuricaTSScanner;
}

class eurica::EuricaTSScanner : public TSScannerBase<eurica::Data_eurica>
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
		return true;
	}
};
#endif /// __EURICA_TSSCANNER_H__