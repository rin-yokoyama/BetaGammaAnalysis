/**
 * @file EuricaPreScanSelector.cc
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief
 * @version 0.1
 * @date 2023-01-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "EuricaPreScanSelector.h"
#include "TDirectory.h"

ClassImp(eurica::EuricaPreScanSelector)

    eurica::EuricaPreScanSelector::EuricaPreScanSelector(TTree *tree) : tree_reader_(tree),
                                                                        vme1_2_(tree_reader_, "UnpackEvent.vme1_2"),
                                                                        vme4_5_(tree_reader_, "UnpackEvent.vme4_5"),
                                                                        vme6_(tree_reader_, "UnpackEvent.vme6"),
                                                                        vmel_(tree_reader_, "UnpackEvent.vmel"),
                                                                        ts_(tree_reader_, "EventInfo.timestamp"),
                                                                        evtnumber_(tree_reader_, "EventInfo.eventnumber"),
                                                                        runnumber_(tree_reader_, "EventInfo.runnumber"),
                                                                        output_file_name_("default_name")
{
}

eurica::EuricaPreScanSelector::~EuricaPreScanSelector()
{
    if (fOutputFile)
        delete fOutputFile;
}

void eurica::EuricaPreScanSelector::Begin(TTree *tree)
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

void eurica::EuricaPreScanSelector::SlaveBegin(TTree *tree)
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
                TNamed *named = (TNamed *)fInput->FindObject("GeEFileName");
                if (named)
                    ge_ecal_file_name_ = named->GetTitle();
            }
            {
                TNamed *named = (TNamed *)fInput->FindObject("GeTFileName");
                if (named)
                    ge_tcal_file_name_ = named->GetTitle();
            }
            {
                TNamed *named = (TNamed *)fInput->FindObject("LabrEFileName");
                if (named)
                    labr_ecal_file_name_ = named->GetTitle();
            }
            {
                TNamed *named = (TNamed *)fInput->FindObject("LabrTFileName");
                if (named)
                    labr_tcal_file_name_ = named->GetTitle();
            }
            {
                TNamed *named = (TNamed *)fInput->FindObject("GeSlewFileName");
                if (named)
                    ge_slew_file_name_ = named->GetTitle();
            }
            {
                TNamed *named = (TNamed *)fInput->FindObject("LabrSlewFileName");
                if (named)
                    labr_slew_file_name_ = named->GetTitle();
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
    fOutputTree->Branch("EuricaData", "EuricaData", &output_data_);
    fOutputTree->SetDirectory(fOutputFile);
    fOutputTree->AutoSave();

    // Recover the current directory.
    gDirectory = savedir;

    calib_ge_e_ = new GACalibManager(ge_ecal_file_name_, kNDetector * kNCrystal);
    calib_ge_t_ = new GACalibManager(ge_tcal_file_name_, kNDetector * kNCrystal);
    calib_labr_e_ = new GACalibManager(labr_ecal_file_name_, kNLabr);
    calib_labr_t_ = new GACalibManager(labr_tcal_file_name_, kNLabr);
    slew_ge_ = new GASlewCorrectionManager(ge_slew_file_name_, kNDetector * kNCrystal);
    slew_labr_ = new GASlewCorrectionManager(labr_slew_file_name_, kNLabr);
}

void eurica::EuricaPreScanSelector::Init(TTree *tree)
{
    // Init() is called when the selector needs to initialize a new tree
    // According to the ROOT documentation, the tree argument of the Begin()
    // and SlaveBegin() functions is deprecated.
    // Therefore, SetTree() should be called in this function.
    tree_reader_.SetTree(tree);
}

Bool_t eurica::EuricaPreScanSelector::Process(Long64_t entry)
{
    // Process() is called for each entry in the tree.
    // This function should contain the body of the analysis.

    tree_reader_.SetLocalEntry(entry);
    output_data_.Clear();

    // mapping cluster
    {
        Int_t adc[kNDetector][kNCrystal];
        Int_t dgf[kNDetector][kNCrystal];

        Int_t fvme4_5[30][4][2];
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 2; k++)
                    fvme4_5[i][j][k] = vme4_5_[4 * 2 * i + j * 2 + k];
            }
        }
        // Energy
        // Cluster A (1)
        adc[0][0] = fvme4_5[0][0][0];
        adc[0][1] = fvme4_5[0][1][0];
        adc[0][2] = fvme4_5[0][2][0];
        adc[0][3] = fvme4_5[0][3][0];
        adc[0][4] = fvme4_5[1][0][0];
        adc[0][5] = fvme4_5[1][1][0];
        adc[0][6] = fvme4_5[1][2][0];

        // Cluster B (2)
        adc[1][0] = fvme4_5[2][0][0];
        adc[1][1] = fvme4_5[2][1][0];
        adc[1][2] = fvme4_5[2][2][0];
        adc[1][3] = fvme4_5[2][3][0];
        adc[1][4] = fvme4_5[3][0][0];
        adc[1][5] = fvme4_5[3][1][0];
        adc[1][6] = fvme4_5[3][2][0];

        // Cluster C (3)
        adc[2][0] = fvme4_5[4][0][0];
        adc[2][1] = fvme4_5[4][1][0];
        adc[2][2] = fvme4_5[4][2][0];
        adc[2][3] = fvme4_5[4][3][0];
        adc[2][4] = fvme4_5[5][0][0];
        adc[2][5] = fvme4_5[5][1][0];
        adc[2][6] = fvme4_5[5][2][0];

        // Cluster D (4)
        adc[3][0] = fvme4_5[1][3][0];
        adc[3][1] = fvme4_5[6][1][0];
        adc[3][2] = fvme4_5[6][2][0];
        adc[3][3] = fvme4_5[6][3][0];
        adc[3][4] = fvme4_5[7][0][0];
        adc[3][5] = fvme4_5[7][1][0];
        adc[3][6] = fvme4_5[5][3][0];

        // Cluster E (5)
        adc[4][0] = fvme4_5[8][0][0];
        adc[4][1] = fvme4_5[8][1][0];
        adc[4][2] = fvme4_5[8][2][0];
        adc[4][3] = fvme4_5[8][3][0];
        adc[4][4] = fvme4_5[9][0][0];
        adc[4][5] = fvme4_5[9][1][0];
        adc[4][6] = fvme4_5[9][2][0];

        // Cluster F (6)
        adc[5][0] = fvme4_5[10][0][0];
        adc[5][1] = fvme4_5[10][1][0];
        adc[5][2] = fvme4_5[10][2][0];
        adc[5][3] = fvme4_5[10][3][0];
        adc[5][4] = fvme4_5[11][0][0];
        adc[5][5] = fvme4_5[11][1][0];
        adc[5][6] = fvme4_5[11][2][0];

        // Cluster G (7)
        adc[6][0] = fvme4_5[12][0][0];
        adc[6][1] = fvme4_5[12][1][0];
        adc[6][2] = fvme4_5[12][2][0];
        adc[6][3] = fvme4_5[12][3][0];
        adc[6][4] = fvme4_5[13][0][0];
        adc[6][5] = fvme4_5[13][1][0];
        adc[6][6] = fvme4_5[13][2][0];

        // Cluster J (8)
        adc[7][0] = fvme4_5[14][0][0];
        adc[7][1] = fvme4_5[14][1][1]; // Dead Crystal
        adc[7][2] = fvme4_5[14][2][0];
        adc[7][3] = fvme4_5[14][3][0];
        adc[7][4] = fvme4_5[15][0][0];
        adc[7][5] = fvme4_5[15][1][0];
        adc[7][6] = fvme4_5[15][2][0];

        // Cluster K (9)
        adc[8][0] = fvme4_5[16][0][0];
        adc[8][1] = fvme4_5[16][1][0];
        adc[8][2] = fvme4_5[16][2][0];
        adc[8][3] = fvme4_5[16][3][0];
        adc[8][4] = fvme4_5[17][0][0];
        adc[8][5] = fvme4_5[17][1][0];
        adc[8][6] = fvme4_5[9][3][0];

        // Cluster L (10)
        adc[9][0] = fvme4_5[18][0][0];
        adc[9][1] = fvme4_5[18][1][0];
        adc[9][2] = fvme4_5[18][2][0];
        adc[9][3] = fvme4_5[18][3][0];
        adc[9][4] = fvme4_5[19][0][0];
        adc[9][5] = fvme4_5[19][1][0];
        adc[9][6] = fvme4_5[19][2][0];

        // Cluster M (11)
        adc[10][0] = fvme4_5[20][0][0];
        adc[10][1] = fvme4_5[20][1][0];
        adc[10][2] = fvme4_5[20][2][1]; // Dead Crystal
        adc[10][3] = fvme4_5[20][3][0];
        adc[10][4] = fvme4_5[21][0][0];
        adc[10][5] = fvme4_5[21][1][0];
        adc[10][6] = fvme4_5[21][2][0];

        // Cluster N (12)
        adc[11][0] = fvme4_5[22][0][0];
        adc[11][1] = fvme4_5[22][1][0];
        adc[11][2] = fvme4_5[22][2][0];
        adc[11][3] = fvme4_5[22][3][0];
        adc[11][4] = fvme4_5[23][0][0];
        adc[11][5] = fvme4_5[23][1][0];
        adc[11][6] = fvme4_5[23][2][0];

        // DGF Time
        // Cluster A (1)
        dgf[0][0] = fvme4_5[0][0][1];
        dgf[0][1] = fvme4_5[0][1][1];
        dgf[0][2] = fvme4_5[0][2][1];
        dgf[0][3] = fvme4_5[0][3][1];
        dgf[0][4] = fvme4_5[1][0][1];
        dgf[0][5] = fvme4_5[1][1][1];
        dgf[0][6] = fvme4_5[1][2][1];

        dgf[1][0] = fvme4_5[2][0][1];
        dgf[1][1] = fvme4_5[2][1][1];
        dgf[1][2] = fvme4_5[2][2][1];
        dgf[1][3] = fvme4_5[2][3][1];
        dgf[1][4] = fvme4_5[3][0][1];
        dgf[1][5] = fvme4_5[3][1][1];
        dgf[1][6] = fvme4_5[3][2][1];

        dgf[2][0] = fvme4_5[4][0][1];
        dgf[2][1] = fvme4_5[4][1][1];
        dgf[2][2] = fvme4_5[4][2][1];
        dgf[2][3] = fvme4_5[4][3][1];
        dgf[2][4] = fvme4_5[5][0][1];
        dgf[2][5] = fvme4_5[5][1][1];
        dgf[2][6] = fvme4_5[5][2][1];

        dgf[3][0] = fvme4_5[1][3][1];
        dgf[3][1] = fvme4_5[6][1][1];
        dgf[3][2] = fvme4_5[6][2][1];
        dgf[3][3] = fvme4_5[6][3][1];
        dgf[3][4] = fvme4_5[7][0][1];
        dgf[3][5] = fvme4_5[7][1][1];
        dgf[3][6] = fvme4_5[5][3][1];

        dgf[4][0] = fvme4_5[8][0][1];
        dgf[4][1] = fvme4_5[8][1][1];
        dgf[4][2] = fvme4_5[8][2][1];
        dgf[4][3] = fvme4_5[8][3][1];
        dgf[4][4] = fvme4_5[9][0][1];
        dgf[4][5] = fvme4_5[9][1][1];
        dgf[4][6] = fvme4_5[9][2][1];

        dgf[5][0] = fvme4_5[10][0][1];
        dgf[5][1] = fvme4_5[10][1][1];
        dgf[5][2] = fvme4_5[10][2][1];
        dgf[5][3] = fvme4_5[10][3][1];
        dgf[5][4] = fvme4_5[11][0][1];
        dgf[5][5] = fvme4_5[11][1][1];
        dgf[5][6] = fvme4_5[11][2][1];

        dgf[6][0] = fvme4_5[12][0][1];
        dgf[6][1] = fvme4_5[12][1][1];
        dgf[6][2] = fvme4_5[12][2][1];
        dgf[6][3] = fvme4_5[12][3][1];
        dgf[6][4] = fvme4_5[13][0][1];
        dgf[6][5] = fvme4_5[13][1][1];
        dgf[6][6] = fvme4_5[13][2][1];

        dgf[7][0] = fvme4_5[14][0][1];
        dgf[7][1] = fvme4_5[14][1][1];
        dgf[7][2] = fvme4_5[14][2][1];
        dgf[7][3] = fvme4_5[14][3][1];
        dgf[7][4] = fvme4_5[15][0][1];
        dgf[7][5] = fvme4_5[15][1][1];
        dgf[7][6] = fvme4_5[15][2][1];

        dgf[8][0] = fvme4_5[16][0][1];
        dgf[8][1] = fvme4_5[16][1][1];
        dgf[8][2] = fvme4_5[16][2][1];
        dgf[8][3] = fvme4_5[16][3][1];
        dgf[8][4] = fvme4_5[17][0][1];
        dgf[8][5] = fvme4_5[17][1][1];
        dgf[8][6] = fvme4_5[9][3][1];

        dgf[9][0] = fvme4_5[18][0][1];
        dgf[9][1] = fvme4_5[18][1][1];
        dgf[9][2] = fvme4_5[18][2][1];
        dgf[9][3] = fvme4_5[18][3][1];
        dgf[9][4] = fvme4_5[19][0][1];
        dgf[9][5] = fvme4_5[19][1][1];
        dgf[9][6] = fvme4_5[19][2][1];

        dgf[10][0] = fvme4_5[20][0][1];
        dgf[10][1] = fvme4_5[20][1][1];
        dgf[10][2] = fvme4_5[20][2][1];
        dgf[10][3] = fvme4_5[20][3][1];
        dgf[10][4] = fvme4_5[21][0][1];
        dgf[10][5] = fvme4_5[21][1][1];
        dgf[10][6] = fvme4_5[21][2][1];

        dgf[11][0] = fvme4_5[22][0][1];
        dgf[11][1] = fvme4_5[22][1][1];
        dgf[11][2] = fvme4_5[22][2][1];
        dgf[11][3] = fvme4_5[22][3][1];
        dgf[11][4] = fvme4_5[23][0][1];
        dgf[11][5] = fvme4_5[23][1][1];
        dgf[11][6] = fvme4_5[23][2][1];

        for (int i_det = 0; i_det < kNDetector; i_det++)
        {
            for (int i_cry = 0; i_cry < kNCrystal; i_cry++)
            {
                if (adc[i_det][i_cry] > 0)
                {
                    if (dgf[i_det][i_cry] > 0 && fvme4_5[7][3][1] > 0)
                    {
                        auto hit = new ClusterHitData();
                        hit->det_id_ = i_det;
                        hit->crystal_id_ = i_cry;
                        hit->energy_ = adc[i_det][i_cry];
                        hit->time_ = dgf[i_det][i_cry] - fvme4_5[7][3][1];
                        output_data_.singles_.emplace_back(hit);
                    }
                }
            }
        }

        // Cluster calibration
        for (const auto &hit : output_data_.singles_)
        {
            hit->energy_ = calib_ge_e_->GCalib(kNCrystal * hit->det_id_ + hit->crystal_id_, hit->energy_);
            hit->time_ = calib_ge_t_->GCalib(kNCrystal * hit->det_id_ + hit->crystal_id_, hit->time_);
            hit->time_ = slew_ge_->SlewCorrect(kNCrystal * hit->det_id_ + hit->crystal_id_, hit->time_, hit->energy_);
        }
    }

    // Mapping Labr
    {
        Int_t adc[18];
        Int_t stdc[18];

        // Energy
        // Cluster A (1)
        adc[0] = vme1_2_[30];
        adc[1] = vme1_2_[26];
        adc[2] = vme1_2_[2];
        adc[3] = vme1_2_[3];
        adc[4] = vme1_2_[4];
        adc[5] = vme1_2_[27];

        // Cluster B (2)
        adc[6] = vme1_2_[28];
        adc[7] = vme1_2_[7];
        adc[8] = vme1_2_[8];
        adc[9] = vme1_2_[9];
        adc[10] = vme1_2_[10];
        adc[11] = vme1_2_[11];

        // Cluster C (3)
        adc[12] = vme1_2_[12];
        adc[13] = vme1_2_[13];
        adc[14] = vme1_2_[14];
        adc[15] = vme1_2_[15];
        adc[16] = vme1_2_[31];
        adc[17] = vme1_2_[17];

        // STDC time
        // Cluster A
        stdc[0] = vme6_[3 * 32 + 0];
        stdc[1] = vme6_[3 * 32 + 1];
        stdc[2] = vme6_[3 * 32 + 2];
        stdc[3] = vme6_[3 * 32 + 3];
        stdc[4] = vme6_[3 * 32 + 4];
        stdc[5] = vme6_[3 * 32 + 5];

        // Cluster B
        stdc[6] = vme6_[3 * 32 + 6];
        stdc[7] = vme6_[3 * 32 + 7];
        stdc[8] = vme6_[3 * 32 + 8];
        stdc[9] = vme6_[3 * 32 + 9];
        stdc[10] = vme6_[3 * 32 + 10];
        stdc[11] = vme6_[3 * 32 + 11];

        // Cluster C
        stdc[12] = vme6_[3 * 32 + 12];
        stdc[13] = vme6_[3 * 32 + 13];
        stdc[14] = vme6_[3 * 32 + 14];
        stdc[15] = vme6_[3 * 32 + 15];
        stdc[16] = vme6_[3 * 32 + 16];
        stdc[17] = vme6_[3 * 32 + 17];

        for (int i_ch = 0; i_ch < kNLabr; ++i_ch)
        {
            if (adc[i_ch] > 0 && adc[i_ch] < 65535)
            {
                auto hit = new ClusterHitData();
                hit->crystal_id_ = 0;
                hit->det_id_ = i_ch;
                hit->energy_ = adc[i_ch];
                hit->time_ = stdc[i_ch];
                output_data_.labr_.emplace_back(hit);
            }
        }

        // Calibration
        for (const auto &hit : output_data_.labr_)
        {
        }
    }

    // Beta Plastic
    {
        Int_t adc[kNBetaPL * 2];
        Int_t stdc[kNBetaPL];

        // Energy
        adc[0] = vme1_2_[29]; // UL
        adc[1] = vme1_2_[19]; // UR
        adc[2] = vme1_2_[20]; // DL
        adc[3] = vme1_2_[21]; // DR
        adc[4] = vme1_2_[22]; // UL_L
        adc[5] = vme1_2_[23]; // UR_L
        adc[6] = vme1_2_[24]; // DL_L
        adc[7] = vme1_2_[25]; // DR_L

        // STDC time
        stdc[0] = vme6_[3 * 32 + 18]; // UL
        stdc[1] = vme6_[3 * 32 + 19]; // UR
        stdc[2] = vme6_[3 * 32 + 20]; // DL
        stdc[3] = vme6_[3 * 32 + 21]; // DR

        for (int i = 0; i < kNBetaPL; ++i)
        {
            auto hit = new ClusterHitData();
            hit->energy_ = adc[i];
            hit->time_ = stdc[i];
            hit->det_id_ = i;
            hit->crystal_id_ = 0;
        }
    }
    output_data_.ts_ = ts_[0];
    output_data_.evtnumber_ = evtnumber_[0];
    output_data_.runnumber_ = runnumber_[0];

    // Fill the tree and the histogram
    fOutputTree->Fill();

    return kTRUE;
}

void eurica::EuricaPreScanSelector::SlaveTerminate()
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

void eurica::EuricaPreScanSelector::Terminate()
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
