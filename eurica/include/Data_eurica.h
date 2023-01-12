//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed May  1 15:52:47 2013 by ROOT version 5.34/03
// from TTree tree/go4 tree
// found on file: treefile/euroball/go4_1006.root
//////////////////////////////////////////////////////////

#ifndef Eurica_Data_eurica_h
#define Eurica_Data_eurica_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <TClonesArray.h>
#include <TObject.h>
#include <TNamed.h>

namespace eurica
{
   class Data_eurica;
   // Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxUnpackEvent = 1;
   const Int_t kMaxGeCluster = 49;
   const Int_t kMaxGeAddback = 23;
   const Int_t kMaxLaBr = 17;
   const Int_t kMaxBetaPlasticUp = 1;
   const Int_t kMaxBetaPlasticDown = 1;
   const Int_t kMaxEventInfo = 1;
   const Int_t kMaxBigRIPSRaw = 10;

}

class eurica::Data_eurica
{
public:
   TTree *fChain;  //! pointer to the analyzed TTree or TChain
   Int_t fCurrent; //! current Tree number in a TChain

   // Declaration of leaf types
   Int_t UnpackEvent_;
   UInt_t UnpackEvent_fUniqueID[eurica::kMaxUnpackEvent]; //[UnpackEvent_]
   UInt_t UnpackEvent_fBits[eurica::kMaxUnpackEvent];     //[UnpackEvent_]
   TString UnpackEvent_fName[eurica::kMaxUnpackEvent];
   TString UnpackEvent_fTitle[eurica::kMaxUnpackEvent];
   Bool_t UnpackEvent_fbIsValid[eurica::kMaxUnpackEvent];         //[UnpackEvent_]
   Short_t UnpackEvent_fIdentifier[eurica::kMaxUnpackEvent];      //[UnpackEvent_]
   Int_t UnpackEvent_detBP[eurica::kMaxUnpackEvent][16];          //[UnpackEvent_]
   Int_t UnpackEvent_detHP[eurica::kMaxUnpackEvent];              //[UnpackEvent_]
   Int_t UnpackEvent_vme1_1[eurica::kMaxUnpackEvent][32];         //[UnpackEvent_]
   Int_t UnpackEvent_vme1_2[eurica::kMaxUnpackEvent][32];         //[UnpackEvent_]
   Int_t UnpackEvent_nhit1[eurica::kMaxUnpackEvent][128];         //[UnpackEvent_]
   Int_t UnpackEvent_vme1s[eurica::kMaxUnpackEvent][128][10];     //[UnpackEvent_]
   Int_t UnpackEvent_vme4_5[eurica::kMaxUnpackEvent][30][4][2];   //[UnpackEvent_]
   Int_t UnpackEvent_vme6[eurica::kMaxUnpackEvent][4][32];        //[UnpackEvent_]
   Int_t UnpackEvent_vmel[eurica::kMaxUnpackEvent][128][3];       //[UnpackEvent_]
   Int_t UnpackEvent_nhitl[eurica::kMaxUnpackEvent][128];         //[UnpackEvent_]
   Int_t UnpackEvent_hp[eurica::kMaxUnpackEvent][4];              //[UnpackEvent_]
   Int_t UnpackEvent_vme20[eurica::kMaxUnpackEvent][21][64];      //[UnpackEvent_]
   Int_t UnpackEvent_vmehit[eurica::kMaxUnpackEvent][21][64][10]; //[UnpackEvent_]
   Int_t UnpackEvent_nhit[eurica::kMaxUnpackEvent][21][64];       //[UnpackEvent_]
   Int_t UnpackEvent_lenUSR[eurica::kMaxUnpackEvent];             //[UnpackEvent_]
   Int_t UnpackEvent_lenDGF[eurica::kMaxUnpackEvent];             //[UnpackEvent_]
   Int_t UnpackEvent_lenGeTDC[eurica::kMaxUnpackEvent];           //[UnpackEvent_]
   UInt_t UnpackEvent_lupotslo[eurica::kMaxUnpackEvent];          //[UnpackEvent_]
   UInt_t UnpackEvent_lupotshi[eurica::kMaxUnpackEvent];          //[UnpackEvent_]
   Int_t UnpackEvent_qlength[eurica::kMaxUnpackEvent];            //[UnpackEvent_]
   Int_t UnpackEvent_qtype[eurica::kMaxUnpackEvent];              //[UnpackEvent_]
   Int_t UnpackEvent_qsubtype[eurica::kMaxUnpackEvent];           //[UnpackEvent_]
   Int_t UnpackEvent_qdummy[eurica::kMaxUnpackEvent];             //[UnpackEvent_]
   Int_t UnpackEvent_qtrigger[eurica::kMaxUnpackEvent];           //[UnpackEvent_]
   Int_t UnpackEvent_qevent_nr[eurica::kMaxUnpackEvent];          //[UnpackEvent_]
   Int_t UnpackEvent_Time_sec[eurica::kMaxUnpackEvent];           //[UnpackEvent_]
   Int_t UnpackEvent_Time_msec[eurica::kMaxUnpackEvent];          //[UnpackEvent_]
   Float_t UnpackEvent_rTime[eurica::kMaxUnpackEvent];            //[UnpackEvent_]
   Int_t GeCluster_;
   UInt_t GeCluster_fUniqueID[eurica::kMaxGeCluster]; //[GeCluster_]
   UInt_t GeCluster_fBits[eurica::kMaxGeCluster];     //[GeCluster_]
   Int_t GeCluster_id[eurica::kMaxGeCluster];         //[GeCluster_]
   Int_t GeCluster_fpl[eurica::kMaxGeCluster];        //[GeCluster_]
   TString GeCluster_name[eurica::kMaxGeCluster];
   Int_t GeCluster_fDataState[eurica::kMaxGeCluster]; //[GeCluster_]
   Int_t GeCluster_channel[eurica::kMaxGeCluster];    //[GeCluster_]
   Int_t GeCluster_fADCe[eurica::kMaxGeCluster];      //[GeCluster_]
   Int_t GeCluster_fADCt[eurica::kMaxGeCluster];      //[GeCluster_]
   Int_t GeCluster_fTDCs[eurica::kMaxGeCluster];      //[GeCluster_]
   Int_t GeCluster_fTDCl[eurica::kMaxGeCluster];      //[GeCluster_]
   Double_t GeCluster_fEnergy[eurica::kMaxGeCluster]; //[GeCluster_]
   Double_t GeCluster_fTime[eurica::kMaxGeCluster];   //[GeCluster_]
   Int_t GeAddback_;
   UInt_t GeAddback_fUniqueID[eurica::kMaxGeAddback]; //[GeAddback_]
   UInt_t GeAddback_fBits[eurica::kMaxGeAddback];     //[GeAddback_]
   Int_t GeAddback_id[eurica::kMaxGeAddback];         //[GeAddback_]
   Int_t GeAddback_fpl[eurica::kMaxGeAddback];        //[GeAddback_]
   TString GeAddback_name[eurica::kMaxGeAddback];
   Int_t GeAddback_fDataState[eurica::kMaxGeAddback]; //[GeAddback_]
   Int_t GeAddback_channel[eurica::kMaxGeAddback];    //[GeAddback_]
   Int_t GeAddback_fADCe[eurica::kMaxGeAddback];      //[GeAddback_]
   Int_t GeAddback_fADCt[eurica::kMaxGeAddback];      //[GeAddback_]
   Int_t GeAddback_fTDCs[eurica::kMaxGeAddback];      //[GeAddback_]
   Int_t GeAddback_fTDCl[eurica::kMaxGeAddback];      //[GeAddback_]
   Double_t GeAddback_fEnergy[eurica::kMaxGeAddback]; //[GeAddback_]
   Double_t GeAddback_fTime[eurica::kMaxGeAddback];   //[GeAddback_]
   Int_t LaBr_;
   UInt_t LaBr_fUniqueID[eurica::kMaxLaBr]; //[LaBr_]
   UInt_t LaBr_fBits[eurica::kMaxLaBr];     //[LaBr_]
   Int_t LaBr_id[eurica::kMaxLaBr];         //[LaBr_]
   Int_t LaBr_fpl[eurica::kMaxLaBr];        //[LaBr_]
   TString LaBr_name[eurica::kMaxLaBr];
   Int_t LaBr_fDataState[eurica::kMaxLaBr];   //[LaBr_]
   Int_t LaBr_channel[eurica::kMaxLaBr];      //[LaBr_]
   Int_t LaBr_fADC[eurica::kMaxLaBr];         //[LaBr_]
   Int_t LaBr_fTDC_srt[eurica::kMaxLaBr];     //[LaBr_]
   Int_t LaBr_fTDC_lrt[eurica::kMaxLaBr];     //[LaBr_]
   Double_t LaBr_fEnergy[eurica::kMaxLaBr];   //[LaBr_]
   Double_t LaBr_fTime_srt[eurica::kMaxLaBr]; //[LaBr_]
   Double_t LaBr_fTime_lrt[eurica::kMaxLaBr]; //[LaBr_]
   Int_t BetaPlasticUp_;
   UInt_t BetaPlasticUp_fUniqueID[eurica::kMaxBetaPlasticUp]; //[BetaPlasticUp_]
   UInt_t BetaPlasticUp_fBits[eurica::kMaxBetaPlasticUp];     //[BetaPlasticUp_]
   Int_t BetaPlasticUp_id[eurica::kMaxBetaPlasticUp];         //[BetaPlasticUp_]
   Int_t BetaPlasticUp_fpl[eurica::kMaxBetaPlasticUp];        //[BetaPlasticUp_]
   TString BetaPlasticUp_name[eurica::kMaxBetaPlasticUp];
   Int_t BetaPlasticUp_fDataState[eurica::kMaxBetaPlasticUp];    //[BetaPlasticUp_]
   Int_t BetaPlasticUp_ADC_L_Beta[eurica::kMaxBetaPlasticUp];    //[BetaPlasticUp_]
   Int_t BetaPlasticUp_ADC_R_Beta[eurica::kMaxBetaPlasticUp];    //[BetaPlasticUp_]
   Int_t BetaPlasticUp_ADC_L_Beam[eurica::kMaxBetaPlasticUp];    //[BetaPlasticUp_]
   Int_t BetaPlasticUp_ADC_R_Beam[eurica::kMaxBetaPlasticUp];    //[BetaPlasticUp_]
   Int_t BetaPlasticUp_TDC_L_lrt[eurica::kMaxBetaPlasticUp];     //[BetaPlasticUp_]
   Int_t BetaPlasticUp_TDC_R_lrt[eurica::kMaxBetaPlasticUp];     //[BetaPlasticUp_]
   Int_t BetaPlasticUp_TDC_L_srt[eurica::kMaxBetaPlasticUp];     //[BetaPlasticUp_]
   Int_t BetaPlasticUp_TDC_R_srt[eurica::kMaxBetaPlasticUp];     //[BetaPlasticUp_]
   Double_t BetaPlasticUp_Time_L_srt[eurica::kMaxBetaPlasticUp]; //[BetaPlasticUp_]
   Double_t BetaPlasticUp_Time_R_srt[eurica::kMaxBetaPlasticUp]; //[BetaPlasticUp_]
   Double_t BetaPlasticUp_Time_L_lrt[eurica::kMaxBetaPlasticUp]; //[BetaPlasticUp_]
   Double_t BetaPlasticUp_Time_R_lrt[eurica::kMaxBetaPlasticUp]; //[BetaPlasticUp_]
   Int_t BetaPlasticDown_;
   UInt_t BetaPlasticDown_fUniqueID[eurica::kMaxBetaPlasticDown]; //[BetaPlasticDown_]
   UInt_t BetaPlasticDown_fBits[eurica::kMaxBetaPlasticDown];     //[BetaPlasticDown_]
   Int_t BetaPlasticDown_id[eurica::kMaxBetaPlasticDown];         //[BetaPlasticDown_]
   Int_t BetaPlasticDown_fpl[eurica::kMaxBetaPlasticDown];        //[BetaPlasticDown_]
   TString BetaPlasticDown_name[eurica::kMaxBetaPlasticDown];
   Int_t BetaPlasticDown_fDataState[eurica::kMaxBetaPlasticDown];    //[BetaPlasticDown_]
   Int_t BetaPlasticDown_ADC_L_Beta[eurica::kMaxBetaPlasticDown];    //[BetaPlasticDown_]
   Int_t BetaPlasticDown_ADC_R_Beta[eurica::kMaxBetaPlasticDown];    //[BetaPlasticDown_]
   Int_t BetaPlasticDown_ADC_L_Beam[eurica::kMaxBetaPlasticDown];    //[BetaPlasticDown_]
   Int_t BetaPlasticDown_ADC_R_Beam[eurica::kMaxBetaPlasticDown];    //[BetaPlasticDown_]
   Int_t BetaPlasticDown_TDC_L_lrt[eurica::kMaxBetaPlasticDown];     //[BetaPlasticDown_]
   Int_t BetaPlasticDown_TDC_R_lrt[eurica::kMaxBetaPlasticDown];     //[BetaPlasticDown_]
   Int_t BetaPlasticDown_TDC_L_srt[eurica::kMaxBetaPlasticDown];     //[BetaPlasticDown_]
   Int_t BetaPlasticDown_TDC_R_srt[eurica::kMaxBetaPlasticDown];     //[BetaPlasticDown_]
   Double_t BetaPlasticDown_Time_L_srt[eurica::kMaxBetaPlasticDown]; //[BetaPlasticDown_]
   Double_t BetaPlasticDown_Time_R_srt[eurica::kMaxBetaPlasticDown]; //[BetaPlasticDown_]
   Double_t BetaPlasticDown_Time_L_lrt[eurica::kMaxBetaPlasticDown]; //[BetaPlasticDown_]
   Double_t BetaPlasticDown_Time_R_lrt[eurica::kMaxBetaPlasticDown]; //[BetaPlasticDown_]
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
   Int_t BigRIPSRaw_;
   UInt_t BigRIPSRaw_fUniqueID[eurica::kMaxBigRIPSRaw]; //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_fBits[eurica::kMaxBigRIPSRaw];     //[BigRIPSRaw_]
   TString BigRIPSRaw_fName[eurica::kMaxBigRIPSRaw];
   TString BigRIPSRaw_fTitle[eurica::kMaxBigRIPSRaw];
   UInt_t BigRIPSRaw_F3PPAC1_X1[eurica::kMaxBigRIPSRaw];      //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F3PPAC1_X2[eurica::kMaxBigRIPSRaw];      //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F3PPAC2_X1[eurica::kMaxBigRIPSRaw];      //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F3PPAC2_X2[eurica::kMaxBigRIPSRaw];      //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F5PPAC1_X1[eurica::kMaxBigRIPSRaw];      //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F5PPAC1_X2[eurica::kMaxBigRIPSRaw];      //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F5PPAC2_X1[eurica::kMaxBigRIPSRaw];      //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F5PPAC2_X2[eurica::kMaxBigRIPSRaw];      //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F3SCI_L[eurica::kMaxBigRIPSRaw];         //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F3SCI_R[eurica::kMaxBigRIPSRaw];         //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F7SCI_L[eurica::kMaxBigRIPSRaw];         //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F7SCI_R[eurica::kMaxBigRIPSRaw];         //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F11PPAC1_X1[eurica::kMaxBigRIPSRaw];     //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F11PPAC1_Y1[eurica::kMaxBigRIPSRaw];     //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F11PPAC1_X2[eurica::kMaxBigRIPSRaw];     //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F11PPAC1_Y2[eurica::kMaxBigRIPSRaw];     //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F11PPAC2_X1[eurica::kMaxBigRIPSRaw];     //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F11PPAC2_Y1[eurica::kMaxBigRIPSRaw];     //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F11PPAC2_X2[eurica::kMaxBigRIPSRaw];     //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F11PPAC2_Y2[eurica::kMaxBigRIPSRaw];     //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F11SCI_L[eurica::kMaxBigRIPSRaw];        //[BigRIPSRaw_]
   UInt_t BigRIPSRaw_F11SCI_R[eurica::kMaxBigRIPSRaw];        //[BigRIPSRaw_]
   Float_t BigRIPSRaw_DE[eurica::kMaxBigRIPSRaw];             //[BigRIPSRaw_]
   Float_t BigRIPSRaw_F3PPAC1_TDiffX[eurica::kMaxBigRIPSRaw]; //[BigRIPSRaw_]
   Float_t BigRIPSRaw_F3PPAC2_TDiffX[eurica::kMaxBigRIPSRaw]; //[BigRIPSRaw_]
   Float_t BigRIPSRaw_F5PPAC1_TDiffX[eurica::kMaxBigRIPSRaw]; //[BigRIPSRaw_]
   Float_t BigRIPSRaw_F5PPAC2_TDiffX[eurica::kMaxBigRIPSRaw]; //[BigRIPSRaw_]
   Float_t BigRIPSRaw_F3PPAC1_X[eurica::kMaxBigRIPSRaw];      //[BigRIPSRaw_]
   Float_t BigRIPSRaw_F3PPAC2_X[eurica::kMaxBigRIPSRaw];      //[BigRIPSRaw_]
   Float_t BigRIPSRaw_F5PPAC1_X[eurica::kMaxBigRIPSRaw];      //[BigRIPSRaw_]
   Float_t BigRIPSRaw_F5PPAC2_X[eurica::kMaxBigRIPSRaw];      //[BigRIPSRaw_]
   Float_t BigRIPSRaw_F3_X[eurica::kMaxBigRIPSRaw];           //[BigRIPSRaw_]
   Float_t BigRIPSRaw_F3_A[eurica::kMaxBigRIPSRaw];           //[BigRIPSRaw_]
   Float_t BigRIPSRaw_F5_X[eurica::kMaxBigRIPSRaw];           //[BigRIPSRaw_]
   Float_t BigRIPSRaw_F5_A[eurica::kMaxBigRIPSRaw];           //[BigRIPSRaw_]
   Float_t BigRIPSRaw_TF3SCI_L[eurica::kMaxBigRIPSRaw];       //[BigRIPSRaw_]
   Float_t BigRIPSRaw_TF3SCI_R[eurica::kMaxBigRIPSRaw];       //[BigRIPSRaw_]
   Float_t BigRIPSRaw_TF7SCI_L[eurica::kMaxBigRIPSRaw];       //[BigRIPSRaw_]
   Float_t BigRIPSRaw_TF7SCI_R[eurica::kMaxBigRIPSRaw];       //[BigRIPSRaw_]
   Float_t BigRIPSRaw_Delta_F3F5[eurica::kMaxBigRIPSRaw];     //[BigRIPSRaw_]
   Float_t BigRIPSRaw_TOF_F3F7[eurica::kMaxBigRIPSRaw];       //[BigRIPSRaw_]
   Float_t BigRIPSRaw_dT_F3L[eurica::kMaxBigRIPSRaw];         //[BigRIPSRaw_]
   Float_t BigRIPSRaw_dT_F3R[eurica::kMaxBigRIPSRaw];         //[BigRIPSRaw_]
   Float_t BigRIPSRaw_dT_F7L[eurica::kMaxBigRIPSRaw];         //[BigRIPSRaw_]
   Float_t BigRIPSRaw_dT_F7R[eurica::kMaxBigRIPSRaw];         //[BigRIPSRaw_]
   Float_t BigRIPSRaw_dT_F3F11L[eurica::kMaxBigRIPSRaw];      //[BigRIPSRaw_]
   Float_t BigRIPSRaw_dT_F3F11R[eurica::kMaxBigRIPSRaw];      //[BigRIPSRaw_]
   Float_t BigRIPSRaw_ToF_F7[eurica::kMaxBigRIPSRaw];         //[BigRIPSRaw_]
   Float_t BigRIPSRaw_ToF_F11[eurica::kMaxBigRIPSRaw];        //[BigRIPSRaw_]
   Float_t BigRIPSRaw_Beta_F3F5[eurica::kMaxBigRIPSRaw];      //[BigRIPSRaw_]
   Float_t BigRIPSRaw_Beta_F5F7[eurica::kMaxBigRIPSRaw];      //[BigRIPSRaw_]
   Float_t BigRIPSRaw_AoQ_F3F5[eurica::kMaxBigRIPSRaw];       //[BigRIPSRaw_]
   Float_t BigRIPSRaw_Zed_F11[eurica::kMaxBigRIPSRaw];        //[BigRIPSRaw_]

   // List of branches
   TBranch *b_UnpackEvent_;               //!
   TBranch *b_UnpackEvent_fUniqueID;      //!
   TBranch *b_UnpackEvent_fBits;          //!
   TBranch *b_UnpackEvent_fName;          //!
   TBranch *b_UnpackEvent_fTitle;         //!
   TBranch *b_UnpackEvent_fbIsValid;      //!
   TBranch *b_UnpackEvent_fIdentifier;    //!
   TBranch *b_UnpackEvent_detBP;          //!
   TBranch *b_UnpackEvent_detHP;          //!
   TBranch *b_UnpackEvent_vme1_1;         //!
   TBranch *b_UnpackEvent_vme1_2;         //!
   TBranch *b_UnpackEvent_nhit1;          //!
   TBranch *b_UnpackEvent_vme1s;          //!
   TBranch *b_UnpackEvent_vme4_5;         //!
   TBranch *b_UnpackEvent_vme6;           //!
   TBranch *b_UnpackEvent_vmel;           //!
   TBranch *b_UnpackEvent_nhitl;          //!
   TBranch *b_UnpackEvent_hp;             //!
   TBranch *b_UnpackEvent_vme20;          //!
   TBranch *b_UnpackEvent_vmehit;         //!
   TBranch *b_UnpackEvent_nhit;           //!
   TBranch *b_UnpackEvent_lenUSR;         //!
   TBranch *b_UnpackEvent_lenDGF;         //!
   TBranch *b_UnpackEvent_lenGeTDC;       //!
   TBranch *b_UnpackEvent_lupotslo;       //!
   TBranch *b_UnpackEvent_lupotshi;       //!
   TBranch *b_UnpackEvent_qlength;        //!
   TBranch *b_UnpackEvent_qtype;          //!
   TBranch *b_UnpackEvent_qsubtype;       //!
   TBranch *b_UnpackEvent_qdummy;         //!
   TBranch *b_UnpackEvent_qtrigger;       //!
   TBranch *b_UnpackEvent_qevent_nr;      //!
   TBranch *b_UnpackEvent_Time_sec;       //!
   TBranch *b_UnpackEvent_Time_msec;      //!
   TBranch *b_UnpackEvent_rTime;          //!
   TBranch *b_GeCluster_;                 //!
   TBranch *b_GeCluster_fUniqueID;        //!
   TBranch *b_GeCluster_fBits;            //!
   TBranch *b_GeCluster_id;               //!
   TBranch *b_GeCluster_fpl;              //!
   TBranch *b_GeCluster_name;             //!
   TBranch *b_GeCluster_fDataState;       //!
   TBranch *b_GeCluster_channel;          //!
   TBranch *b_GeCluster_fADCe;            //!
   TBranch *b_GeCluster_fADCt;            //!
   TBranch *b_GeCluster_fTDCs;            //!
   TBranch *b_GeCluster_fTDCl;            //!
   TBranch *b_GeCluster_fEnergy;          //!
   TBranch *b_GeCluster_fTime;            //!
   TBranch *b_GeAddback_;                 //!
   TBranch *b_GeAddback_fUniqueID;        //!
   TBranch *b_GeAddback_fBits;            //!
   TBranch *b_GeAddback_id;               //!
   TBranch *b_GeAddback_fpl;              //!
   TBranch *b_GeAddback_name;             //!
   TBranch *b_GeAddback_fDataState;       //!
   TBranch *b_GeAddback_channel;          //!
   TBranch *b_GeAddback_fADCe;            //!
   TBranch *b_GeAddback_fADCt;            //!
   TBranch *b_GeAddback_fTDCs;            //!
   TBranch *b_GeAddback_fTDCl;            //!
   TBranch *b_GeAddback_fEnergy;          //!
   TBranch *b_GeAddback_fTime;            //!
   TBranch *b_LaBr_;                      //!
   TBranch *b_LaBr_fUniqueID;             //!
   TBranch *b_LaBr_fBits;                 //!
   TBranch *b_LaBr_id;                    //!
   TBranch *b_LaBr_fpl;                   //!
   TBranch *b_LaBr_name;                  //!
   TBranch *b_LaBr_fDataState;            //!
   TBranch *b_LaBr_channel;               //!
   TBranch *b_LaBr_fADC;                  //!
   TBranch *b_LaBr_fTDC_srt;              //!
   TBranch *b_LaBr_fTDC_lrt;              //!
   TBranch *b_LaBr_fEnergy;               //!
   TBranch *b_LaBr_fTime_srt;             //!
   TBranch *b_LaBr_fTime_lrt;             //!
   TBranch *b_BetaPlasticUp_;             //!
   TBranch *b_BetaPlasticUp_fUniqueID;    //!
   TBranch *b_BetaPlasticUp_fBits;        //!
   TBranch *b_BetaPlasticUp_id;           //!
   TBranch *b_BetaPlasticUp_fpl;          //!
   TBranch *b_BetaPlasticUp_name;         //!
   TBranch *b_BetaPlasticUp_fDataState;   //!
   TBranch *b_BetaPlasticUp_ADC_L_Beta;   //!
   TBranch *b_BetaPlasticUp_ADC_R_Beta;   //!
   TBranch *b_BetaPlasticUp_ADC_L_Beam;   //!
   TBranch *b_BetaPlasticUp_ADC_R_Beam;   //!
   TBranch *b_BetaPlasticUp_TDC_L_lrt;    //!
   TBranch *b_BetaPlasticUp_TDC_R_lrt;    //!
   TBranch *b_BetaPlasticUp_TDC_L_srt;    //!
   TBranch *b_BetaPlasticUp_TDC_R_srt;    //!
   TBranch *b_BetaPlasticUp_Time_L_srt;   //!
   TBranch *b_BetaPlasticUp_Time_R_srt;   //!
   TBranch *b_BetaPlasticUp_Time_L_lrt;   //!
   TBranch *b_BetaPlasticUp_Time_R_lrt;   //!
   TBranch *b_BetaPlasticDown_;           //!
   TBranch *b_BetaPlasticDown_fUniqueID;  //!
   TBranch *b_BetaPlasticDown_fBits;      //!
   TBranch *b_BetaPlasticDown_id;         //!
   TBranch *b_BetaPlasticDown_fpl;        //!
   TBranch *b_BetaPlasticDown_name;       //!
   TBranch *b_BetaPlasticDown_fDataState; //!
   TBranch *b_BetaPlasticDown_ADC_L_Beta; //!
   TBranch *b_BetaPlasticDown_ADC_R_Beta; //!
   TBranch *b_BetaPlasticDown_ADC_L_Beam; //!
   TBranch *b_BetaPlasticDown_ADC_R_Beam; //!
   TBranch *b_BetaPlasticDown_TDC_L_lrt;  //!
   TBranch *b_BetaPlasticDown_TDC_R_lrt;  //!
   TBranch *b_BetaPlasticDown_TDC_L_srt;  //!
   TBranch *b_BetaPlasticDown_TDC_R_srt;  //!
   TBranch *b_BetaPlasticDown_Time_L_srt; //!
   TBranch *b_BetaPlasticDown_Time_R_srt; //!
   TBranch *b_BetaPlasticDown_Time_L_lrt; //!
   TBranch *b_BetaPlasticDown_Time_R_lrt; //!
   TBranch *b_EventInfo_;                 //!
   TBranch *b_EventInfo_fUniqueID;        //!
   TBranch *b_EventInfo_fBits;            //!
   TBranch *b_EventInfo_fName;            //!
   TBranch *b_EventInfo_fTitle;           //!
   TBranch *b_EventInfo_runnumber;        //!
   TBranch *b_EventInfo_eventnumber;      //!
   TBranch *b_EventInfo_subsysname;       //!
   TBranch *b_EventInfo_timestamp;        //!
   TBranch *b_EventInfo_comp_val;         //!
   TBranch *b_EventInfo_fBit;             //!
   TBranch *b_BigRIPSRaw_;                //!
   TBranch *b_BigRIPSRaw_fUniqueID;       //!
   TBranch *b_BigRIPSRaw_fBits;           //!
   TBranch *b_BigRIPSRaw_fName;           //!
   TBranch *b_BigRIPSRaw_fTitle;          //!
   TBranch *b_BigRIPSRaw_F3PPAC1_X1;      //!
   TBranch *b_BigRIPSRaw_F3PPAC1_X2;      //!
   TBranch *b_BigRIPSRaw_F3PPAC2_X1;      //!
   TBranch *b_BigRIPSRaw_F3PPAC2_X2;      //!
   TBranch *b_BigRIPSRaw_F5PPAC1_X1;      //!
   TBranch *b_BigRIPSRaw_F5PPAC1_X2;      //!
   TBranch *b_BigRIPSRaw_F5PPAC2_X1;      //!
   TBranch *b_BigRIPSRaw_F5PPAC2_X2;      //!
   TBranch *b_BigRIPSRaw_F3SCI_L;         //!
   TBranch *b_BigRIPSRaw_F3SCI_R;         //!
   TBranch *b_BigRIPSRaw_F7SCI_L;         //!
   TBranch *b_BigRIPSRaw_F7SCI_R;         //!
   TBranch *b_BigRIPSRaw_F11PPAC1_X1;     //!
   TBranch *b_BigRIPSRaw_F11PPAC1_Y1;     //!
   TBranch *b_BigRIPSRaw_F11PPAC1_X2;     //!
   TBranch *b_BigRIPSRaw_F11PPAC1_Y2;     //!
   TBranch *b_BigRIPSRaw_F11PPAC2_X1;     //!
   TBranch *b_BigRIPSRaw_F11PPAC2_Y1;     //!
   TBranch *b_BigRIPSRaw_F11PPAC2_X2;     //!
   TBranch *b_BigRIPSRaw_F11PPAC2_Y2;     //!
   TBranch *b_BigRIPSRaw_F11SCI_L;        //!
   TBranch *b_BigRIPSRaw_F11SCI_R;        //!
   TBranch *b_BigRIPSRaw_DE;              //!
   TBranch *b_BigRIPSRaw_F3PPAC1_TDiffX;  //!
   TBranch *b_BigRIPSRaw_F3PPAC2_TDiffX;  //!
   TBranch *b_BigRIPSRaw_F5PPAC1_TDiffX;  //!
   TBranch *b_BigRIPSRaw_F5PPAC2_TDiffX;  //!
   TBranch *b_BigRIPSRaw_F3PPAC1_X;       //!
   TBranch *b_BigRIPSRaw_F3PPAC2_X;       //!
   TBranch *b_BigRIPSRaw_F5PPAC1_X;       //!
   TBranch *b_BigRIPSRaw_F5PPAC2_X;       //!
   TBranch *b_BigRIPSRaw_F3_X;            //!
   TBranch *b_BigRIPSRaw_F3_A;            //!
   TBranch *b_BigRIPSRaw_F5_X;            //!
   TBranch *b_BigRIPSRaw_F5_A;            //!
   TBranch *b_BigRIPSRaw_TF3SCI_L;        //!
   TBranch *b_BigRIPSRaw_TF3SCI_R;        //!
   TBranch *b_BigRIPSRaw_TF7SCI_L;        //!
   TBranch *b_BigRIPSRaw_TF7SCI_R;        //!
   TBranch *b_BigRIPSRaw_Delta_F3F5;      //!
   TBranch *b_BigRIPSRaw_TOF_F3F7;        //!
   TBranch *b_BigRIPSRaw_dT_F3L;          //!
   TBranch *b_BigRIPSRaw_dT_F3R;          //!
   TBranch *b_BigRIPSRaw_dT_F7L;          //!
   TBranch *b_BigRIPSRaw_dT_F7R;          //!
   TBranch *b_BigRIPSRaw_dT_F3F11L;       //!
   TBranch *b_BigRIPSRaw_dT_F3F11R;       //!
   TBranch *b_BigRIPSRaw_ToF_F7;          //!
   TBranch *b_BigRIPSRaw_ToF_F11;         //!
   TBranch *b_BigRIPSRaw_Beta_F3F5;       //!
   TBranch *b_BigRIPSRaw_Beta_F5F7;       //!
   TBranch *b_BigRIPSRaw_AoQ_F3F5;        //!
   TBranch *b_BigRIPSRaw_Zed_F11;         //!

   virtual void Read(char *filename);
   virtual void e_blanch();
   virtual ~Data_eurica();
   virtual Int_t Cut(Long64_t entry);
   virtual Int_t GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void Init();
   virtual void Loop();
   virtual Bool_t Notify();
   virtual void Show(Long64_t entry = -1);
};

#endif

#ifdef Data_eurica_cxx
/*
Data_eurica::Data_eurica(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("treefile/euroball/go4_1006.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("treefile/euroball/go4_1006.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}
*/

void Data_eurica ::e_blanch()
{

   fChain->SetBranchStatus("*", 0);
   fChain->SetBranchStatus("EventInfo.timestamp");
   fChain->SetBranchStatus("UnpackEvent.vme4_5[30][4][2]");
   fChain->SetBranchStatus("UnpackEvent.vme6[4][32]");
   fChain->SetBranchStatus("UnpackEvent.vmel[128][3]");

   fChain->SetBranchStatus("UnpackEvent.vme1_1[32]");
   fChain->SetBranchStatus("UnpackEvent.vme1_2[32]");
   fChain->SetBranchStatus("UnpackEvent.nhit1[128]");
   fChain->SetBranchStatus("UnpackEvent.vme1s[128][10]");

   fChain->SetBranchStatus("BigRIPSRaw.F7SCI_L");
   fChain->SetBranchStatus("BigRIPSRaw.F11SCI_L");
   fChain->SetBranchStatus("BigRIPSRaw.F7SCI_R");
   fChain->SetBranchStatus("BigRIPSRaw.F11SCI_R");
   fChain->SetBranchStatus("BigRIPSRaw.AoQ_F3F5");
   fChain->SetBranchStatus("BigRIPSRaw.Zed_F11");
   /*
    *    fChain->SetBranchStatus("*",0);
    *       fChain->SetBranchStatus("EventInfo.timestamp");
    *       */
}

void Data_eurica::Read(char *filename)
{
   TFile *f = new TFile(filename);
   fChain = (TChain *)f->Get("tree");
   e_blanch();
   Init();
}

Data_eurica::~Data_eurica()
{
   if (!fChain)
      return;
   delete fChain->GetCurrentFile();
}

Int_t Data_eurica::GetEntry(Long64_t entry)
{
   // Read contents of entry.
   if (!fChain)
      return 0;
   return fChain->GetEntry(entry);
}
Long64_t Data_eurica::LoadTree(Long64_t entry)
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

void Data_eurica::Init()
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   /*
      if (!tree) return;
      fChain = tree;
   */
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("UnpackEvent", &UnpackEvent_, &b_UnpackEvent_);
   fChain->SetBranchAddress("UnpackEvent.fUniqueID", UnpackEvent_fUniqueID, &b_UnpackEvent_fUniqueID);
   fChain->SetBranchAddress("UnpackEvent.fBits", UnpackEvent_fBits, &b_UnpackEvent_fBits);
   fChain->SetBranchAddress("UnpackEvent.fName", UnpackEvent_fName, &b_UnpackEvent_fName);
   fChain->SetBranchAddress("UnpackEvent.fTitle", UnpackEvent_fTitle, &b_UnpackEvent_fTitle);
   fChain->SetBranchAddress("UnpackEvent.fbIsValid", UnpackEvent_fbIsValid, &b_UnpackEvent_fbIsValid);
   fChain->SetBranchAddress("UnpackEvent.fIdentifier", UnpackEvent_fIdentifier, &b_UnpackEvent_fIdentifier);
   fChain->SetBranchAddress("UnpackEvent.detBP[16]", UnpackEvent_detBP, &b_UnpackEvent_detBP);
   fChain->SetBranchAddress("UnpackEvent.detHP", UnpackEvent_detHP, &b_UnpackEvent_detHP);
   fChain->SetBranchAddress("UnpackEvent.vme1_1[32]", UnpackEvent_vme1_1, &b_UnpackEvent_vme1_1);
   fChain->SetBranchAddress("UnpackEvent.vme1_2[32]", UnpackEvent_vme1_2, &b_UnpackEvent_vme1_2);
   fChain->SetBranchAddress("UnpackEvent.nhit1[128]", UnpackEvent_nhit1, &b_UnpackEvent_nhit1);
   fChain->SetBranchAddress("UnpackEvent.vme1s[128][10]", UnpackEvent_vme1s, &b_UnpackEvent_vme1s);
   fChain->SetBranchAddress("UnpackEvent.vme4_5[30][4][2]", UnpackEvent_vme4_5, &b_UnpackEvent_vme4_5);
   fChain->SetBranchAddress("UnpackEvent.vme6[4][32]", UnpackEvent_vme6, &b_UnpackEvent_vme6);
   fChain->SetBranchAddress("UnpackEvent.vmel[128][3]", UnpackEvent_vmel, &b_UnpackEvent_vmel);
   fChain->SetBranchAddress("UnpackEvent.nhitl[128]", UnpackEvent_nhitl, &b_UnpackEvent_nhitl);
   fChain->SetBranchAddress("UnpackEvent.hp[4]", UnpackEvent_hp, &b_UnpackEvent_hp);
   fChain->SetBranchAddress("UnpackEvent.vme20[21][64]", UnpackEvent_vme20, &b_UnpackEvent_vme20);
   fChain->SetBranchAddress("UnpackEvent.vmehit[21][64][10]", UnpackEvent_vmehit, &b_UnpackEvent_vmehit);
   fChain->SetBranchAddress("UnpackEvent.nhit[21][64]", UnpackEvent_nhit, &b_UnpackEvent_nhit);
   fChain->SetBranchAddress("UnpackEvent.lenUSR", UnpackEvent_lenUSR, &b_UnpackEvent_lenUSR);
   fChain->SetBranchAddress("UnpackEvent.lenDGF", UnpackEvent_lenDGF, &b_UnpackEvent_lenDGF);
   fChain->SetBranchAddress("UnpackEvent.lenGeTDC", UnpackEvent_lenGeTDC, &b_UnpackEvent_lenGeTDC);
   fChain->SetBranchAddress("UnpackEvent.lupotslo", UnpackEvent_lupotslo, &b_UnpackEvent_lupotslo);
   fChain->SetBranchAddress("UnpackEvent.lupotshi", UnpackEvent_lupotshi, &b_UnpackEvent_lupotshi);
   fChain->SetBranchAddress("UnpackEvent.qlength", UnpackEvent_qlength, &b_UnpackEvent_qlength);
   fChain->SetBranchAddress("UnpackEvent.qtype", UnpackEvent_qtype, &b_UnpackEvent_qtype);
   fChain->SetBranchAddress("UnpackEvent.qsubtype", UnpackEvent_qsubtype, &b_UnpackEvent_qsubtype);
   fChain->SetBranchAddress("UnpackEvent.qdummy", UnpackEvent_qdummy, &b_UnpackEvent_qdummy);
   fChain->SetBranchAddress("UnpackEvent.qtrigger", UnpackEvent_qtrigger, &b_UnpackEvent_qtrigger);
   fChain->SetBranchAddress("UnpackEvent.qevent_nr", UnpackEvent_qevent_nr, &b_UnpackEvent_qevent_nr);
   fChain->SetBranchAddress("UnpackEvent.Time_sec", UnpackEvent_Time_sec, &b_UnpackEvent_Time_sec);
   fChain->SetBranchAddress("UnpackEvent.Time_msec", UnpackEvent_Time_msec, &b_UnpackEvent_Time_msec);
   fChain->SetBranchAddress("UnpackEvent.rTime", UnpackEvent_rTime, &b_UnpackEvent_rTime);
   fChain->SetBranchAddress("GeCluster", &GeCluster_, &b_GeCluster_);
   fChain->SetBranchAddress("GeCluster.fUniqueID", GeCluster_fUniqueID, &b_GeCluster_fUniqueID);
   fChain->SetBranchAddress("GeCluster.fBits", GeCluster_fBits, &b_GeCluster_fBits);
   fChain->SetBranchAddress("GeCluster.id", GeCluster_id, &b_GeCluster_id);
   fChain->SetBranchAddress("GeCluster.fpl", GeCluster_fpl, &b_GeCluster_fpl);
   fChain->SetBranchAddress("GeCluster.name", GeCluster_name, &b_GeCluster_name);
   fChain->SetBranchAddress("GeCluster.fDataState", GeCluster_fDataState, &b_GeCluster_fDataState);
   fChain->SetBranchAddress("GeCluster.channel", GeCluster_channel, &b_GeCluster_channel);
   fChain->SetBranchAddress("GeCluster.fADCe", GeCluster_fADCe, &b_GeCluster_fADCe);
   fChain->SetBranchAddress("GeCluster.fADCt", GeCluster_fADCt, &b_GeCluster_fADCt);
   fChain->SetBranchAddress("GeCluster.fTDCs", GeCluster_fTDCs, &b_GeCluster_fTDCs);
   fChain->SetBranchAddress("GeCluster.fTDCl", GeCluster_fTDCl, &b_GeCluster_fTDCl);
   fChain->SetBranchAddress("GeCluster.fEnergy", GeCluster_fEnergy, &b_GeCluster_fEnergy);
   fChain->SetBranchAddress("GeCluster.fTime", GeCluster_fTime, &b_GeCluster_fTime);
   fChain->SetBranchAddress("GeAddback", &GeAddback_, &b_GeAddback_);
   fChain->SetBranchAddress("GeAddback.fUniqueID", GeAddback_fUniqueID, &b_GeAddback_fUniqueID);
   fChain->SetBranchAddress("GeAddback.fBits", GeAddback_fBits, &b_GeAddback_fBits);
   fChain->SetBranchAddress("GeAddback.id", GeAddback_id, &b_GeAddback_id);
   fChain->SetBranchAddress("GeAddback.fpl", GeAddback_fpl, &b_GeAddback_fpl);
   fChain->SetBranchAddress("GeAddback.name", GeAddback_name, &b_GeAddback_name);
   fChain->SetBranchAddress("GeAddback.fDataState", GeAddback_fDataState, &b_GeAddback_fDataState);
   fChain->SetBranchAddress("GeAddback.channel", GeAddback_channel, &b_GeAddback_channel);
   fChain->SetBranchAddress("GeAddback.fADCe", GeAddback_fADCe, &b_GeAddback_fADCe);
   fChain->SetBranchAddress("GeAddback.fADCt", GeAddback_fADCt, &b_GeAddback_fADCt);
   fChain->SetBranchAddress("GeAddback.fTDCs", GeAddback_fTDCs, &b_GeAddback_fTDCs);
   fChain->SetBranchAddress("GeAddback.fTDCl", GeAddback_fTDCl, &b_GeAddback_fTDCl);
   fChain->SetBranchAddress("GeAddback.fEnergy", GeAddback_fEnergy, &b_GeAddback_fEnergy);
   fChain->SetBranchAddress("GeAddback.fTime", GeAddback_fTime, &b_GeAddback_fTime);
   fChain->SetBranchAddress("LaBr", &LaBr_, &b_LaBr_);
   fChain->SetBranchAddress("LaBr.fUniqueID", LaBr_fUniqueID, &b_LaBr_fUniqueID);
   fChain->SetBranchAddress("LaBr.fBits", LaBr_fBits, &b_LaBr_fBits);
   fChain->SetBranchAddress("LaBr.id", LaBr_id, &b_LaBr_id);
   fChain->SetBranchAddress("LaBr.fpl", LaBr_fpl, &b_LaBr_fpl);
   fChain->SetBranchAddress("LaBr.name", LaBr_name, &b_LaBr_name);
   fChain->SetBranchAddress("LaBr.fDataState", LaBr_fDataState, &b_LaBr_fDataState);
   fChain->SetBranchAddress("LaBr.channel", LaBr_channel, &b_LaBr_channel);
   fChain->SetBranchAddress("LaBr.fADC", LaBr_fADC, &b_LaBr_fADC);
   fChain->SetBranchAddress("LaBr.fTDC_srt", LaBr_fTDC_srt, &b_LaBr_fTDC_srt);
   fChain->SetBranchAddress("LaBr.fTDC_lrt", LaBr_fTDC_lrt, &b_LaBr_fTDC_lrt);
   fChain->SetBranchAddress("LaBr.fEnergy", LaBr_fEnergy, &b_LaBr_fEnergy);
   fChain->SetBranchAddress("LaBr.fTime_srt", LaBr_fTime_srt, &b_LaBr_fTime_srt);
   fChain->SetBranchAddress("LaBr.fTime_lrt", LaBr_fTime_lrt, &b_LaBr_fTime_lrt);
   fChain->SetBranchAddress("BetaPlasticUp", &BetaPlasticUp_, &b_BetaPlasticUp_);
   fChain->SetBranchAddress("BetaPlasticUp.fUniqueID", BetaPlasticUp_fUniqueID, &b_BetaPlasticUp_fUniqueID);
   fChain->SetBranchAddress("BetaPlasticUp.fBits", BetaPlasticUp_fBits, &b_BetaPlasticUp_fBits);
   fChain->SetBranchAddress("BetaPlasticUp.id", BetaPlasticUp_id, &b_BetaPlasticUp_id);
   fChain->SetBranchAddress("BetaPlasticUp.fpl", BetaPlasticUp_fpl, &b_BetaPlasticUp_fpl);
   fChain->SetBranchAddress("BetaPlasticUp.name", BetaPlasticUp_name, &b_BetaPlasticUp_name);
   fChain->SetBranchAddress("BetaPlasticUp.fDataState", BetaPlasticUp_fDataState, &b_BetaPlasticUp_fDataState);
   fChain->SetBranchAddress("BetaPlasticUp.ADC_L_Beta", BetaPlasticUp_ADC_L_Beta, &b_BetaPlasticUp_ADC_L_Beta);
   fChain->SetBranchAddress("BetaPlasticUp.ADC_R_Beta", BetaPlasticUp_ADC_R_Beta, &b_BetaPlasticUp_ADC_R_Beta);
   fChain->SetBranchAddress("BetaPlasticUp.ADC_L_Beam", BetaPlasticUp_ADC_L_Beam, &b_BetaPlasticUp_ADC_L_Beam);
   fChain->SetBranchAddress("BetaPlasticUp.ADC_R_Beam", BetaPlasticUp_ADC_R_Beam, &b_BetaPlasticUp_ADC_R_Beam);
   fChain->SetBranchAddress("BetaPlasticUp.TDC_L_lrt", BetaPlasticUp_TDC_L_lrt, &b_BetaPlasticUp_TDC_L_lrt);
   fChain->SetBranchAddress("BetaPlasticUp.TDC_R_lrt", BetaPlasticUp_TDC_R_lrt, &b_BetaPlasticUp_TDC_R_lrt);
   fChain->SetBranchAddress("BetaPlasticUp.TDC_L_srt", BetaPlasticUp_TDC_L_srt, &b_BetaPlasticUp_TDC_L_srt);
   fChain->SetBranchAddress("BetaPlasticUp.TDC_R_srt", BetaPlasticUp_TDC_R_srt, &b_BetaPlasticUp_TDC_R_srt);
   fChain->SetBranchAddress("BetaPlasticUp.Time_L_srt", BetaPlasticUp_Time_L_srt, &b_BetaPlasticUp_Time_L_srt);
   fChain->SetBranchAddress("BetaPlasticUp.Time_R_srt", BetaPlasticUp_Time_R_srt, &b_BetaPlasticUp_Time_R_srt);
   fChain->SetBranchAddress("BetaPlasticUp.Time_L_lrt", BetaPlasticUp_Time_L_lrt, &b_BetaPlasticUp_Time_L_lrt);
   fChain->SetBranchAddress("BetaPlasticUp.Time_R_lrt", BetaPlasticUp_Time_R_lrt, &b_BetaPlasticUp_Time_R_lrt);
   fChain->SetBranchAddress("BetaPlasticDown", &BetaPlasticDown_, &b_BetaPlasticDown_);
   fChain->SetBranchAddress("BetaPlasticDown.fUniqueID", BetaPlasticDown_fUniqueID, &b_BetaPlasticDown_fUniqueID);
   fChain->SetBranchAddress("BetaPlasticDown.fBits", BetaPlasticDown_fBits, &b_BetaPlasticDown_fBits);
   fChain->SetBranchAddress("BetaPlasticDown.id", BetaPlasticDown_id, &b_BetaPlasticDown_id);
   fChain->SetBranchAddress("BetaPlasticDown.fpl", BetaPlasticDown_fpl, &b_BetaPlasticDown_fpl);
   fChain->SetBranchAddress("BetaPlasticDown.name", BetaPlasticDown_name, &b_BetaPlasticDown_name);
   fChain->SetBranchAddress("BetaPlasticDown.fDataState", BetaPlasticDown_fDataState, &b_BetaPlasticDown_fDataState);
   fChain->SetBranchAddress("BetaPlasticDown.ADC_L_Beta", BetaPlasticDown_ADC_L_Beta, &b_BetaPlasticDown_ADC_L_Beta);
   fChain->SetBranchAddress("BetaPlasticDown.ADC_R_Beta", BetaPlasticDown_ADC_R_Beta, &b_BetaPlasticDown_ADC_R_Beta);
   fChain->SetBranchAddress("BetaPlasticDown.ADC_L_Beam", BetaPlasticDown_ADC_L_Beam, &b_BetaPlasticDown_ADC_L_Beam);
   fChain->SetBranchAddress("BetaPlasticDown.ADC_R_Beam", BetaPlasticDown_ADC_R_Beam, &b_BetaPlasticDown_ADC_R_Beam);
   fChain->SetBranchAddress("BetaPlasticDown.TDC_L_lrt", BetaPlasticDown_TDC_L_lrt, &b_BetaPlasticDown_TDC_L_lrt);
   fChain->SetBranchAddress("BetaPlasticDown.TDC_R_lrt", BetaPlasticDown_TDC_R_lrt, &b_BetaPlasticDown_TDC_R_lrt);
   fChain->SetBranchAddress("BetaPlasticDown.TDC_L_srt", BetaPlasticDown_TDC_L_srt, &b_BetaPlasticDown_TDC_L_srt);
   fChain->SetBranchAddress("BetaPlasticDown.TDC_R_srt", BetaPlasticDown_TDC_R_srt, &b_BetaPlasticDown_TDC_R_srt);
   fChain->SetBranchAddress("BetaPlasticDown.Time_L_srt", BetaPlasticDown_Time_L_srt, &b_BetaPlasticDown_Time_L_srt);
   fChain->SetBranchAddress("BetaPlasticDown.Time_R_srt", BetaPlasticDown_Time_R_srt, &b_BetaPlasticDown_Time_R_srt);
   fChain->SetBranchAddress("BetaPlasticDown.Time_L_lrt", BetaPlasticDown_Time_L_lrt, &b_BetaPlasticDown_Time_L_lrt);
   fChain->SetBranchAddress("BetaPlasticDown.Time_R_lrt", BetaPlasticDown_Time_R_lrt, &b_BetaPlasticDown_Time_R_lrt);
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
   fChain->SetBranchAddress("BigRIPSRaw", &BigRIPSRaw_, &b_BigRIPSRaw_);
   fChain->SetBranchAddress("BigRIPSRaw.fUniqueID", BigRIPSRaw_fUniqueID, &b_BigRIPSRaw_fUniqueID);
   fChain->SetBranchAddress("BigRIPSRaw.fBits", BigRIPSRaw_fBits, &b_BigRIPSRaw_fBits);
   fChain->SetBranchAddress("BigRIPSRaw.fName", BigRIPSRaw_fName, &b_BigRIPSRaw_fName);
   fChain->SetBranchAddress("BigRIPSRaw.fTitle", BigRIPSRaw_fTitle, &b_BigRIPSRaw_fTitle);
   fChain->SetBranchAddress("BigRIPSRaw.F3PPAC1_X1", BigRIPSRaw_F3PPAC1_X1, &b_BigRIPSRaw_F3PPAC1_X1);
   fChain->SetBranchAddress("BigRIPSRaw.F3PPAC1_X2", BigRIPSRaw_F3PPAC1_X2, &b_BigRIPSRaw_F3PPAC1_X2);
   fChain->SetBranchAddress("BigRIPSRaw.F3PPAC2_X1", BigRIPSRaw_F3PPAC2_X1, &b_BigRIPSRaw_F3PPAC2_X1);
   fChain->SetBranchAddress("BigRIPSRaw.F3PPAC2_X2", BigRIPSRaw_F3PPAC2_X2, &b_BigRIPSRaw_F3PPAC2_X2);
   fChain->SetBranchAddress("BigRIPSRaw.F5PPAC1_X1", BigRIPSRaw_F5PPAC1_X1, &b_BigRIPSRaw_F5PPAC1_X1);
   fChain->SetBranchAddress("BigRIPSRaw.F5PPAC1_X2", BigRIPSRaw_F5PPAC1_X2, &b_BigRIPSRaw_F5PPAC1_X2);
   fChain->SetBranchAddress("BigRIPSRaw.F5PPAC2_X1", BigRIPSRaw_F5PPAC2_X1, &b_BigRIPSRaw_F5PPAC2_X1);
   fChain->SetBranchAddress("BigRIPSRaw.F5PPAC2_X2", BigRIPSRaw_F5PPAC2_X2, &b_BigRIPSRaw_F5PPAC2_X2);
   fChain->SetBranchAddress("BigRIPSRaw.F3SCI_L", BigRIPSRaw_F3SCI_L, &b_BigRIPSRaw_F3SCI_L);
   fChain->SetBranchAddress("BigRIPSRaw.F3SCI_R", BigRIPSRaw_F3SCI_R, &b_BigRIPSRaw_F3SCI_R);
   fChain->SetBranchAddress("BigRIPSRaw.F7SCI_L", BigRIPSRaw_F7SCI_L, &b_BigRIPSRaw_F7SCI_L);
   fChain->SetBranchAddress("BigRIPSRaw.F7SCI_R", BigRIPSRaw_F7SCI_R, &b_BigRIPSRaw_F7SCI_R);
   fChain->SetBranchAddress("BigRIPSRaw.F11PPAC1_X1", BigRIPSRaw_F11PPAC1_X1, &b_BigRIPSRaw_F11PPAC1_X1);
   fChain->SetBranchAddress("BigRIPSRaw.F11PPAC1_Y1", BigRIPSRaw_F11PPAC1_Y1, &b_BigRIPSRaw_F11PPAC1_Y1);
   fChain->SetBranchAddress("BigRIPSRaw.F11PPAC1_X2", BigRIPSRaw_F11PPAC1_X2, &b_BigRIPSRaw_F11PPAC1_X2);
   fChain->SetBranchAddress("BigRIPSRaw.F11PPAC1_Y2", BigRIPSRaw_F11PPAC1_Y2, &b_BigRIPSRaw_F11PPAC1_Y2);
   fChain->SetBranchAddress("BigRIPSRaw.F11PPAC2_X1", BigRIPSRaw_F11PPAC2_X1, &b_BigRIPSRaw_F11PPAC2_X1);
   fChain->SetBranchAddress("BigRIPSRaw.F11PPAC2_Y1", BigRIPSRaw_F11PPAC2_Y1, &b_BigRIPSRaw_F11PPAC2_Y1);
   fChain->SetBranchAddress("BigRIPSRaw.F11PPAC2_X2", BigRIPSRaw_F11PPAC2_X2, &b_BigRIPSRaw_F11PPAC2_X2);
   fChain->SetBranchAddress("BigRIPSRaw.F11PPAC2_Y2", BigRIPSRaw_F11PPAC2_Y2, &b_BigRIPSRaw_F11PPAC2_Y2);
   fChain->SetBranchAddress("BigRIPSRaw.F11SCI_L", BigRIPSRaw_F11SCI_L, &b_BigRIPSRaw_F11SCI_L);
   fChain->SetBranchAddress("BigRIPSRaw.F11SCI_R", BigRIPSRaw_F11SCI_R, &b_BigRIPSRaw_F11SCI_R);
   fChain->SetBranchAddress("BigRIPSRaw.DE", BigRIPSRaw_DE, &b_BigRIPSRaw_DE);
   fChain->SetBranchAddress("BigRIPSRaw.F3PPAC1_TDiffX", BigRIPSRaw_F3PPAC1_TDiffX, &b_BigRIPSRaw_F3PPAC1_TDiffX);
   fChain->SetBranchAddress("BigRIPSRaw.F3PPAC2_TDiffX", BigRIPSRaw_F3PPAC2_TDiffX, &b_BigRIPSRaw_F3PPAC2_TDiffX);
   fChain->SetBranchAddress("BigRIPSRaw.F5PPAC1_TDiffX", BigRIPSRaw_F5PPAC1_TDiffX, &b_BigRIPSRaw_F5PPAC1_TDiffX);
   fChain->SetBranchAddress("BigRIPSRaw.F5PPAC2_TDiffX", BigRIPSRaw_F5PPAC2_TDiffX, &b_BigRIPSRaw_F5PPAC2_TDiffX);
   fChain->SetBranchAddress("BigRIPSRaw.F3PPAC1_X", BigRIPSRaw_F3PPAC1_X, &b_BigRIPSRaw_F3PPAC1_X);
   fChain->SetBranchAddress("BigRIPSRaw.F3PPAC2_X", BigRIPSRaw_F3PPAC2_X, &b_BigRIPSRaw_F3PPAC2_X);
   fChain->SetBranchAddress("BigRIPSRaw.F5PPAC1_X", BigRIPSRaw_F5PPAC1_X, &b_BigRIPSRaw_F5PPAC1_X);
   fChain->SetBranchAddress("BigRIPSRaw.F5PPAC2_X", BigRIPSRaw_F5PPAC2_X, &b_BigRIPSRaw_F5PPAC2_X);
   fChain->SetBranchAddress("BigRIPSRaw.F3_X", BigRIPSRaw_F3_X, &b_BigRIPSRaw_F3_X);
   fChain->SetBranchAddress("BigRIPSRaw.F3_A", BigRIPSRaw_F3_A, &b_BigRIPSRaw_F3_A);
   fChain->SetBranchAddress("BigRIPSRaw.F5_X", BigRIPSRaw_F5_X, &b_BigRIPSRaw_F5_X);
   fChain->SetBranchAddress("BigRIPSRaw.F5_A", BigRIPSRaw_F5_A, &b_BigRIPSRaw_F5_A);
   fChain->SetBranchAddress("BigRIPSRaw.TF3SCI_L", BigRIPSRaw_TF3SCI_L, &b_BigRIPSRaw_TF3SCI_L);
   fChain->SetBranchAddress("BigRIPSRaw.TF3SCI_R", BigRIPSRaw_TF3SCI_R, &b_BigRIPSRaw_TF3SCI_R);
   fChain->SetBranchAddress("BigRIPSRaw.TF7SCI_L", BigRIPSRaw_TF7SCI_L, &b_BigRIPSRaw_TF7SCI_L);
   fChain->SetBranchAddress("BigRIPSRaw.TF7SCI_R", BigRIPSRaw_TF7SCI_R, &b_BigRIPSRaw_TF7SCI_R);
   fChain->SetBranchAddress("BigRIPSRaw.Delta_F3F5", BigRIPSRaw_Delta_F3F5, &b_BigRIPSRaw_Delta_F3F5);
   fChain->SetBranchAddress("BigRIPSRaw.TOF_F3F7", BigRIPSRaw_TOF_F3F7, &b_BigRIPSRaw_TOF_F3F7);
   fChain->SetBranchAddress("BigRIPSRaw.dT_F3L", BigRIPSRaw_dT_F3L, &b_BigRIPSRaw_dT_F3L);
   fChain->SetBranchAddress("BigRIPSRaw.dT_F3R", BigRIPSRaw_dT_F3R, &b_BigRIPSRaw_dT_F3R);
   fChain->SetBranchAddress("BigRIPSRaw.dT_F7L", BigRIPSRaw_dT_F7L, &b_BigRIPSRaw_dT_F7L);
   fChain->SetBranchAddress("BigRIPSRaw.dT_F7R", BigRIPSRaw_dT_F7R, &b_BigRIPSRaw_dT_F7R);
   fChain->SetBranchAddress("BigRIPSRaw.dT_F3F11L", BigRIPSRaw_dT_F3F11L, &b_BigRIPSRaw_dT_F3F11L);
   fChain->SetBranchAddress("BigRIPSRaw.dT_F3F11R", BigRIPSRaw_dT_F3F11R, &b_BigRIPSRaw_dT_F3F11R);
   fChain->SetBranchAddress("BigRIPSRaw.ToF_F7", BigRIPSRaw_ToF_F7, &b_BigRIPSRaw_ToF_F7);
   fChain->SetBranchAddress("BigRIPSRaw.ToF_F11", BigRIPSRaw_ToF_F11, &b_BigRIPSRaw_ToF_F11);
   fChain->SetBranchAddress("BigRIPSRaw.Beta_F3F5", BigRIPSRaw_Beta_F3F5, &b_BigRIPSRaw_Beta_F3F5);
   fChain->SetBranchAddress("BigRIPSRaw.Beta_F5F7", BigRIPSRaw_Beta_F5F7, &b_BigRIPSRaw_Beta_F5F7);
   fChain->SetBranchAddress("BigRIPSRaw.AoQ_F3F5", BigRIPSRaw_AoQ_F3F5, &b_BigRIPSRaw_AoQ_F3F5);
   fChain->SetBranchAddress("BigRIPSRaw.Zed_F11", BigRIPSRaw_Zed_F11, &b_BigRIPSRaw_Zed_F11);
   Notify();
}

Bool_t Data_eurica::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Data_eurica::Show(Long64_t entry)
{
   // Print contents of entry.
   // If entry is not specified, print current entry
   if (!fChain)
      return;
   fChain->Show(entry);
}
Int_t Data_eurica::Cut(Long64_t entry)
{
   // This function may be called from Loop.
   // returns  1 if entry is accepted.
   // returns -1 otherwise.
   return 1;
}
#endif // #ifdef Data_eurica_cxx
