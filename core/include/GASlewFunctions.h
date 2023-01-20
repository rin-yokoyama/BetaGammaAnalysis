#ifndef GASLEWFUNCTIONS_H
#define GASLEWFUNCTIONS_H

#include <iostream>
#include <string>
#include <sstream>
#include <TF1.h>
using namespace std;

enum SlewFuncType
{
    kSqrt = 1,
    kArbD = 2,
    kStep = 3,
    kRtQd = 4
};

class GASlewFunctions
{
protected:
    Int_t f_num;
    string f_name;
    Double_t range[2];

public:
    GASlewFunctions(string fname = "GSlew", Int_t fnum = 0);
    ~GASlewFunctions(void);
    void SetRange(Double_t xlow, Double_t xup);
    TF1 *CalibFunc(SlewFuncType func_type);
};

#endif