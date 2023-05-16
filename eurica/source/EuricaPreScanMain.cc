/**
 * @file EuricaPreScanMain.cc
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief
 * @version 0.1
 * @date 2023-05-12
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <unistd.h>
#include "TROOT.h"
#include "TChain.h"
#include "TProof.h"
#include "TParameter.h"
#include "EuricaPreScanSelector.h"
#include "LibraryConfig.h"

// A flag to descide whether to use PROOF
// kTRUE : use PROOF, kFALSE : run locally
const Bool_t kUseProof = kFALSE;

// A flag for merging output tree at the end of the process when you use PROOF
// kTRUE: merge output tree at the end, kFALSE: merge only histograms
//	Each process creates a file under the folder named as its ordinal number.
// Merging these files at the end takes considerable amount of time and disk space
// when the size of the output tree is very large.
// In such cases, you might want to set this flag to false and just chain the output files.
// ********************************************************************************************
// *** You need to give an absolute path to the output file when you set this flag to false ***
// *** otherwise worker outputs will be written under .proof directory under your $HOME     ***
// ********************************************************************************************
const Bool_t kMergeTree = kTRUE;

// The number of processes to run
const UInt_t kNWorkers = 2U;

// CalibFileName
const std::string kConfigGeE = "/home/ryokoyam/data/eurica/prm/ge_ecal_15.prm";
const std::string kConfigGeT = "/home/ryokoyam/data/eurica/prm/ge_stcal.prm";
const std::string kConfigLabrE = "/home/ryokoyam/data/eurica/prm/labr_ecal.prm";
const std::string kConfigLabrT = "/home/ryokoyam/data/eurica/prm/labr_tcal.prm";
const std::string kConfigGeSlew = "/home/ryokoyam/data/eurica/prm/ge_slew.prm";
const std::string kConfigLabrSlew = "/home/ryokoyam/data/eurica/prm/labr_slew.prm";

/** prints usage **/
void usage(char *argv0)
{
    std::cout << "[EuricaPreScanMain]: Usage: "
              << argv0 << "-i [input_file] -o [output_file] -c [pid_file]"
              << std::endl;
}

int main(int argc, char **argv)
{

    std::string config_file_name;
    std::string input_file_name;
    std::string output_file_name;

    /** parsing commandline arguments **/
    int opt = 0;
    while ((opt = getopt(argc, argv, "i:o:c:")) != -1)
    {
        switch (opt)
        {
        case 'i':
            input_file_name = optarg;
            break;
        case 'o':
            output_file_name = optarg;
            break;
        case 'c':
            config_file_name = optarg;
            break;
        default:
            usage(argv[0]);
            return 1;
            break;
        }
    }

    // Switch to the batch mode.
    gROOT->SetBatch();

    // Create a TChain from the files generated by FillGauss
    TChain *chain = new TChain("tree");
    chain->Add(input_file_name.c_str());

    if (kUseProof)
    {
        // Open a PROOF lite session.
        auto proof = TProof::Open("lite://", Form("workers=%u", kNWorkers));

        // Load shared libraries to the PROOF server.
        {
            const std::string lib_name = getDataLibDir() + "libBetaGammaCore.so";
            proof->Load(lib_name.c_str());
        }
        {
            const std::string lib_name = getDataLibDir() + "libEurica.so";
            proof->Load(lib_name.c_str());
        }

        // Set Proof to the chain you want to analyze.
        chain->SetProof();
        // If you want to pass parameters or strings to the PROOF processes, use AddInput().
        // The list of input objects will be accessible from the fInput pointer of the TSelector object.
        proof->AddInput(new TNamed("OutputFileName", output_file_name));
        proof->AddInput(new TNamed("GeEFileName", kConfigGeE));
        proof->AddInput(new TNamed("GeTFileName", kConfigGeT));
        proof->AddInput(new TNamed("LabrEFileName", kConfigLabrE));
        proof->AddInput(new TNamed("LabrTFileName", kConfigLabrT));
        proof->AddInput(new TNamed("GeSlewFileName", kConfigGeSlew));
        proof->AddInput(new TNamed("LabrSlewFileName", kConfigLabrSlew));
        proof->AddInput(new TParameter<Bool_t>("MergeTree", kMergeTree));

        // Start processing.
        chain->Process("eurica::EuricaPreScanSelector");
    }
    else
    {
        // When you don't use PROOF, create a TSelector instance, set parameters you need and run.
        auto selector = new eurica::EuricaPreScanSelector(chain);
        selector->SetOutputFileName(output_file_name);
        selector->SetGeEFileName(kConfigGeE);
        selector->SetGeTFileName(kConfigGeT);
        selector->SetLabrEFileName(kConfigLabrE);
        selector->SetLabrTFileName(kConfigLabrT);
        selector->SetGeSlewFileName(kConfigGeSlew);
        selector->SetLabrSlewFileName(kConfigLabrSlew);
        chain->Process(selector);
        delete selector;
    }

    delete chain;

    return 0;
}