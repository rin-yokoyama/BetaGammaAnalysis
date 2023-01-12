#include <iostream>
#include <unistd.h>
#include "SH13TreeEventBuilder.h"
#include "YamlReader.hpp"

/** prints usage **/
void usage(char *argv0)
{
	std::cout << "[SH13EventBuilderMain]: Usage: "
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
	while ((opt = getopt(argc, argv, "i:o:c:")) != -1) {
      switch (opt) {
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

	SH13TreeEventBuilder event_builder;
	event_builder.Configure("SH13EventBuilderConfig");
	event_builder.Loop();

	std::cout << "[SH13EventBuilderMain]: Main loop done." << std::endl;
	return 0;
}