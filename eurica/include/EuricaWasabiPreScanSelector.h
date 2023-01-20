/**
 * @file EuricaWasabiPreScanSelector.h
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief Pre scan Wasabi raw tree data and generate a new tree with
 *  WasabiData object
 * @version 0.1
 * @date 2023-01-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __EURICA_WASABI_PRESCAN_SELECTOR_H
#define __EURICA_WASABI_PRESCAN_SELECTOR_H
#include <iostream>
#include <string>
#include "TSelector.h"
#include "TTree.h"
#include "TProofServ.h"
#include "TProofOutputFile.h"
#include "TFile.h"
#include "TParameter.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "TTreeReaderArray.h"
#include "EuricaMergerData.hpp"
#include "GACalibManager.h"
#include "GASlewCorrectionManager.h"

namespace eurica
{
    class WasabiPreScanSelector;
}

class eurica::WasabiPreScanSelector : public TSelector
{
public:
    WasabiPreScanSelector(TTree *tree = 0);
    virtual ~WasabiPreScanSelector();

    // Overloaded from TSelector
    virtual Int_t Version() const { return 1; }
    virtual void Init(TTree *tree);
    virtual void Begin(TTree *tree);
    virtual void SlaveBegin(TTree *tree);
    virtual Bool_t Notify()
    {
        std::cout << "Notify() called." << std::endl;
        return kTRUE;
    }
    virtual Bool_t Process(Long64_t entry);
    virtual void SetOption(const char *option) { fOption = option; }
    virtual void SetObject(TObject *obj) { fObject = obj; }
    virtual void SetInputList(TList *input) { fInput = input; }
    virtual TList *GetOutputList() const { return fOutput; }
    virtual void SlaveTerminate();
    virtual void Terminate();

    // Set methods
    void SetOutputFileName(const std::string &name) { output_file_name_ = name; }
    void SetInputPIDFileName(const std::string &name) { input_pidfile_name_ = name; }
    void SetEXFileName(const std::string &name) { ex_file_name_ = name; }
    void SetEYFileName(const std::string &name) { ey_file_name_ = name; }
    void SetTXFileName(const std::string &name) { tx_file_name_ = name; }
    void SetTYFileName(const std::string &name) { ty_file_name_ = name; }
    void SetSlewXFileName(const std::string &name) { slewx_file_name_ = name; }
    void SetSlewYFileName(const std::string &name) { slewy_file_name_ = name; }

protected:
    static const Int_t kTDCThreshold = -100000;
    static const Int_t kNHit = 3;
    static const Int_t kNLayer = 5;
    static const Int_t kNX = 60;
    static const Int_t kNY = 40;
    TTreeReader tree_reader_;           // TTreeReader for the input tree
    TTreeReaderArray<Int_t> dssdE_;     // TTreeReaderArray for the input AoQ branch
    TTreeReaderArray<Int_t> dssdT_;     // TTreeReaderArray for the input Zet branch
    TTreeReaderArray<ULong64_t> ts_;    // TTreeReaderArray for the input timestamp branch
    TTreeReaderArray<Int_t> evtnumber_; // TTreeReaderArray for the input event number branch
    TTreeReaderArray<Int_t> runnumber_; // TTreeReaderArray for the input runnumber branch

    GACalibManager *calib_tx_;
    GACalibManager *calib_ty_;
    GACalibManager *calib_ex_;
    GACalibManager *calib_ey_;
    GASlewCorrectionManager *slew_x_;
    GASlewCorrectionManager *slew_y_;

    eurica::WasabiData output_data_;        // The output data that will be filled to the output tree.
    TTree *fOutputTree = nullptr;           // A pointer to the output tree object
    TFile *fOutputFile = nullptr;           // A pointer to the output file object
    TProofOutputFile *fProofFile = nullptr; // A pointer to the ProofOutputFile object
    std::string output_file_name_;          // The output file name
    std::string input_pidfile_name_;        // The input PID gate file name
    std::string ex_file_name_;              // calib ex file name
    std::string ey_file_name_;              // calib ey file name
    std::string tx_file_name_;              // calib tx file name
    std::string ty_file_name_;              // calib ty file name
    std::string slewx_file_name_;           // slew correction x file name
    std::string slewy_file_name_;           // slew correction y file name
    Bool_t merge_tree_ = false;             // A flag whether to merge tree output at the end when use PROOF.

    ClassDef(WasabiPreScanSelector, 1)
};

#endif