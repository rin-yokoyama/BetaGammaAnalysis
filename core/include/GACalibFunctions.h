#ifndef GACALIBFUNCTIONS_H
#define GACALIBFUNCTIONS_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <TF1.h>
using namespace std;

enum CalFuncType
{
    kLine = 1,
    kPol2 = 2,
    kPol3 = 3,
    kPol4 = 4,
    kPol5 = 5,
    k2Line = 51,
    kHyperbolic = 52
};

Double_t TwoLine(Double_t *x, Double_t *par);

class GACalibFunctions
{

protected:
    Int_t f_num;
    string f_name;
    Double_t range[2];
    Double_t fDivisionPoint;

public:
    GACalibFunctions(string fname = "GCalib", Int_t fnum = 0);
    ~GACalibFunctions(void);
    void SetRange(Double_t xlow, Double_t xup);
    TF1 *CalibFunc(CalFuncType func_type);
    Double_t CalcResidualError(Double_t ch, Double_t che, Double_t RefEe, Double_t *par, Double_t *parE, CalFuncType func_type);
    void SetInitialParam(TF1 *fTF1, Double_t gain, Double_t offset, CalFuncType func_type);
    void SetDivisionPoint(Double_t div_p) { fDivisionPoint = div_p; }
};

#endif