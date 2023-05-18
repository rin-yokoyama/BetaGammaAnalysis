/**
 * @file WasabiPreScanSelector.cc
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief
 * @version 0.1
 * @date 2023-01-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "EuricaWasabiPreScanSelector.h"
#include "TDirectory.h"

ClassImp(eurica::WasabiPreScanSelector)

    eurica::WasabiPreScanSelector::WasabiPreScanSelector(TTree *tree) : tree_reader_(tree),
                                                                        dssdE_(tree_reader_, "DSSD_E"),
                                                                        dssdT_(tree_reader_, "DSSD_T"),
                                                                        ts_(tree_reader_, "EventInfo.timestamp"),
                                                                        evtnumber_(tree_reader_, "EventInfo.eventnumber"),
                                                                        runnumber_(tree_reader_, "EventInfo.runnumber"),
                                                                        output_file_name_("default_name")
{
}

eurica::WasabiPreScanSelector::~WasabiPreScanSelector()
{
    if (fOutputFile)
        delete fOutputFile;
}

void eurica::WasabiPreScanSelector::Begin(TTree *tree)
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

void eurica::WasabiPreScanSelector::SlaveBegin(TTree *tree)
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
            {
                TNamed *named = (TNamed *)fInput->FindObject("OutputFileName");
                if (named)
                    output_file_name_ = named->GetTitle();
            }
            {
                TNamed *named = (TNamed *)fInput->FindObject("EXFileName");
                if (named)
                    ex_file_name_ = named->GetTitle();
            }
            {
                TNamed *named = (TNamed *)fInput->FindObject("EYFileName");
                if (named)
                    ey_file_name_ = named->GetTitle();
            }
            {
                TNamed *named = (TNamed *)fInput->FindObject("TXFileName");
                if (named)
                    tx_file_name_ = named->GetTitle();
            }
            {
                TNamed *named = (TNamed *)fInput->FindObject("TYFileName");
                if (named)
                    ty_file_name_ = named->GetTitle();
            }
            {
                TNamed *named = (TNamed *)fInput->FindObject("SlewXFileName");
                if (named)
                    slewx_file_name_ = named->GetTitle();
            }
            {
                TNamed *named = (TNamed *)fInput->FindObject("SlewYFileName");
                if (named)
                    slewy_file_name_ = named->GetTitle();
            }
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
    fOutputTree->Branch("WasabiData", "WasabiData", &output_data_);
    fOutputTree->SetDirectory(fOutputFile);
    fOutputTree->AutoSave();

    // Recover the current directory.
    gDirectory = savedir;

    calib_ex_ = new GACalibManager(ex_file_name_, kNX * kNLayer);
    calib_ey_ = new GACalibManager(ey_file_name_, kNY * kNLayer);
    calib_tx_ = new GACalibManager(tx_file_name_, kNX * kNLayer);
    calib_ty_ = new GACalibManager(ty_file_name_, kNY * kNLayer);
    slew_x_ = new GASlewCorrectionManager(slewx_file_name_, kNX * kNLayer);
    slew_y_ = new GASlewCorrectionManager(slewy_file_name_, kNY * kNLayer);
}

void eurica::WasabiPreScanSelector::Init(TTree *tree)
{
    // Init() is called when the selector needs to initialize a new tree
    // According to the ROOT documentation, the tree argument of the Begin()
    // and SlaveBegin() functions is deprecated.
    // Therefore, SetTree() should be called in this function.
    tree_reader_.SetTree(tree);
}

Bool_t eurica::WasabiPreScanSelector::Process(Long64_t entry)
{
    // Process() is called for each entry in the tree.
    // This function should contain the body of the analysis.

    tree_reader_.SetLocalEntry(entry);
    output_data_.Clear();

    for (int i_layer = 0; i_layer < kNLayer; i_layer++)
    {
        for (int i_x = 0; i_x < kNX; i_x++)
        {
            Double_t hit_time = calib_tx_->GCalib(
                i_x + i_layer * kNX, dssdT_[(i_layer * (kNX + kNY) + i_x) * kNHit]);
            hit_time = slew_x_->SlewCorrect(
                i_layer * kNX + i_x,
                hit_time,
                dssdE_[i_layer * (kNX + kNY) + i_x]);
            Double_t hit_energy = calib_ex_->GCalib(
                i_x + i_layer * kNX, dssdE_[i_layer * (kNX + kNY) + i_x]);
            if (hit_time > kTDCThreshold)
            {
                // auto hit = new WasabiHitData();
                // hit->energy_ = hit_energy;
                // hit->time_ = hit_time;
                // hit->layer_ = i_layer;
                // hit->id_ = i_x;
                // output_data_.x_.emplace_back(hit);
                WasabiHitData hit;
                hit.energy_ = hit_energy;
                hit.time_ = hit_time;
                hit.layer_ = i_layer;
                hit.id_ = i_x;
                output_data_.x_.emplace_back(hit);
            }
        }
        for (int i_y = 0; i_y < kNY; i_y++)
        {
            Double_t hit_time = calib_ty_->GCalib(
                i_y + i_layer * kNY,
                dssdT_[(i_layer * (kNX + kNY) + i_y + kNX) * kNHit]);
            hit_time = slew_y_->SlewCorrect(
                i_layer * kNY + i_y,
                hit_time,
                dssdE_[i_layer * (kNX + kNY) + i_y + kNX]);
            Double_t hit_energy = calib_ey_->GCalib(
                i_y + i_layer * kNY,
                dssdE_[i_layer * (kNX + kNY) + i_y + kNX]);
            if (hit_time > kTDCThreshold)
            {
                // auto hit = new WasabiHitData();
                // hit->energy_ = hit_energy;
                // hit->time_ = hit_time;
                // hit->layer_ = i_layer;
                // hit->id_ = i_y;
                // output_data_.y_.emplace_back(hit);
                WasabiHitData hit;
                hit.energy_ = hit_energy;
                hit.time_ = hit_time;
                hit.layer_ = i_layer;
                hit.id_ = i_y;
                output_data_.y_.emplace_back(hit);
            }
        }
    }
    output_data_.ts_ = ts_[0];
    output_data_.evtnumber_ = evtnumber_[0];
    output_data_.runnumber_ = runnumber_[0];

    // Fill the tree and the histogram
    fOutputTree->Fill();

    return kTRUE;
}

void eurica::WasabiPreScanSelector::SlaveTerminate()
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

void eurica::WasabiPreScanSelector::Terminate()
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
