#include <iostream>
#include <unistd.h>
#include "YamlReader.hpp"
#include "EuricaWasabiTSScanner.h"
#include "EuricaTSScanner.h"
#include "EuricaBigRIPSTSScanner.h"
#include "EuricaWasabiDataTSScanner.h"
#include "EuricaImplantTSScanner.h"
#include "EuricaBetaTSScanner.h"
#include "OutputTreeData.hpp"
#include "TreeMerger.hpp"
#include "EuricaBetaTreeMerger.h"
#include "EuricaMergerData.hpp"

/** prints usage **/
void usage(char *argv0)
{
    std::cout << "[EuricaMergerMain]: Usage: "
              << argv0 << "-c [config file]"
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
    YamlParameter::Create(config_file_name);
    /** merge eurica events to wasabi events **/
    {
        std::cout << "[MergerMain]: merging EURICA events to WAS3ABi events..." << std::endl;

        /** timestamp scanors **/
        eurica::WasabiTSScanner wasabi_ts_scanner;
        eurica::EuricaTSScanner eurica_ts_scanner;

        /** configures timestamp scannors with the yaml file **/
        wasabi_ts_scanner.Configure("WasabiTSScannor");
        eurica_ts_scanner.Configure("EuricaTSScannor");

        /** sets TTreeReaderValue objects **/
        wasabi_ts_scanner.SetReader();
        eurica_ts_scanner.SetReader();

        /** scans timestamps through the tree **/
        std::cout << "[MergerMain]: scanning WAS3ABi events..." << std::endl;
        wasabi_ts_scanner.Scan();
        std::cout << "[MergerMain]: scanning EURICA events..." << std::endl;
        eurica_ts_scanner.Scan();

        std::cout << "[MergerMain]: WAS3ABi map size: " << wasabi_ts_scanner.GetIEntryMap().size() << std::endl;
        std::cout << "[MergerMain]: EURICA map size: " << eurica_ts_scanner.GetIEntryMap().size() << std::endl;

        /** runs merger **/
        TreeMerger<eurica::WasabiData, eurica::Data_wasabi, eurica::Data_eurica> merger(&wasabi_ts_scanner, &eurica_ts_scanner);
        merger.Configure("WasabiEuricaTreeMerger");
        merger.Merge();
        merger.Write();
    }

    /** merge bigrips events to wasabi events **/
    {
        std::cout << "[MergerMain]: merging BigRIPS events to WAS3ABi events..." << std::endl;

        /** timestamp scanors **/
        eurica::WasabiDataTSScanner wasabi_ts_scanner;
        eurica::BigRIPSTSScanner bigrips_ts_scanner;

        /** configures timestamp scannors with the yaml file **/
        wasabi_ts_scanner.Configure("WasabiDataTSScannor");
        bigrips_ts_scanner.Configure("BigRIPSTSScannor");

        /** sets TTreeReaderValue objects **/
        wasabi_ts_scanner.SetReader();
        bigrips_ts_scanner.SetReader();

        /** scans timestamps through the tree **/
        std::cout << "[MergerMain]: scanning WAS3ABi events..." << std::endl;
        wasabi_ts_scanner.Scan();
        std::cout << "[MergerMain]: scanning BigRIPS events..." << std::endl;
        bigrips_ts_scanner.Scan();

        std::cout << "[MergerMain]: WAS3ABi map size: " << wasabi_ts_scanner.GetIEntryMap().size() << std::endl;
        std::cout << "[MergerMain]: BigRIPS map size: " << bigrips_ts_scanner.GetIEntryMap().size() << std::endl;

        /** runs merger **/
        TreeMerger<eurica::MergedData, eurica::WasabiData, eurica::Data_bigrips> merger(&wasabi_ts_scanner, &bigrips_ts_scanner);
        merger.Configure("WasabiBigRIPSTreeMerger");
        merger.Merge();
        merger.Write();
    }
    /** merge implant events to beta events **/
    {
        std::cout << "[MergerMain]: merging Implant events to beta events..." << std::endl;

        /** timestamp scanors **/
        eurica::ImplantTSScanner implant_ts_scanner;
        eurica::BetaTSScanner beta_ts_scanner;

        /** configures timestamp scannors with the yaml file **/
        implant_ts_scanner.Configure("ImplantTSScannor");
        beta_ts_scanner.Configure("BetaTSScannor");

        /** sets TTreeReaderValue objects **/
        implant_ts_scanner.SetReader();
        beta_ts_scanner.SetReader();

        /** scans timestamps through the tree **/
        std::cout << "[MergerMain]: scanning implant events..." << std::endl;
        implant_ts_scanner.Scan();
        std::cout << "[MergerMain]: scanning beta events..." << std::endl;
        beta_ts_scanner.Scan();

        std::cout << "[MergerMain]: implant map size: " << implant_ts_scanner.GetIEntryMap().size() << std::endl;
        std::cout << "[MergerMain]: beta map size: " << beta_ts_scanner.GetIEntryMap().size() << std::endl;

        /** runs merger **/
        eurica::BetaTreeMerger merger(&beta_ts_scanner, &implant_ts_scanner);
        merger.Configure("BetaImplantTreeMerger");
        merger.Merge();
        merger.Write();
    }
    std::cout << "[MergerMain]: Main loop done." << std::endl;
    return 0;
}