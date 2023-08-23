// RDataFrameAnalysis.cpp created by Rin Yokoyama on \date April 18, 2023
// This program generates root files with a tree containing a branch of the ExampleTwoDataClass.
// named "ExampleData". ExampleData.data1_ and data2_ will be filled with random Gaussian events.
#include <iostream>
#include "TROOT.h"
#include "ROOT/RDataFrame.hxx"
#include "EuricaMergerData.hpp"
#include "YamlParameter.hpp"
#include "YamlReader.hpp"

/** prints usage **/
void usage(char *argv0)
{
    std::cout << "[RDataFrameAnalysis]: Usage: "
              << argv0 << "-c [config_file] -n [n_workers] -o [output_file]"
              << std::endl;
}

// Main function
int main(int argc, char **argv)
{
    std::string config_file_name;
    std::string output_file_name = "output.root";
    Int_t n_workers = 1;

    /** parsing commandline arguments **/
    int opt = 0;
    while ((opt = getopt(argc, argv, "o:n:c:")) != -1)
    {
        switch (opt)
        {
        case 'o':
            output_file_name = optarg;
            break;
        case 'n':
            n_workers = std::stoi(optarg);
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
    YamlParameter::Create(config_file_name);
    YamlReader yaml_reader("RDataFrameAnalysisImplant");
    std::vector<std::string> files = yaml_reader.GetStringVec("InputFiles");
    n_workers = yaml_reader.GetULong64("NWorkers");

    // Enable multithreading
    ROOT::EnableImplicitMT(n_workers);

    // Create RDataFrame from a tree, "exampleTree" in the "example.root" file.
    ROOT::RDataFrame d("OutputTree", files);

    output_file_name = yaml_reader.GetString("OutputFile", false, output_file_name);

    // Function to gate on implant events
    const auto implantGate = [](const eurica::ImplantData &input)
    {
        return !input.output_vec_.empty();
    };

    // Function to define A/Q
    const auto aoq = [](const eurica::ImplantData &input)
    {
        return input.output_vec_.at(0).aoq_;
    };

    // Function to define Z
    const auto zet = [](const eurica::ImplantData &input)
    {
        return input.output_vec_.at(0).zet_;
    };

    // Function to define pid gate
    const auto pid = [](const eurica::ImplantData &input)
    {
        return input.output_vec_.at(0).pid_;
    };

    // Function to define gamma E
    const auto geEFunction = [](const eurica::ImplantData &input)
    {
        const auto &gamma_vec = input.input_.output_vec_;
        std::vector<Double_t> gammaE_vec;
        for (const auto &gamma : gamma_vec)
        {
            for (const auto &single : gamma.singles_)
            {
                gammaE_vec.emplace_back(single.energy_);
            }
        }
        return gammaE_vec;
    };

    // Function to define gamma T
    const auto geTFunction = [](const eurica::ImplantData &input)
    {
        const auto &gamma_vec = input.input_.output_vec_;
        std::vector<Double_t> gammaT_vec;
        for (const auto &gamma : gamma_vec)
        {
            for (const auto &single : gamma.singles_)
            {
                gammaT_vec.emplace_back(single.time_);
            }
        }
        return gammaT_vec;
    };

    // Function to define crystalId
    const auto geCrystalIdFunction = [](const eurica::ImplantData &input)
    {
        const auto &gamma_vec = input.input_.output_vec_;
        std::vector<Int_t> gammaCrystalId_vec;
        for (const auto &gamma : gamma_vec)
        {
            for (const auto &single : gamma.singles_)
            {
                gammaCrystalId_vec.emplace_back(single.crystal_id_);
            }
        }
        return gammaCrystalId_vec;
    };

    // Function to define detectorId
    const auto geDetectorIdFunction = [](const eurica::ImplantData &input)
    {
        const auto &gamma_vec = input.input_.output_vec_;
        std::vector<Int_t> gammaDetectorId_vec;
        for (const auto &gamma : gamma_vec)
        {
            for (const auto &single : gamma.singles_)
            {
                gammaDetectorId_vec.emplace_back(single.det_id_);
            }
        }
        return gammaDetectorId_vec;
    };

    // Process tree
    auto output = d.Filter(implantGate, {"Implant"})
                      .Define("aoq", aoq, {"Implant"})
                      .Define("zet", zet, {"Implant"})
                      .Define("pid", pid, {"Implant"})
                      .Define("geE", geEFunction, {"Implant"})
                      .Define("geT", geTFunction, {"Implant"})
                      .Define("geCrystal", geCrystalIdFunction, {"Implant"})
                      .Define("geDetector", geDetectorIdFunction, {"Implant"});

    // save new branches to output_file_name tree
    output.Snapshot("tree", output_file_name, {"aoq", "zet", "pid", "geE", "geT", "geCrystal", "geDetector"});

    // Fill the histogram
    auto hist_pid = output.Histo2D({"PID", "PID", 200, 2.5, 2.8, 200, 40, 65}, "aoq", "zet");

    // Gamma-Gamma histograms
    TH2F hGG("gg", "gg", 3000, 0, 3000, 3000, 0, 3000);
    // Function to fill a gamma-gamma histogram
    const auto fillGammaGammaFunction = [&hGG](const eurica::ImplantData &input)
    {
        const auto &gamma_vec = input.input_.output_vec_;
        for (const auto &gamma : gamma_vec)
        {
            const auto &singles = gamma.singles_;
            for (const auto &hit1 : singles)
            {
                for (const auto &hit2 : singles)
                {
                    if (hit1.det_id_ == hit2.det_id_)
                        continue;
                    hGG.Fill(hit1.energy_, hit2.energy_);
                }
            }
        }
        return;
    };
    output.Foreach(fillGammaGammaFunction, {"Implant"});

    TFile output_file(output_file_name.c_str(), "UPDATE");
    hist_pid->Write();
    hGG.Write();
    output_file.Close();
    return 0;
}