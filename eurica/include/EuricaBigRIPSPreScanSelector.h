/**
 * @file EuricaBigRIPSPreScanSelector.h
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief Pre scan BigRIPS raw tree data and generate a new tree with
 *  BigRIPSData object
 * @version 0.1
 * @date 2023-01-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __EURICA_BIGRIPS_PRESCAN_SELECTOR_H
#define __EURICA_BIGRIPS_PRESCAN_SELECTOR_H
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

namespace eurica
{
    class BigRIPSPreScanSelector;
}

class eurica::BigRIPSPreScanSelector : public TSelector
{
public:
    BigRIPSPreScanSelector(TTree *tree = 0);
    virtual ~BigRIPSPreScanSelector();

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

protected:
    TTreeReader tree_reader_;           // TTreeReader for the input tree
    TTreeReaderArray<Double_t> aoq_;    // TTreeReaderArray for the input AoQ branch
    TTreeReaderArray<Double_t> zet_;    // TTreeReaderArray for the input Zet branch
    TTreeReaderArray<ULong64_t> ts_;    // TTreeReaderArray for the input timestamp branch
    TTreeReaderArray<Int_t> evtnumber_; // TTreeReaderArray for the input event number branch
    TTreeReaderArray<Int_t> runnumber_; // TTreeReaderArray for the input runnumber branch

    eurica::BigRIPSData output_data_;       // The output data that will be filled to the output tree.
    TTree *fOutputTree = nullptr;           // A pointer to the output tree object
    TFile *fOutputFile = nullptr;           // A pointer to the output file object
    TProofOutputFile *fProofFile = nullptr; // A pointer to the ProofOutputFile object
    std::string output_file_name_;          // The output file name
    Bool_t merge_tree_ = false;             // A flag whether to merge tree output at the end when use PROOF.

    ClassDef(BigRIPSPreScanSelector, 1)
};

#endif