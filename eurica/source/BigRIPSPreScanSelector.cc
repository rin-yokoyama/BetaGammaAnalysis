/**
 * @file BigRIPSPreScanSelector.cc
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief
 * @version 0.1
 * @date 2023-01-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "EuricaBigRIPSPreScanSelector.h"
#include "TDirectory.h"

ClassImp(eurica::BigRIPSPreScanSelector)

    eurica::BigRIPSPreScanSelector::BigRIPSPreScanSelector(TTree *tree) : tree_reader_(tree),
                                                                          aoq_(tree_reader_, "AOQ"),
                                                                          zet_(tree_reader_, "ZET"),
                                                                          ts_(tree_reader_, "EventInfo.timestamp"),
                                                                          evtnumber_(tree_reader_, "EventInfo.eventnumber"),
                                                                          runnumber_(tree_reader_, "EventInfo.runnumber"),
                                                                          output_file_name_("default_name")
{
}

eurica::BigRIPSPreScanSelector::~BigRIPSPreScanSelector()
{
    if (fOutputFile)
        delete fOutputFile;
}

void eurica::BigRIPSPreScanSelector::Begin(TTree *tree)
{
    // Begin() is called only in the client process.
    // Get OutputFileName from the list of input objects.
    // This is required when you write a file in the Terminate() method.
    if (fInput)
    {
        TNamed *named = (TNamed *)fInput->FindObject("OutputFileName");
        if (named)
            output_file_name_ = named->GetTitle();
    }
}

void eurica::BigRIPSPreScanSelector::SlaveBegin(TTree *tree)
{
    // SlaveBegin() is called only in the worker process when it runs on PROOF.
    // If it's not on PROOF, SlaveBegin() is called after Begin()

    // Clear the fOutputList.
    // fOutputList is a list of object which will be merged and sent to the client process.
    GetOutputList()->Clear();

    // Save current TDirectory
    TDirectory *savedir = gDirectory;

    if (gProofServ)
    {
        // If this process is running on a PROOF server, read objects from fInput.
        if (fInput)
        {
            TNamed *named = (TNamed *)fInput->FindObject("OutputFileName");
            if (named)
                output_file_name_ = named->GetTitle();
            TParameter<Bool_t> *merge_tree = (TParameter<Bool_t> *)fInput->FindObject("MergeTree");
            if (merge_tree)
                merge_tree_ = merge_tree->GetVal();
        }

        // Create a TProofOutputFile
        if (fProofFile)
            delete fProofFile;
        if (merge_tree_)
        {
            // Option "M" to merge files from all the workers at the end
            fProofFile = new TProofOutputFile(output_file_name_.c_str(), "M");
        }
        else
        {
            // Without "M" not to merge output
            fProofFile = new TProofOutputFile(output_file_name_.c_str(), "");
        }

        // Open an output file for this worker.
        fProofFile->SetOutputFileName(output_file_name_.c_str());
        if (fOutputFile)
            delete fOutputFile;
        fOutputFile = fProofFile->OpenFile("RECREATE");

        // You can send a message to the client process from workers by using SendAsynMessage()
        const TString msg = TString::Format("SalveBegin() of Ord = %s is called.", gProofServ->GetOrdinal());
        gProofServ->SendAsynMessage(msg);
    }
    else
    {
        // If it's not on PROOF, just create a new file.
        if (fOutputFile)
            delete fOutputFile;
        fOutputFile = new TFile(output_file_name_.c_str(), "RECREATE");
    }

    // Create an output tree.
    if (fOutputTree)
        delete fOutputTree;
    fOutputTree = new TTree("OutputTree", "OutputTree");
    fOutputTree->Branch("BigRIPSData", "BigRIPSData", &output_data_);
    fOutputTree->SetDirectory(fOutputFile);
    fOutputTree->AutoSave();

    // Recover the current directory.
    gDirectory = savedir;
}

void eurica::BigRIPSPreScanSelector::Init(TTree *tree)
{
    // Init() is called when the selector needs to initialize a new tree
    // According to the ROOT documentation, the tree argument of the Begin()
    // and SlaveBegin() functions is deprecated.
    // Therefore, SetTree() should be called in this function.
    tree_reader_.SetTree(tree);
}

Bool_t eurica::BigRIPSPreScanSelector::Process(Long64_t entry)
{
    // Process() is called for each entry in the tree.
    // This function should contain the body of the analysis.

    tree_reader_.SetLocalEntry(entry);

    if (aoq_.GetSize() < 3 || zet_.GetSize() < 2 || ts_.GetSize() < 1)
        return kTRUE;
    output_data_.aoq_ = aoq_[0];
    output_data_.zet_ = zet_[1];
    output_data_.ts_ = ts_[0];
    output_data_.evtnumber_ = evtnumber_[0];
    output_data_.runnumber_ = runnumber_[0];

    // Fill the tree and the histogram
    fOutputTree->Fill();

    return kTRUE;
}

void eurica::BigRIPSPreScanSelector::SlaveTerminate()
{
    // SlaveTerminate() is called after all entries have been processed.
    // This function is called only in the worker process.
    // If it's not on PROOF, SlaveTerminate() is called before Terminate()

    // Unlink the tree reader from the input tree.
    tree_reader_.SetTree((TTree *)nullptr);

    // Write the tree and the histogram to file.
    TDirectory *savedir = gDirectory;
    fOutputFile->cd();
    fOutputTree->Write();

    // If merge_tree_ flag is true, add the file to the fOutput
    // so the files from all the workers will be merged.
    if (merge_tree_)
        fOutput->Add(fProofFile);

    // Close the file.
    fOutputTree->SetDirectory(0);
    fOutputFile->Close();
    gDirectory = savedir;
    delete fOutputFile;
    fOutputFile = nullptr;
}

void eurica::BigRIPSPreScanSelector::Terminate()
{
    // Terminate() is called only in the client process

    // If there is a histogram in the output list (i.e. merge_tree_ = false),
    // create a file in the client process and write it to the file.
    auto hist = GetOutputList()->FindObject("h_output_value");
    if (hist)
    {
        fOutputFile = TFile::Open(output_file_name_.c_str(), "UPDATE");
        hist->Write();
        fOutputFile->Close();
    }
}
