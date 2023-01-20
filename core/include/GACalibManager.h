#ifndef GACALIBMANAGER_H
#define GACALIBMANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <new>
#include "GACalibrator.h"
using namespace std;

class GACalibManager
{
protected:
    Int_t n_hist;
    Int_t n_par;
    GACalibrator **fGACalibrator;
    void ReadFile(string fname);

public:
    GACalibManager(string fname, Int_t nhist);
    ~GACalibManager(void);
    Double_t GCalib(Int_t hn, Double_t ch);
};

#endif