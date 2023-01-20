#include "GACalibrator.h"

GACalibrator::GACalibrator(CalFuncType func_type, Double_t *parameter, Int_t num)
{
    f_type = func_type;
    fGCalibFunction = new GACalibFunctions("GCalib", num);
    fTF1 = fGCalibFunction->CalibFunc(f_type);
    npar = fTF1->GetNpar();
    par = new Double_t[npar];
    for (int i = 0; i < npar; i++)
    {
        par[i] = parameter[i];
    }
    fTF1->SetParameters(par);
    rnd = new TRandom();
}

GACalibrator::~GACalibrator(void)
{
}

Double_t GACalibrator::GCalib(Double_t ch)
{
    fGCalibFunction->SetRange(xmin, xmax);
    Double_t val = ch + rnd->Uniform(-0.5, 0.5);
    val = fTF1->Eval(val);
    return val;
}

void GACalibrator::SetRange(Double_t x_min, Double_t x_max)
{
    xmin = x_min;
    xmax = x_max;
}