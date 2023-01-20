#include "GACalibManager.h"

GACalibManager::GACalibManager(string fname, Int_t nhist)
{
    try
    {
        n_hist = nhist;
        ReadFile(fname);
    }
    catch (bad_alloc)
    {
        cout << "[GACalibManager-E]: bad_alloc." << endl;
        throw 1;
    }
}

GACalibManager::~GACalibManager(void) {}

void GACalibManager::ReadFile(string fname)
{
    try
    {
        ifstream fin(fname.c_str(), ios::in);
        if (!fin)
        {
            cout << "[GACalibManager-E]: cannot open parameter file: " << fname << endl;
            throw 1;
        }
        Int_t f_type;
        istringstream iss;
        string line;
        getline(fin, line);
        iss.str(line);
        iss >> f_type;
        Double_t xmin, xmax;
        getline(fin, line);
        iss.str(line);
        iss >> xmin;
        iss >> xmax;
        GACalibFunctions *fGACalibFunction = new GACalibFunctions();
        fGACalibrator = new GACalibrator *[n_hist];
        TF1 *Func = fGACalibFunction->CalibFunc((CalFuncType)f_type);
        n_par = Func->GetNpar();
        Double_t **par;
        par = new Double_t *[n_hist];
        getline(fin, line);
        for (int i = 0; i < n_hist; i++)
        {
            par[i] = new Double_t[n_par];
            for (int j = 0; j < n_par; j++)
                fin >> par[i][j];
            fGACalibrator[i] = new GACalibrator((CalFuncType)f_type, par[i], i);
            fGACalibrator[i]->SetRange(xmin, xmax);
        }
    }
    catch (bad_alloc)
    {
        cout << "[GACalibManager-E]: Exception bad_alloc." << endl;
        throw 1;
    }
}

Double_t GACalibManager::GCalib(Int_t hn, Double_t ch)
{
    return fGACalibrator[hn]->GCalib(ch);
}