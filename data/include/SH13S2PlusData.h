#ifndef __SH13_S2_PLUS_DATA__
#define __SH13_S2_PLUS_DATA__

#include <vector>
#include <TObject.h>
#include "APVSingleData.h"
#include "TAPV8008Data.h"

class SH13S2PlusData : public TObject
{
public:
    SH13S2PlusData() {}
    virtual ~SH13S2PlusData() {}

    SH13S2PlusData(const SH13S2PlusData &obj) : ge(obj.GetGe()), stopper(obj.GetStopper()), cebr(obj.GetCeBr()), shtrig(obj.GetSHTrig())
    {
    }

    void Clear()
    {
        ge.clear();
        stopper.clear();
        cebr.clear();
        shtrig.clear();
    }

    std::vector<art::TAPV8008Data *> GetGe() const { return ge; }
    std::vector<APVSingleData *> GetStopper() const { return stopper; }
    std::vector<APVSingleData *> GetCeBr() const { return cebr; }
    std::vector<APVSingleData *> GetSHTrig() const { return shtrig; }

protected:
    std::vector<art::TAPV8008Data *> ge;
    std::vector<APVSingleData *> stopper;
    std::vector<APVSingleData *> cebr;
    std::vector<APVSingleData *> shtrig;

    ClassDef(SH13S2PlusData, 1)
};

#endif /// __SH13_S2_PLUS_DATA__
