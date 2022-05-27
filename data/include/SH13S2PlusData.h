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

    SH13S2PlusData(const SH13S2PlusData &obj) : ge(obj.GetGe()), stopper(obj.GetStopper()), cebr(obj.GetCeBr())
    {
    }

    void Clear()
    {
        ge.clear();
        stopper.clear();
        cebr.clear();
        shtrig_8008.clear();
        shtrig_8104.clear();
        shtrig_8508.clear();
    }

    const std::vector<art::TAPV8008Data> &GetGe() const { return ge; }
    const std::vector<APVSingleData> &GetStopper() const { return stopper; }
    const std::vector<APVSingleData> &GetCeBr() const { return cebr; }
    const std::vector<Double_t> &GetSHTrig8008() const { return shtrig_8008; }
    const std::vector<Double_t> &GetSHTrig8104() const { return shtrig_8104; }
    const std::vector<Double_t> &GetSHTrig8508() const { return shtrig_8508; }

    std::vector<art::TAPV8008Data> *GetGePtr() { return &ge; }
    std::vector<APVSingleData> *GetStopperPtr() { return &stopper; }
    std::vector<APVSingleData> *GetCeBrPtr() { return &cebr; }
    std::vector<Double_t> *GetSHTrig8008Ptr() { return &shtrig_8008; }
    std::vector<Double_t> *GetSHTrig8104Ptr() { return &shtrig_8104; }
    std::vector<Double_t> *GetSHTrig8508Ptr() { return &shtrig_8508; }

protected:
    std::vector<art::TAPV8008Data> ge;
    std::vector<APVSingleData> stopper;
    std::vector<APVSingleData> cebr;
    std::vector<Double_t> shtrig_8008;
    std::vector<Double_t> shtrig_8104;
    std::vector<Double_t> shtrig_8508;

    ClassDef(SH13S2PlusData, 1)
};

#endif /// __SH13_S2_PLUS_DATA__
