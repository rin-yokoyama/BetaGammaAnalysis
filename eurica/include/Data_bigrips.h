//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon May 13 14:43:42 2013 by ROOT version 5.34/03
// from TTree tree/bigrips tree
// found on file: run0080.root
//////////////////////////////////////////////////////////

#ifndef Eurica_Data_bigrips_h
#define Eurica_Data_bigrips_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <TClonesArray.h>
#include <TObject.h>
#include <TNamed.h>

#include "Data_eurica.h"

namespace eurica
{
   class Data_bigrips;
}
// Fixed size dimensions of array or collections stored in the TTree if any.
// const Int_t eurica::kMaxEventInfo = 1;

class eurica::Data_bigrips
{
public:
   TTree *fChain;  //! pointer to the analyzed TTree or TChain
   Int_t fCurrent; //! current Tree number in a TChain

   // Declaration of leaf types
   Int_t EventInfo_;
   UInt_t EventInfo_fUniqueID[eurica::kMaxEventInfo]; //[EventInfo_]
   UInt_t EventInfo_fBits[eurica::kMaxEventInfo];     //[EventInfo_]
   TString EventInfo_fName[eurica::kMaxEventInfo];
   TString EventInfo_fTitle[eurica::kMaxEventInfo];
   Int_t EventInfo_runnumber[eurica::kMaxEventInfo];   //[EventInfo_]
   Int_t EventInfo_eventnumber[eurica::kMaxEventInfo]; //[EventInfo_]
   TString EventInfo_subsysname[eurica::kMaxEventInfo];
   ULong64_t EventInfo_timestamp[eurica::kMaxEventInfo]; //[EventInfo_]
   Int_t EventInfo_comp_val[eurica::kMaxEventInfo];      //[EventInfo_]
   UInt_t EventInfo_fBit[eurica::kMaxEventInfo];         //[EventInfo_]
   Double_t F3X;
   Double_t F3A;
   Double_t F3Y;
   Double_t F3B;
   Double_t F3PLA_TL;
   Double_t F3PLA_TR;
   Double_t F3PLA_TM;
   Int_t F3PLA_QL;
   Int_t F3PLA_QR;
   Double_t F3PLA_QA;
   Double_t F3PLA_LQL;
   Double_t F3PLA_LQR;
   Double_t F3PLA_TD;
   Double_t F5X;
   Double_t F5A;
   Double_t F5Y;
   Double_t F5B;
   Double_t F5PPAC_TM;
   Double_t F7X;
   Double_t F7A;
   Double_t F7Y;
   Double_t F7B;
   Double_t F7PLA_TL;
   Double_t F7PLA_TR;
   Double_t F7PLA_TM;
   Int_t F7PLA_QL;
   Int_t F7PLA_QR;
   Double_t F7PLA_QA;
   Double_t F7PLA_LQL;
   Double_t F7PLA_LQR;
   Double_t F7PLA_TD;
   Int_t F7ICADC[6];
   Double_t F7ICSQSUM;
   Double_t F7ICAVSUM;
   Double_t F7ICE;
   Double_t F7ICADCR[5];
   Double_t F7ICPARA;
   Int_t F7GEADC[8];
   Int_t F7GETDC[8];
   Double_t F7GEENERGY[8];
   Double_t F7GETIMING[8];
   Double_t F11X;
   Double_t F11A;
   Double_t F11Y;
   Double_t F11B;
   Double_t F11PLA_TL;
   Double_t F11PLA_TR;
   Double_t F11PLA_TM;
   Int_t F11PLA_QL;
   Int_t F11PLA_QR;
   Double_t F11PLA_QA;
   Int_t F11ICADC[6];
   Double_t F11ICSQSUM;
   Double_t F11ICAVSUM;
   Double_t F11ICE;
   Double_t F11ICADCR[5];
   Double_t F11ICPARA;
   Int_t F11ICP;
   Double_t DELTA[2];
   Double_t ANGLE[2];
   Double_t DDELTA;
   Double_t BRHO[2];
   Double_t TOF[3];
   Double_t BETA[3];
   Double_t AOQ[3];
   Double_t ZET[2];
   Double_t RAOQ;

   // List of branches
   TBranch *b_EventInfo_;            //!
   TBranch *b_EventInfo_fUniqueID;   //!
   TBranch *b_EventInfo_fBits;       //!
   TBranch *b_EventInfo_fName;       //!
   TBranch *b_EventInfo_fTitle;      //!
   TBranch *b_EventInfo_runnumber;   //!
   TBranch *b_EventInfo_eventnumber; //!
   TBranch *b_EventInfo_subsysname;  //!
   TBranch *b_EventInfo_timestamp;   //!
   TBranch *b_EventInfo_comp_val;    //!
   TBranch *b_EventInfo_fBit;        //!
   TBranch *b_F3X;                   //!
   TBranch *b_F3A;                   //!
   TBranch *b_F3Y;                   //!
   TBranch *b_F3B;                   //!
   TBranch *b_F3PLA_TL;              //!
   TBranch *b_F3PLA_TR;              //!
   TBranch *b_F3PLA_TM;              //!
   TBranch *b_F3PLA_QL;              //!
   TBranch *b_F3PLA_QR;              //!
   TBranch *b_F3PLA_QA;              //!
   TBranch *b_F3PLA_LQL;             //!
   TBranch *b_F3PLA_LQR;             //!
   TBranch *b_F3PLA_TD;              //!
   TBranch *b_F5X;                   //!
   TBranch *b_F5A;                   //!
   TBranch *b_F5Y;                   //!
   TBranch *b_F5B;                   //!
   TBranch *b_F5PPAC_TM;             //!
   TBranch *b_F7X;                   //!
   TBranch *b_F7A;                   //!
   TBranch *b_F7Y;                   //!
   TBranch *b_F7B;                   //!
   TBranch *b_F7PLA_TL;              //!
   TBranch *b_F7PLA_TR;              //!
   TBranch *b_F7PLA_TM;              //!
   TBranch *b_F7PLA_QL;              //!
   TBranch *b_F7PLA_QR;              //!
   TBranch *b_F7PLA_QA;              //!
   TBranch *b_F7PLA_LQL;             //!
   TBranch *b_F7PLA_LQR;             //!
   TBranch *b_F7PLA_TD;              //!
   TBranch *b_F7ICADC;               //!
   TBranch *b_F7ICSQSUM;             //!
   TBranch *b_F7ICAVSUM;             //!
   TBranch *b_F7ICE;                 //!
   TBranch *b_F7ICADCR;              //!
   TBranch *b_F7ICPARA;              //!
   TBranch *b_F7GEADC;               //!
   TBranch *b_F7GETDC;               //!
   TBranch *b_F7GEENERGY;            //!
   TBranch *b_F7GETIMING;            //!
   TBranch *b_F11X;                  //!
   TBranch *b_F11A;                  //!
   TBranch *b_F11Y;                  //!
   TBranch *b_F11B;                  //!
   TBranch *b_F11PLA_TL;             //!
   TBranch *b_F11PLA_TR;             //!
   TBranch *b_F11PLA_TM;             //!
   TBranch *b_F11PLA_QL;             //!
   TBranch *b_F11PLA_QR;             //!
   TBranch *b_F11PLA_QA;             //!
   TBranch *b_F11ICADC;              //!
   TBranch *b_F11ICSQSUM;            //!
   TBranch *b_F11ICAVSUM;            //!
   TBranch *b_F11ICE;                //!
   TBranch *b_F11ICADCR;             //!
   TBranch *b_F11ICPARA;             //!
   TBranch *b_F11ICP;                //!
   TBranch *b_DELTA;                 //!
   TBranch *b_ANGLE;                 //!
   TBranch *b_DDELTA;                //!
   TBranch *b_BRHO;                  //!
   TBranch *b_TOF;                   //!
   TBranch *b_BETA;                  //!
   TBranch *b_AOQ;                   //!
   TBranch *b_ZET;                   //!
   TBranch *b_RAOQ;                  //!

   Data_bigrips(){};
   virtual ~Data_bigrips(){};
#ifdef Data_bigrips_cxx
   virtual void Read(char *filename);
   virtual void e_blanch();
   virtual Int_t Cut(Long64_t entry);
   virtual Int_t GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void Init();
   virtual void Loop();
   virtual Bool_t Notify();
   virtual void Show(Long64_t entry = -1);
#endif
};

#endif

#ifdef Data_bigrips_cxx
/*
Data_bigrips::Data_bigrips(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("run0080.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("run0080.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}
*/

void Data_bigrips::e_blanch()
{
   fChain->SetBranchStatus("*", 0);
   fChain->SetBranchStatus("EventInfo.timestamp");
   fChain->SetBranchStatus("EventInfo.runnumber");

   fChain->SetBranchStatus("DELTA");
   fChain->SetBranchStatus("BETA");
   fChain->SetBranchStatus("ZET");
   fChain->SetBranchStatus("AOQ");
}

void Data_bigrips::Read(char *filename)
{
   TFile *f = new TFile(filename);
   fChain = (TChain *)f->Get("tree");
   e_blanch();
   Init();
}

Data_bigrips::~Data_bigrips()
{
   if (!fChain)
      return;
   delete fChain->GetCurrentFile();
}

Int_t Data_bigrips::GetEntry(Long64_t entry)
{
   // Read contents of entry.
   if (!fChain)
      return 0;
   return fChain->GetEntry(entry);
}
Long64_t Data_bigrips::LoadTree(Long64_t entry)
{
   // Set the environment to read one entry
   if (!fChain)
      return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0)
      return centry;
   if (fChain->GetTreeNumber() != fCurrent)
   {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Data_bigrips::Init()
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("EventInfo", &EventInfo_, &b_EventInfo_);
   fChain->SetBranchAddress("EventInfo.fUniqueID", EventInfo_fUniqueID, &b_EventInfo_fUniqueID);
   fChain->SetBranchAddress("EventInfo.fBits", EventInfo_fBits, &b_EventInfo_fBits);
   fChain->SetBranchAddress("EventInfo.fName", EventInfo_fName, &b_EventInfo_fName);
   fChain->SetBranchAddress("EventInfo.fTitle", EventInfo_fTitle, &b_EventInfo_fTitle);
   fChain->SetBranchAddress("EventInfo.runnumber", EventInfo_runnumber, &b_EventInfo_runnumber);
   fChain->SetBranchAddress("EventInfo.eventnumber", EventInfo_eventnumber, &b_EventInfo_eventnumber);
   fChain->SetBranchAddress("EventInfo.subsysname", EventInfo_subsysname, &b_EventInfo_subsysname);
   fChain->SetBranchAddress("EventInfo.timestamp", EventInfo_timestamp, &b_EventInfo_timestamp);
   fChain->SetBranchAddress("EventInfo.comp_val", EventInfo_comp_val, &b_EventInfo_comp_val);
   fChain->SetBranchAddress("EventInfo.fBit", EventInfo_fBit, &b_EventInfo_fBit);
   fChain->SetBranchAddress("F3X", &F3X, &b_F3X);
   fChain->SetBranchAddress("F3A", &F3A, &b_F3A);
   fChain->SetBranchAddress("F3Y", &F3Y, &b_F3Y);
   fChain->SetBranchAddress("F3B", &F3B, &b_F3B);
   fChain->SetBranchAddress("F3PLA_TL", &F3PLA_TL, &b_F3PLA_TL);
   fChain->SetBranchAddress("F3PLA_TR", &F3PLA_TR, &b_F3PLA_TR);
   fChain->SetBranchAddress("F3PLA_TM", &F3PLA_TM, &b_F3PLA_TM);
   fChain->SetBranchAddress("F3PLA_QL", &F3PLA_QL, &b_F3PLA_QL);
   fChain->SetBranchAddress("F3PLA_QR", &F3PLA_QR, &b_F3PLA_QR);
   fChain->SetBranchAddress("F3PLA_QA", &F3PLA_QA, &b_F3PLA_QA);
   fChain->SetBranchAddress("F3PLA_LQL", &F3PLA_LQL, &b_F3PLA_LQL);
   fChain->SetBranchAddress("F3PLA_LQR", &F3PLA_LQR, &b_F3PLA_LQR);
   fChain->SetBranchAddress("F3PLA_TD", &F3PLA_TD, &b_F3PLA_TD);
   fChain->SetBranchAddress("F5X", &F5X, &b_F5X);
   fChain->SetBranchAddress("F5A", &F5A, &b_F5A);
   fChain->SetBranchAddress("F5Y", &F5Y, &b_F5Y);
   fChain->SetBranchAddress("F5B", &F5B, &b_F5B);
   fChain->SetBranchAddress("F5PPAC_TM", &F5PPAC_TM, &b_F5PPAC_TM);
   fChain->SetBranchAddress("F7X", &F7X, &b_F7X);
   fChain->SetBranchAddress("F7A", &F7A, &b_F7A);
   fChain->SetBranchAddress("F7Y", &F7Y, &b_F7Y);
   fChain->SetBranchAddress("F7B", &F7B, &b_F7B);
   fChain->SetBranchAddress("F7PLA_TL", &F7PLA_TL, &b_F7PLA_TL);
   fChain->SetBranchAddress("F7PLA_TR", &F7PLA_TR, &b_F7PLA_TR);
   fChain->SetBranchAddress("F7PLA_TM", &F7PLA_TM, &b_F7PLA_TM);
   fChain->SetBranchAddress("F7PLA_QL", &F7PLA_QL, &b_F7PLA_QL);
   fChain->SetBranchAddress("F7PLA_QR", &F7PLA_QR, &b_F7PLA_QR);
   fChain->SetBranchAddress("F7PLA_QA", &F7PLA_QA, &b_F7PLA_QA);
   fChain->SetBranchAddress("F7PLA_LQL", &F7PLA_LQL, &b_F7PLA_LQL);
   fChain->SetBranchAddress("F7PLA_LQR", &F7PLA_LQR, &b_F7PLA_LQR);
   fChain->SetBranchAddress("F7PLA_TD", &F7PLA_TD, &b_F7PLA_TD);
   fChain->SetBranchAddress("F7ICADC", F7ICADC, &b_F7ICADC);
   fChain->SetBranchAddress("F7ICSQSUM", &F7ICSQSUM, &b_F7ICSQSUM);
   fChain->SetBranchAddress("F7ICAVSUM", &F7ICAVSUM, &b_F7ICAVSUM);
   fChain->SetBranchAddress("F7ICE", &F7ICE, &b_F7ICE);
   fChain->SetBranchAddress("F7ICADCR", F7ICADCR, &b_F7ICADCR);
   fChain->SetBranchAddress("F7ICPARA", &F7ICPARA, &b_F7ICPARA);
   fChain->SetBranchAddress("F7GEADC", F7GEADC, &b_F7GEADC);
   fChain->SetBranchAddress("F7GETDC", F7GETDC, &b_F7GETDC);
   fChain->SetBranchAddress("F7GEENERGY", F7GEENERGY, &b_F7GEENERGY);
   fChain->SetBranchAddress("F7GETIMING", F7GETIMING, &b_F7GETIMING);
   fChain->SetBranchAddress("F11X", &F11X, &b_F11X);
   fChain->SetBranchAddress("F11A", &F11A, &b_F11A);
   fChain->SetBranchAddress("F11Y", &F11Y, &b_F11Y);
   fChain->SetBranchAddress("F11B", &F11B, &b_F11B);
   fChain->SetBranchAddress("F11PLA_TL", &F11PLA_TL, &b_F11PLA_TL);
   fChain->SetBranchAddress("F11PLA_TR", &F11PLA_TR, &b_F11PLA_TR);
   fChain->SetBranchAddress("F11PLA_TM", &F11PLA_TM, &b_F11PLA_TM);
   fChain->SetBranchAddress("F11PLA_QL", &F11PLA_QL, &b_F11PLA_QL);
   fChain->SetBranchAddress("F11PLA_QR", &F11PLA_QR, &b_F11PLA_QR);
   fChain->SetBranchAddress("F11PLA_QA", &F11PLA_QA, &b_F11PLA_QA);
   fChain->SetBranchAddress("F11ICADC", F11ICADC, &b_F11ICADC);
   fChain->SetBranchAddress("F11ICSQSUM", &F11ICSQSUM, &b_F11ICSQSUM);
   fChain->SetBranchAddress("F11ICAVSUM", &F11ICAVSUM, &b_F11ICAVSUM);
   fChain->SetBranchAddress("F11ICE", &F11ICE, &b_F11ICE);
   fChain->SetBranchAddress("F11ICADCR", F11ICADCR, &b_F11ICADCR);
   fChain->SetBranchAddress("F11ICPARA", &F11ICPARA, &b_F11ICPARA);
   fChain->SetBranchAddress("F11ICP", &F11ICP, &b_F11ICP);
   fChain->SetBranchAddress("DELTA", DELTA, &b_DELTA);
   fChain->SetBranchAddress("ANGLE", ANGLE, &b_ANGLE);
   fChain->SetBranchAddress("DDELTA", &DDELTA, &b_DDELTA);
   fChain->SetBranchAddress("BRHO", BRHO, &b_BRHO);
   fChain->SetBranchAddress("TOF", TOF, &b_TOF);
   fChain->SetBranchAddress("BETA", BETA, &b_BETA);
   fChain->SetBranchAddress("AOQ", AOQ, &b_AOQ);
   fChain->SetBranchAddress("ZET", ZET, &b_ZET);
   fChain->SetBranchAddress("RAOQ", &RAOQ, &b_RAOQ);
   Notify();
}

Bool_t Data_bigrips::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Data_bigrips::Show(Long64_t entry)
{
   // Print contents of entry.
   // If entry is not specified, print current entry
   if (!fChain)
      return;
   fChain->Show(entry);
}
Int_t Data_bigrips::Cut(Long64_t entry)
{
   // This function may be called from Loop.
   // returns  1 if entry is accepted.
   // returns -1 otherwise.
   return 1;
}
#endif // #ifdef Data_bigrips_cxx
