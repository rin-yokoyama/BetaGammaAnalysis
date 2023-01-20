/**
 * @file EuricaPreScanSelector.h
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief Pre scan Eurica raw tree data and generate a new tree with
 *  EuricaData object
 * @version 0.1
 * @date 2023-01-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __EURICA_PRESCAN_SELECTOR_H
#define __EURICA_PRESCAN_SELECTOR_H
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
    class EuricaPreScanSelector;
}

class eurica::EuricaPreScanSelector : public TSelector
{
public:
    EuricaPreScanSelector(TTree *tree = 0);
    virtual ~EuricaPreScanSelector();

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
    void SetGeEFileName(const std::string &name) { ge_ecal_file_name_ = name; }
    void SetGeTFileName(const std::string &name) { ge_tcal_file_name_ = name; }
    void SetLabrEFileName(const std::string &name) { labr_ecal_file_name_ = name; }
    void SetLabrTFileName(const std::string &name) { labr_tcal_file_name_ = name; }
    void SetGeSlewFileName(const std::string &name) { ge_slew_file_name_ = name; }
    void SetLabrSlewFileName(const std::string &name) { labr_slew_file_name_ = name; }

protected:
    static const Int_t kTDCThreshold = -100000;
    static const Int_t kNDetector = 12;
    static const Int_t kNCrystal = 7;
    static const Int_t kNLabr = 7;
    TTreeReader tree_reader_;           // TTreeReader for the input tree
    TTreeReaderArray<Int_t> vme1_2_;    // TTreeReaderArray for the input AoQ branch
    TTreeReaderArray<Int_t> vme4_5_;    // TTreeReaderArray for the input AoQ branch
    TTreeReaderArray<Int_t> vme6_;      // TTreeReaderArray for the input Zet branch
    TTreeReaderArray<Int_t> vmel_;      // TTreeReaderArray for the input Zet branch
    TTreeReaderArray<ULong64_t> ts_;    // TTreeReaderArray for the input timestamp branch
    TTreeReaderArray<Int_t> evtnumber_; // TTreeReaderArray for the input event number branch
    TTreeReaderArray<Int_t> runnumber_; // TTreeReaderArray for the input runnumber branch

    GACalibManager *calib_ge_e_;
    GACalibManager *calib_ge_t_;
    GACalibManager *calib_labr_e_;
    GACalibManager *calib_labr_t_;
    GASlewCorrectionManager *slew_ge_;
    GASlewCorrectionManager *slew_labr_;

    eurica::ClusterData output_data_;       // The output data that will be filled to the output tree.
    TTree *fOutputTree = nullptr;           // A pointer to the output tree object
    TFile *fOutputFile = nullptr;           // A pointer to the output file object
    TProofOutputFile *fProofFile = nullptr; // A pointer to the ProofOutputFile object
    std::string output_file_name_;          // The output file name
    std::string ge_ecal_file_name_;         // Ge E calib file name
    std::string ge_tcal_file_name_;         // Ge T calib file name
    std::string ge_slew_file_name_;         // Ge slew correction file name
    std::string labr_ecal_file_name_;       // Labr E calib file name
    std::string labr_tcal_file_name_;       // Labr T calib file name
    std::string labr_slew_file_name_;       // Labr slew correction file name
    Bool_t merge_tree_ = false;             // A flag whether to merge tree output at the end when use PROOF.

    ClassDef(EuricaPreScanSelector, 1)
};

#endif