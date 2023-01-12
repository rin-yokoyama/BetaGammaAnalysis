//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed May  1 16:25:42 2013 by ROOT version 5.34/03
// from TTree WASABI/data
// found on file: treefile/sistopper/WASABI1020.root
//////////////////////////////////////////////////////////

#ifndef Data_wasabi_h
#define Data_wasabi_h

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
   class Data_wasabi;
}
// Fixed size dimensions of array or collections stored in the TTree if any.
// const Int_t eurica::kMaxEventInfo = 1;

class eurica::Data_wasabi
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
   Int_t IF_BETA;
   Int_t IF_ION;
   Int_t numdssd;
   Int_t numadc;
   Int_t numtdc;
   Int_t dstrx;
   Int_t dstry;
   Int_t scal[32];
   Int_t dssd_E_X[5][60];    //[numdssd]
   Int_t dssd_ch_X[5][60];   //[numdssd]
   Int_t dssd_id_X[5][60];   //[numdssd]
   Int_t dssd_E_Y[5][40];    //[numdssd]
   Int_t dssd_ch_Y[5][40];   //[numdssd]
   Int_t dssd_id_Y[5][40];   //[numdssd]
   Int_t dssd_T_X[5][60][3]; //[numdssd]
   Int_t dssd_T_Y[5][40][3]; //[numdssd]
   Int_t dssd_X[5];          //[numdssd]
   Int_t dssd_Y[5];          //[numdssd]
   Int_t dssd_Z;
   Int_t ADC[18][32];       //[numadc]
   Int_t TDC[5][128][3];    //[numtdc]
   Int_t DSSD_E[5][100];    //[numdssd]
   Int_t DSSD_T[5][100][3]; //[numdssd]
   Int_t bigrips_F7PPAC1X1;
   Int_t bigrips_F7PPAC1X2;
   Int_t bigrips_F7PPAC2X1;
   Int_t bigrips_F7PPAC2X2;
   Int_t bigrips_F5PPAC1X1;
   Int_t bigrips_F5PPAC1X2;
   Int_t bigrips_F5PPAC2X1;
   Int_t bigrips_F5PPAC2X2;
   Int_t bigrips_F3L;
   Int_t bigrips_F3R;
   Int_t bigrips_F7L;
   Int_t bigrips_F7R;
   Int_t bigrips_F11L;
   Int_t bigrips_F11R;
   Int_t bigrips_IC1e;
   Int_t bigrips_IC2e;
   Int_t bigrips_IC3e;
   Int_t bigrips_IC4e;
   Int_t bigrips_IC5e;
   Int_t bigrips_IC6e;
   Int_t vetoPL_front;
   Int_t vetoPL_back;
   Int_t betaPL1L;
   Int_t betaPL1R;
   Int_t betaPL2L;
   Int_t betaPL2R;
   Double_t bigrips_F7PPAC1_TDiffX;
   Double_t bigrips_F7PPAC2_TDiffX;
   Double_t bigrips_F5PPAC1_TDiffX;
   Double_t bigrips_F5PPAC2_TDiffX;
   Double_t bigrips_F7PPAC1_X;
   Double_t bigrips_F7PPAC2_X;
   Double_t bigrips_F5PPAC1_X;
   Double_t bigrips_F5PPAC2_X;
   Double_t bigrips_F7_X;
   Double_t bigrips_F7_A;
   Double_t bigrips_F5_X;
   Double_t bigrips_F5_A;
   Double_t bigrips_dERaw;
   Double_t bigrips_dE;
   Double_t pid_Delta_F5F7;
   Double_t pid_TOF_F3F7;
   Double_t pid_Beta_F3F5;
   Double_t pid_Beta_F5F7;
   Double_t pid_AoQ_F5F7;
   Double_t pid_Zet_F11;

   // List of branches
   TBranch *b_EventInfo_;             //!
   TBranch *b_EventInfo_fUniqueID;    //!
   TBranch *b_EventInfo_fBits;        //!
   TBranch *b_EventInfo_fName;        //!
   TBranch *b_EventInfo_fTitle;       //!
   TBranch *b_EventInfo_runnumber;    //!
   TBranch *b_EventInfo_eventnumber;  //!
   TBranch *b_EventInfo_subsysname;   //!
   TBranch *b_EventInfo_timestamp;    //!
   TBranch *b_EventInfo_comp_val;     //!
   TBranch *b_EventInfo_fBit;         //!
   TBranch *b_IF_BETA;                //!
   TBranch *b_IF_ION;                 //!
   TBranch *b_numdssd;                //!
   TBranch *b_numadc;                 //!
   TBranch *b_numtdc;                 //!
   TBranch *b_dstrx;                  //!
   TBranch *b_dstry;                  //!
   TBranch *b_scal;                   //!
   TBranch *b_dssd_E_X;               //!
   TBranch *b_dssd_ch_X;              //!
   TBranch *b_dssd_id_X;              //!
   TBranch *b_dssd_E_Y;               //!
   TBranch *b_dssd_ch_Y;              //!
   TBranch *b_dssd_id_Y;              //!
   TBranch *b_dssd_T_X;               //!
   TBranch *b_dssd_T_Y;               //!
   TBranch *b_dssd_X;                 //!
   TBranch *b_dssd_Y;                 //!
   TBranch *b_dssd_Z;                 //!
   TBranch *b_ADC;                    //!
   TBranch *b_TDC;                    //!
   TBranch *b_DSSD_E;                 //!
   TBranch *b_DSSD_T;                 //!
   TBranch *b_bigrips_F7PPAC1X1;      //!
   TBranch *b_bigrips_F7PPAC1X2;      //!
   TBranch *b_bigrips_F7PPAC2X1;      //!
   TBranch *b_bigrips_F7PPAC2X2;      //!
   TBranch *b_bigrips_F5PPAC1X1;      //!
   TBranch *b_bigrips_F5PPAC1X2;      //!
   TBranch *b_bigrips_F5PPAC2X1;      //!
   TBranch *b_bigrips_F5PPAC2X2;      //!
   TBranch *b_bigrips_F3L;            //!
   TBranch *b_bigrips_F3R;            //!
   TBranch *b_bigrips_F7L;            //!
   TBranch *b_bigrips_F7R;            //!
   TBranch *b_bigrips_F11L;           //!
   TBranch *b_bigrips_F11R;           //!
   TBranch *b_bigrips_IC1e;           //!
   TBranch *b_bigrips_IC2e;           //!
   TBranch *b_bigrips_IC3e;           //!
   TBranch *b_bigrips_IC4e;           //!
   TBranch *b_bigrips_IC5e;           //!
   TBranch *b_bigrips_IC6e;           //!
   TBranch *b_vetoPL_front;           //!
   TBranch *b_vetoPL_back;            //!
   TBranch *b_betaPL1L;               //!
   TBranch *b_betaPL1R;               //!
   TBranch *b_betaPL2L;               //!
   TBranch *b_betaPL2R;               //!
   TBranch *b_bigrips_F7PPAC1_TDiffX; //!
   TBranch *b_bigrips_F7PPAC2_TDiffX; //!
   TBranch *b_bigrips_F5PPAC1_TDiffX; //!
   TBranch *b_bigrips_F5PPAC2_TDiffX; //!
   TBranch *b_bigrips_F7PPAC1_X;      //!
   TBranch *b_bigrips_F7PPAC2_X;      //!
   TBranch *b_bigrips_F5PPAC1_X;      //!
   TBranch *b_bigrips_F5PPAC2_X;      //!
   TBranch *b_bigrips_F7_X;           //!
   TBranch *b_bigrips_F7_A;           //!
   TBranch *b_bigrips_F5_X;           //!
   TBranch *b_bigrips_F5_A;           //!
   TBranch *b_bigrips_dERaw;          //!
   TBranch *b_bigrips_dE;             //!
   TBranch *b_pid_Delta_F5F7;         //!
   TBranch *b_pid_TOF_F3F7;           //!
   TBranch *b_pid_Beta_F3F5;          //!
   TBranch *b_pid_Beta_F5F7;          //!
   TBranch *b_pid_AoQ_F5F7;           //!
   TBranch *b_pid_Zet_F11;            //!

   virtual ~Data_wasabi();
   virtual void Read(char *filename);
   virtual void e_blanch();
   virtual Int_t Cut(Long64_t entry);
   virtual Int_t GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void Init();
   virtual void Loop();
   virtual Bool_t Notify();
   virtual void Show(Long64_t entry = -1);
};

#endif

#ifdef Data_wasabi_cxx
/*
Data_wasabi::Data_wasabi(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("treefile/sistopper/WASABI1020.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("treefile/sistopper/WASABI1020.root");
      }
      f->GetObject("WASABI",tree);

   }
   Init(tree);
}
*/

void Data_wasabi ::e_blanch()
{
   fChain->SetBranchStatus("*", 0);
   fChain->SetBranchStatus("EventInfo.timestamp");
   fChain->SetBranchStatus("dssd_E_X");
   fChain->SetBranchStatus("dssd_T_X");
   fChain->SetBranchStatus("dssd_E_Y");
   fChain->SetBranchStatus("dssd_T_Y");
   fChain->SetBranchStatus("bigrips_F7L");
   fChain->SetBranchStatus("bigrips_F7R");
   fChain->SetBranchStatus("bigrips_F11L");
   fChain->SetBranchStatus("bigrips_F11R");
   fChain->SetBranchStatus("pid_AoQ_F5F7");
   fChain->SetBranchStatus("pid_Zet_F11");
}

void Data_wasabi::Read(char *filename)
{
   TFile *f = new TFile(filename);
   fChain = (TChain *)f->Get("WASABI");
   e_blanch();
   Init();
}

Data_wasabi::~Data_wasabi()
{
   if (!fChain)
      return;
   delete fChain->GetCurrentFile();
}

Int_t Data_wasabi::GetEntry(Long64_t entry)
{
   // Read contents of entry.
   if (!fChain)
      return 0;
   return fChain->GetEntry(entry);
}
Long64_t Data_wasabi::LoadTree(Long64_t entry)
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

void Data_wasabi::Init()
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
   fChain->SetBranchAddress("IF_BETA", &IF_BETA, &b_IF_BETA);
   fChain->SetBranchAddress("IF_ION", &IF_ION, &b_IF_ION);
   fChain->SetBranchAddress("numdssd", &numdssd, &b_numdssd);
   fChain->SetBranchAddress("numadc", &numadc, &b_numadc);
   fChain->SetBranchAddress("numtdc", &numtdc, &b_numtdc);
   fChain->SetBranchAddress("dstrx", &dstrx, &b_dstrx);
   fChain->SetBranchAddress("dstry", &dstry, &b_dstry);
   fChain->SetBranchAddress("scal", scal, &b_scal);
   fChain->SetBranchAddress("dssd_E_X", dssd_E_X, &b_dssd_E_X);
   fChain->SetBranchAddress("dssd_ch_X", dssd_ch_X, &b_dssd_ch_X);
   fChain->SetBranchAddress("dssd_id_X", dssd_id_X, &b_dssd_id_X);
   fChain->SetBranchAddress("dssd_E_Y", dssd_E_Y, &b_dssd_E_Y);
   fChain->SetBranchAddress("dssd_ch_Y", dssd_ch_Y, &b_dssd_ch_Y);
   fChain->SetBranchAddress("dssd_id_Y", dssd_id_Y, &b_dssd_id_Y);
   fChain->SetBranchAddress("dssd_T_X", dssd_T_X, &b_dssd_T_X);
   fChain->SetBranchAddress("dssd_T_Y", dssd_T_Y, &b_dssd_T_Y);
   fChain->SetBranchAddress("dssd_X", dssd_X, &b_dssd_X);
   fChain->SetBranchAddress("dssd_Y", dssd_Y, &b_dssd_Y);
   fChain->SetBranchAddress("dssd_Z", &dssd_Z, &b_dssd_Z);
   fChain->SetBranchAddress("ADC", ADC, &b_ADC);
   fChain->SetBranchAddress("TDC", TDC, &b_TDC);
   fChain->SetBranchAddress("DSSD_E", DSSD_E, &b_DSSD_E);
   fChain->SetBranchAddress("DSSD_T", DSSD_T, &b_DSSD_T);
   fChain->SetBranchAddress("bigrips_F7PPAC1X1", &bigrips_F7PPAC1X1, &b_bigrips_F7PPAC1X1);
   fChain->SetBranchAddress("bigrips_F7PPAC1X2", &bigrips_F7PPAC1X2, &b_bigrips_F7PPAC1X2);
   fChain->SetBranchAddress("bigrips_F7PPAC2X1", &bigrips_F7PPAC2X1, &b_bigrips_F7PPAC2X1);
   fChain->SetBranchAddress("bigrips_F7PPAC2X2", &bigrips_F7PPAC2X2, &b_bigrips_F7PPAC2X2);
   fChain->SetBranchAddress("bigrips_F5PPAC1X1", &bigrips_F5PPAC1X1, &b_bigrips_F5PPAC1X1);
   fChain->SetBranchAddress("bigrips_F5PPAC1X2", &bigrips_F5PPAC1X2, &b_bigrips_F5PPAC1X2);
   fChain->SetBranchAddress("bigrips_F5PPAC2X1", &bigrips_F5PPAC2X1, &b_bigrips_F5PPAC2X1);
   fChain->SetBranchAddress("bigrips_F5PPAC2X2", &bigrips_F5PPAC2X2, &b_bigrips_F5PPAC2X2);
   fChain->SetBranchAddress("bigrips_F3L", &bigrips_F3L, &b_bigrips_F3L);
   fChain->SetBranchAddress("bigrips_F3R", &bigrips_F3R, &b_bigrips_F3R);
   fChain->SetBranchAddress("bigrips_F7L", &bigrips_F7L, &b_bigrips_F7L);
   fChain->SetBranchAddress("bigrips_F7R", &bigrips_F7R, &b_bigrips_F7R);
   fChain->SetBranchAddress("bigrips_F11L", &bigrips_F11L, &b_bigrips_F11L);
   fChain->SetBranchAddress("bigrips_F11R", &bigrips_F11R, &b_bigrips_F11R);
   fChain->SetBranchAddress("bigrips_IC1e", &bigrips_IC1e, &b_bigrips_IC1e);
   fChain->SetBranchAddress("bigrips_IC2e", &bigrips_IC2e, &b_bigrips_IC2e);
   fChain->SetBranchAddress("bigrips_IC3e", &bigrips_IC3e, &b_bigrips_IC3e);
   fChain->SetBranchAddress("bigrips_IC4e", &bigrips_IC4e, &b_bigrips_IC4e);
   fChain->SetBranchAddress("bigrips_IC5e", &bigrips_IC5e, &b_bigrips_IC5e);
   fChain->SetBranchAddress("bigrips_IC6e", &bigrips_IC6e, &b_bigrips_IC6e);
   fChain->SetBranchAddress("vetoPL_front", &vetoPL_front, &b_vetoPL_front);
   fChain->SetBranchAddress("vetoPL_back", &vetoPL_back, &b_vetoPL_back);
   fChain->SetBranchAddress("betaPL1L", &betaPL1L, &b_betaPL1L);
   fChain->SetBranchAddress("betaPL1R", &betaPL1R, &b_betaPL1R);
   fChain->SetBranchAddress("betaPL2L", &betaPL2L, &b_betaPL2L);
   fChain->SetBranchAddress("betaPL2R", &betaPL2R, &b_betaPL2R);
   fChain->SetBranchAddress("bigrips_F7PPAC1_TDiffX", &bigrips_F7PPAC1_TDiffX, &b_bigrips_F7PPAC1_TDiffX);
   fChain->SetBranchAddress("bigrips_F7PPAC2_TDiffX", &bigrips_F7PPAC2_TDiffX, &b_bigrips_F7PPAC2_TDiffX);
   fChain->SetBranchAddress("bigrips_F5PPAC1_TDiffX", &bigrips_F5PPAC1_TDiffX, &b_bigrips_F5PPAC1_TDiffX);
   fChain->SetBranchAddress("bigrips_F5PPAC2_TDiffX", &bigrips_F5PPAC2_TDiffX, &b_bigrips_F5PPAC2_TDiffX);
   fChain->SetBranchAddress("bigrips_F7PPAC1_X", &bigrips_F7PPAC1_X, &b_bigrips_F7PPAC1_X);
   fChain->SetBranchAddress("bigrips_F7PPAC2_X", &bigrips_F7PPAC2_X, &b_bigrips_F7PPAC2_X);
   fChain->SetBranchAddress("bigrips_F5PPAC1_X", &bigrips_F5PPAC1_X, &b_bigrips_F5PPAC1_X);
   fChain->SetBranchAddress("bigrips_F5PPAC2_X", &bigrips_F5PPAC2_X, &b_bigrips_F5PPAC2_X);
   fChain->SetBranchAddress("bigrips_F7_X", &bigrips_F7_X, &b_bigrips_F7_X);
   fChain->SetBranchAddress("bigrips_F7_A", &bigrips_F7_A, &b_bigrips_F7_A);
   fChain->SetBranchAddress("bigrips_F5_X", &bigrips_F5_X, &b_bigrips_F5_X);
   fChain->SetBranchAddress("bigrips_F5_A", &bigrips_F5_A, &b_bigrips_F5_A);
   fChain->SetBranchAddress("bigrips_dERaw", &bigrips_dERaw, &b_bigrips_dERaw);
   fChain->SetBranchAddress("bigrips_dE", &bigrips_dE, &b_bigrips_dE);
   fChain->SetBranchAddress("pid_Delta_F5F7", &pid_Delta_F5F7, &b_pid_Delta_F5F7);
   fChain->SetBranchAddress("pid_TOF_F3F7", &pid_TOF_F3F7, &b_pid_TOF_F3F7);
   fChain->SetBranchAddress("pid_Beta_F3F5", &pid_Beta_F3F5, &b_pid_Beta_F3F5);
   fChain->SetBranchAddress("pid_Beta_F5F7", &pid_Beta_F5F7, &b_pid_Beta_F5F7);
   fChain->SetBranchAddress("pid_AoQ_F5F7", &pid_AoQ_F5F7, &b_pid_AoQ_F5F7);
   fChain->SetBranchAddress("pid_Zet_F11", &pid_Zet_F11, &b_pid_Zet_F11);
   Notify();
}

Bool_t Data_wasabi::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Data_wasabi::Show(Long64_t entry)
{
   // Print contents of entry.
   // If entry is not specified, print current entry
   if (!fChain)
      return;
   fChain->Show(entry);
}
Int_t Data_wasabi::Cut(Long64_t entry)
{
   // This function may be called from Loop.
   // returns  1 if entry is accepted.
   // returns -1 otherwise.
   return 1;
}
#endif // #ifdef Data_wasabi_cxx
