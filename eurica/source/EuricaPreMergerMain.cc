/**
 * @file EuricaPreMergerMain.cc
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
#include "TreeMerger.hpp"
#include "EuricaTSScanner.h"
#include "EuricaWasabiTSScanner.h"
#include "EuricaBigRIPSTSScanner.h"
#include "EuricaWasabiMergedTSScanner.h"

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

        /** merges Eurica events to Wasabi events **/
        {
            std::cout << "[MergerMain]: merging Eurica events to Wasabi events..." << std::endl;

            /** timestamp scanors **/
            eurica::EuricaTSScanner eurica_ts_scanner;
            eurica::WasabiTSScanner wasabi_ts_scanner;

            /** configures timestamp scannors with the yaml file **/
            eurica_ts_scanner.Configure("EuricaTSScanner");
            wasabi_ts_scanner.Configure("WasabiTSScanner");

            /** sets TTreeReaderValue objects **/
            eurica_ts_scanner.SetReader();
            wasabi_ts_scanner.SetReader();

            /** scans timestamps through the tree **/
            std::cout << "[MergerMain]: scanning Eurica events..." << std::endl;
            eurica_ts_scanner.Scan();
            std::cout << "[MergerMain]: scanning Wasabi events..." << std::endl;
            wasabi_ts_scanner.Scan();

            std::cout << "[MergerMain]: Eurica map size: " << eurica_ts_scanner.GetIEntryMap().size() << std::endl;
            std::cout << "[MergerMain]: Wasabi map size: " << wasabi_ts_scanner.GetIEntryMap().size() << std::endl;

            /** runs merger **/
            TreeMerger<eurica::EuricaWasabiData, eurica::WasabiData, eurica::ClusterData> eurica_wasabi_merger(&wasabi_ts_scanner, &eurica_ts_scanner);
            eurica_wasabi_merger.Configure("EuricaWasabiMerger");
            eurica_wasabi_merger.Merge();
            eurica_wasabi_merger.Write();

            std::cout << std::endl;
            std::cout << std::endl;
        }

        /** merges eurica events to bigrips events **/
        {
            std::cout << "[MergerMain]: merging eurica events to bigrips events..." << std::endl;
            /** timestamp scanors **/
            eurica::WasabiMergedTSScanner merged_ts_scannor;
            eurica::BigRIPSTSScanner bigrips_ts_scannor;

            /** configures timestamp scannors with the yaml file **/
            merged_ts_scannor.Configure("WasabiMergedTSScanner");
            bigrips_ts_scannor.Configure("BigRIPSTSScanner");

            /** sets TTreeReaderValue objects **/
            merged_ts_scannor.SetReader();
            bigrips_ts_scannor.SetReader();

            /** scans timestamps through the tree **/
            std::cout << "[MergerMain]: scanning eurica-wasabi-merged events..." << std::endl;
            merged_ts_scannor.Scan();
            std::cout << "[MergerMain]: scanning BigRIPS events..." << std::endl;
            bigrips_ts_scannor.Scan();

            std::cout << "[MergerMain]: Merged map size: " << merged_ts_scannor.GetIEntryMap().size() << std::endl;
            std::cout << "[MergerMain]: BigRIPS map size: " << bigrips_ts_scannor.GetIEntryMap().size() << std::endl;

            /** runs merger **/
            TreeMerger<eurica::ImplantData, eurica::BigRIPSData, eurica::EuricaWasabiData> merger(&bigrips_ts_scannor, &merged_ts_scannor);
            merger.Configure("ImplantMerger");
            merger.Merge();
            merger.Write();
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