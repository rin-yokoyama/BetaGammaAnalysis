#ifndef GACALIBRATOR_H
#define GACALIBRATOR_H

#include "GACalibFunctions.h"
#include <TRandom.h>
#include <TH1.h>

class GACalibrator
{
protected:
    enum CalFuncType f_type;
    GACalibFunctions *fGCalibFunction;
    Int_t npar;
    Double_t *par;
    Double_t xmin, xmax;
    TF1 *fTF1;
    TRandom *rnd;

public:
    GACalibrator(CalFuncType func_type, Double_t *parameter, Int_t num = 0);
    virtual ~GACalibrator(void);
    Double_t GCalib(Double_t ch);
    inline Int_t GetNpar(void) { return npar; }
    void SetRange(Double_t x_min, Double_t x_max);
};

#endif