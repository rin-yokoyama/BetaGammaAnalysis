#include <iostream>
#include <unistd.h>
#include "YamlReader.hpp"
#include "S2PlusTSScanner.h"
#include "SH13PIDTSScanner.h"
#include "OutputTreeData.hpp"
#include "TreeMerger.hpp"
#include "TMergerData.h"

/** prints usage **/
void usage(char *argv0)
{
    std::cout << "[SH13MergerMain]: Usage: "
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
    /** merges S2+ events to sharaq events **/
    {
        std::cout << "[MergerMain]: merging BigRIPS events to implants events..." << std::endl;

        /** timestamp scanors **/
        SH13PIDTSScanner sharaq_ts_scanner;
        S2PlusTSScanner s2plus_ts_scanner;

        /** configures timestamp scannors with the yaml file **/
        sharaq_ts_scanner.Configure("SH13PIDTSScannor");
        s2plus_ts_scanner.Configure("S2PlusTSScannor");

        /** sets TTreeReaderValue objects **/
        sharaq_ts_scanner.SetReader();
        s2plus_ts_scanner.SetReader();

        /** scans timestamps through the tree **/
        std::cout << "[MergerMain]: scanning SHARAQ events..." << std::endl;
        sharaq_ts_scanner.Scan();
        std::cout << "[MergerMain]: scanning S2+ events..." << std::endl;
        s2plus_ts_scanner.Scan();

        std::cout << "[MergerMain]: SHARAQ map size: " << sharaq_ts_scanner.GetIEntryMap().size() << std::endl;
        std::cout << "[MergerMain]: S2+ map size: " << s2plus_ts_scanner.GetIEntryMap().size() << std::endl;

        /** runs merger **/
        TreeMerger<OutputTreeData<ULong64_t, SH13S2PlusData>, ULong64_t, SH13S2PlusData> merger(&sharaq_ts_scanner, &s2plus_ts_scanner);
        merger.Configure("TreeMerger");
        merger.Merge();
        merger.Write();
    }
    std::cout << "[SH13MergerMain]: Main loop done." << std::endl;
    return 0;
}