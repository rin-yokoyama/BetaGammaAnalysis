#ifndef GASLEWCORRECTIONMANAGER_H
#define GASLEWCORRECTIONMANAGER_H

#include <iostream>
#include <fstream>
#include <new>
#include <TF1.h>
#include "GASlewFunctions.h"
using namespace std;

class GASlewCorrectionManager
{
protected:
    Int_t n_hist;
    Int_t n_par;
    TF1 **fTF1;
    void ReadFile(string fname);

public:
    GASlewCorrectionManager(void);
    GASlewCorrectionManager(string fname, Int_t nhist);
    ~GASlewCorrectionManager(void);
    Double_t SlewCorrect(Int_t hn, Double_t raw_t, Double_t raw_e);
};

#endif