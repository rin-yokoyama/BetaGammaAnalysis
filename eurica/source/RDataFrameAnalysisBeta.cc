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
    // Enable multithreading
    ROOT::EnableImplicitMT(n_workers);

    YamlParameter::Create(config_file_name);
    YamlReader yaml_reader("RDataFrameAnalysisBeta");
    std::vector<std::string> files = yaml_reader.GetStringVec("InputFiles");

    // Create RDataFrame from a tree, "exampleTree" in the "example.root" file.
    ROOT::RDataFrame d("OutputTree", files);

    // Function to define Tbeta - Timplant
    const auto tibFunction = [](const eurica::BetaData &input)
    {
        const auto &implant_vec = input.output_vec_;
        std::vector<eurica::ImplantData> gatedImplants;

        // Custom cut
        const Int_t pid = 7;
        const auto customCut = [&pid](const eurica::ImplantData &input)
        {
            return input.output_vec_.at(0).pid_ == pid;
        };

        std::copy_if(implant_vec.begin(), implant_vec.end(), std::back_inserter(gatedImplants), customCut);
        std::vector<Double_t> tib_vec;
        for (const auto &implant : gatedImplants)
        {
            tib_vec.emplace_back(input.input_.input_.input_.ts_ - implant.input_.input_.ts_);
        }
        return tib_vec; // Retern vector of Tbeta - Timplant
    };

    // Function to define gamma hits
    const auto geEFunction = [](const eurica::BetaData &input)
    {
        const auto &gamma_vec = input.input_.input_.output_vec_;
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

    // Process tree
    auto output = d.Define("Tib", tibFunction, {"Beta"}).Define("geE", geEFunction, {"Beta"});

    // Fill the histogram
    // If you want to plot a value in your class, you need to first Define()
    // a column with the value then Histo1D().
    // A lambda function is used to return Double_t value of the output branch.
    // Histogram definition is {"name","title",nbin,low,up} or simply "name"
    // for auto filling. (no auto filling when multithreading)
    auto hist1d = output.Histo1D({"Tib", "Tib", 1000, -1E+9, 1E+9}, "Tib");
    auto hist2d = output.Histo2D({"Tib_vs_geE", "Tib_vs_geE", 1000, -1E+9, 1E+9, 2000, 0, 2000}, "Tib", "geE");

    TFile output_file(output_file_name.c_str(), "RECREATE");
    hist1d->Write();
    hist2d->Write();
    output_file.Close();
    return 0;
}