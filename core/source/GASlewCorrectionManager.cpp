#include "GASlewCorrectionManager.h"

GASlewCorrectionManager::GASlewCorrectionManager(void)
{
}

GASlewCorrectionManager::GASlewCorrectionManager(string fname, Int_t nhist)
{
    n_hist = nhist;
    ReadFile(fname);
}

GASlewCorrectionManager::~GASlewCorrectionManager(void)
{
}

void GASlewCorrectionManager::ReadFile(string fname)
{
    try
    {
        ifstream fin(fname.c_str(), ios::in);
        if (!fin)
        {
            cout << "[GASlewCorrectionManager-E]: cannot open parameter file: " << fname << endl;
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
        GASlewFunctions *fGASlewFunction = new GASlewFunctions();
        fTF1 = new TF1 *[n_hist];
        TF1 *Func = fGASlewFunction->CalibFunc((SlewFuncType)f_type);
        n_par = Func->GetNpar();
        Double_t **par;
        par = new Double_t *[n_hist];
        getline(fin, line);
        for (int i = 0; i < n_hist; i++)
        {
            par[i] = new Double_t[n_par];
            for (int j = 0; j < n_par; j++)
            {
                fin >> par[i][j];
            }
            fTF1[i] = (TF1 *)Func->Clone();
            fTF1[i]->SetParameters(par[i]);
        }
    }
    catch (bad_alloc)
    {
        cout << "[GCalibManager-E]: Exception bad_alloc." << endl;
        throw 1;
    }
}

Double_t GASlewCorrectionManager::SlewCorrect(Int_t hn, Double_t raw_t, Double_t raw_e)
{
    return raw_t - fTF1[hn]->Eval(raw_e);
}