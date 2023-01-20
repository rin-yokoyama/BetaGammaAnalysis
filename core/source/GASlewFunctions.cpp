#include "GASlewFunctions.h"

GASlewFunctions::GASlewFunctions(string fname, Int_t fnum)
{
    f_num = fnum;
    f_name = fname;
    range[0] = 0;
    range[1] = 10000;
}

GASlewFunctions::~GASlewFunctions(void) {}

void GASlewFunctions::SetRange(Double_t xlow, Double_t xup)
{
    range[0] = xlow;
    range[1] = xup;
}

TF1 *GASlewFunctions::CalibFunc(SlewFuncType func_type)
{
    TF1 *fTF1;
    ostringstream oss;
    oss.str("");
    oss << f_name << f_num;
    if (func_type == kSqrt)
        fTF1 = new TF1(oss.str().c_str(), "[0]+[1]/sqrt(x-[3])+[2]/(x-[3])", range[0], range[1]);
    if (func_type == kArbD)
        fTF1 = new TF1(oss.str().c_str(), "[0]+[1]/(x-[3])^[2]", range[0], range[1]);
    if (func_type == kStep)
    {
        fTF1 = new TF1(oss.str().c_str(), "([0]+[1]/(x-[5]))*0.5*(TMath::Erfc((x-[4])/[7])+1.0) + ([2]+[3]/(x-[6]))*0.5*(TMath::Erf((x-[4])/[7])+1.0)", range[0], range[1]);
        fTF1->SetParameters(-29400, 1000, -29400, 1000, 150, 10, -100);
    }
    if (func_type == kRtQd)
        fTF1 = new TF1(oss.str().c_str(), "[0]+[2]/(x-[1])^0.5+[3]/(x-[1])+[4]/(x-[1])^2", range[0], range[1]);
    return (TF1 *)fTF1->Clone();
}