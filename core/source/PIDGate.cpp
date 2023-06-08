#include "PIDGate.h"
#include "TMath.h"

PIDGate::PIDGate(TCutG *aCut, TList *outputList) : numberOfImplants(0),
                                                   numberOfPID(0),
                                                   isotopeName("")
{
    myCutG = nullptr;
    isotopeName = "";
    ellipseA = 0;
    ellipseB = 0;
    ellipseX0 = 0;
    ellipseY0 = 0;

    initializeCut(aCut);
    initializeHistos(outputList);
}

PIDGate::PIDGate(std::string isoname, Double_t a, Double_t b, Double_t x0, Double_t y0, TList *outputList) : numberOfImplants(0),
                                                                                                             numberOfPID(0),
                                                                                                             isotopeName("")
{
    myCutG = nullptr;
    isotopeName = isoname;
    ellipseA = a;
    ellipseB = b;
    ellipseX0 = x0;
    ellipseY0 = y0;

    initializeHistos(outputList);
}

PIDGate::~PIDGate()
{
}

void PIDGate::initializeCut(TCutG *aCut)
{
    std::string tempName4Cut(aCut->GetName());
    tempName4Cut = "i" + tempName4Cut;
    myCutG = (TCutG *)(aCut->Clone(tempName4Cut.c_str()));
    return;
}

void PIDGate::initializeHistos(TList *outputList)
{
    if (myCutG)
    {
        // get the name of the isotope
        // it must be at the end
        std::string tempName4Cut(myCutG->GetName());
        size_t lastindex = tempName4Cut.find_last_of("CUTG");
        if (lastindex == size_t(-1))
            lastindex = tempName4Cut.find_last_of("cutg");
        // the name of TCutG could be "blablaCUTG82ga"
        // and the name of the isotope will be "82ga"
        std::cout << lastindex << " " << (tempName4Cut.substr(3 + 1, tempName4Cut.size())).c_str() << std::endl;
        isotopeName = tempName4Cut.substr(4 + 1, tempName4Cut.size());
    }

    if (outputList)
    {
        fHistArray = new TObjArray();
        TIter next(fHistArray);
        while (TObject *obj = next())
        {
            outputList->Add(obj);
        }
    }

    return;
}

bool PIDGate::IsInside(Double_t x, Double_t y) const
{
    if (myCutG)
    {
        return myCutG->IsInside(x, y);
    }
    else
    {
        return (ellipseA * TMath::Power(x - ellipseX0, 2) + ellipseB * TMath::Power(y - ellipseY0, 2) < 1);
    }
}

const std::vector<PIDGate> PIDGate::LoadCut(std::string icutname, TList *outputList)
{
    std::vector<PIDGate> vectorIsotopes;

    auto file_open_error = [&icutname, &vectorIsotopes]()
    {
        std::cerr << "[PIDGate]: File " << icutname.c_str() << " not found.\n";
        return vectorIsotopes;
    };

    if (icutname.find(".root") == std::string::npos)
    {
        std::ifstream fcut(icutname);
        if (!fcut)
        {
            file_open_error();
        }
        while (!fcut.eof())
        {
            std::string isoname;
            fcut >> isoname;
            Double_t ellipse_a, ellipse_b, ellipse_x0, ellipse_y0, radius;
            fcut >> ellipse_x0;
            fcut >> ellipse_y0;
            fcut >> radius;
            fcut >> ellipse_a;
            fcut >> ellipse_b;
            vectorIsotopes.push_back(PIDGate(isoname, ellipse_a / radius, ellipse_b / radius, ellipse_x0, ellipse_y0, outputList));
        }
        fcut.close();
    }
    else
    {
        TFile *const fcut = new TFile(icutname.c_str());

        if (!fcut)
        {
            file_open_error();
        }
        TKey *key = 0;
        TIter keyNext(fcut->GetListOfKeys());
        TCutG *temp = nullptr;
        while ((key = (TKey *)keyNext()))
        {
            std::string tempName(key->GetName());

            if (tempName.find("CUTG") != std::string::npos || tempName.find("cutg") != std::string::npos)
            {
                fcut->GetObject(key->GetName(), temp);

                vectorIsotopes.push_back(PIDGate(temp, outputList));
            }
        }
        fcut->Close();
        delete fcut;
    }
    return vectorIsotopes;
}