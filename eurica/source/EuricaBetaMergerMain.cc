/**
 * @file EuricaBetaMergerMain.cc
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief
 * @version 0.1
 * @date 2023-05-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include "OutputTreeData.hpp"
#include "YamlParameter.hpp"
#include "EuricaBetaTreeMerger.h"
#include "EuricaImplantTSScanner.h"
#include "EuricaBetaTSScanner.h"

/** prints usage **/
void usage(char *argv0)
{
    std::cout << "[MergerMain]: Usage: "
              << argv0 << "-c [configuration_file_name]"
              << std::endl;
}

int main(int argc, char **argv)
{
    std::string input_file_name;
    std::string config_file_name;
    std::string output_file_name;

    /** parsing commandline arguments **/
    if (argc != 3)
    {
        usage(argv[0]);
        return 1;
    }
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

    try
    {
        /** creates YamlParameter instance **/
        YamlParameter::Create(config_file_name);

        /** merges implant events to beta events **/
        {
            std::cout << "[MergerMain]: merging implant events to beta events..." << std::endl;

            /** timestamp scanors **/
            eurica::ImplantTSScanner implant_ts_scanner;
            eurica::BetaTSScanner beta_ts_scanner;

            /** configures timestamp scannors with the yaml file **/
            implant_ts_scanner.Configure("ImplantTSScanner");
            beta_ts_scanner.Configure("BetaTSScanner");

            /** sets TTreeReaderValue objects **/
            implant_ts_scanner.SetReader();
            beta_ts_scanner.SetReader();

            /** scans timestamps through the tree **/
            std::cout << "[MergerMain]: scanning implant events..." << std::endl;
            implant_ts_scanner.Scan();
            std::cout << "[MergerMain]: scanning beta events..." << std::endl;
            beta_ts_scanner.Scan();

            std::cout << "[MergerMain]: Implant map size: " << implant_ts_scanner.GetIEntryMap().size() << std::endl;
            std::cout << "[MergerMain]: Beta map size: " << beta_ts_scanner.GetIEntryMap().size() << std::endl;

            /** runs merger **/
            eurica::BetaTreeMerger beta_merger(&beta_ts_scanner, &implant_ts_scanner);
            beta_merger.Configure("BetaTreeMerger");
            beta_merger.Merge();
            beta_merger.Write();

            std::cout << std::endl;
            std::cout << std::endl;
        }

        /** destroys YamlParameter instance **/
        // YamlParameter::Destroy();
    }
    catch (std::string msg)
    {
        std::cout << msg << std::endl;
        std::cout << "[MergerMain]: exiting from main() due to the error" << std::endl;
        return 1;
    }
    catch (std::bad_alloc)
    {
        std::cout << "[MergerMain]: bad_alloc occured while setting up." << std::endl;
        std::cout << "[MergerMain]: exiting from main() due to the error" << std::endl;
        return 1;
    }

    return 0;
}