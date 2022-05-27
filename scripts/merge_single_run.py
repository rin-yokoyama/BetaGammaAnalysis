import sys
import subprocess
import argparse
import yaml

INSTALL_DIR = "/home/sh13/isomer/install/bin/"
ARTEMIS_WORK = "/home/sh13/art_analysis/user/yokoyama/"
APV009_DATA_PATH = "/mnt/data/sh13/apv/"
APV128_DATA_PATH = "/mnt/data/sh13/vega/"
APV129_DATA_PATH = "/mnt/data/sh13/vega/"
OUTPUT_DATA_PATH = "/home/sh13/rootfiles/"
YAML_FILE_PATH = "/home/sh13/isomer/work/config/"
YAML_FILE_NAME = YAML_FILE_PATH + "config.yaml"
THIS_ISOMER_PATH = "/home/sh13/isomer/install/share/thisisomer.sh"

if __name__ == '__main__':
    runnum = sys.argv[1]
    runnumge = sys.argv[2]
    runnumsh = sys.argv[3]
    RUNNAME = sys.argv[4]
    apv009_name = APV009_DATA_PATH + "apv" + runnum + ".ridf"
    apv128_name = APV128_DATA_PATH + "port5042_run" + runnum + ".bin"
    apv129_name = APV129_DATA_PATH + "port5041_run" + runnum + ".bin"

    sharaq_rootname = ARTEMIS_WORK + "output/merge/pid_" + RUNNAME + runnumsh +".root"
    apv009_rootname = ARTEMIS_WORK + "output/apv/" + runnumge + "/apvapv" + runnumge +".root"
    apv128_rootname = OUTPUT_DATA_PATH + "port5042_run" + runnum + ".root"
    apv129_rootname = OUTPUT_DATA_PATH + "port5041_run" + runnum + ".root"

    # Decode rawdata
    procs = []
    cmd = "source " + THIS_ISOMER_PATH + "; cd " + ARTEMIS_WORK + "; " + ARTEMIS_WORK + "build/run_artemis " + ARTEMIS_WORK+"steering/chkdaq.yaml apv " + runnumge
    print(cmd)
    procs.append(subprocess.Popen([cmd],shell=True))
    cmd = "source " + THIS_ISOMER_PATH + "; cd " + ARTEMIS_WORK + "; " + ARTEMIS_WORK + "build/run_artemis " + ARTEMIS_WORK+"steering/merge.yaml " + RUNNAME + " " + runnumsh
    print(cmd)
    procs.append(subprocess.Popen([cmd],shell=True))
    cmd = "source " + THIS_ISOMER_PATH +"; " + INSTALL_DIR + "apv_decoder -i " + apv128_name + " -o " + apv128_rootname
    print(cmd)
    procs.append(subprocess.Popen([cmd],shell=True))
    cmd = "source " + THIS_ISOMER_PATH + "; " + INSTALL_DIR + "apv_decoder -i " + apv129_name + " -o " + apv129_rootname
    print(cmd)
    procs.append(subprocess.Popen([cmd],shell=True))

    for proc in procs:
        proc.communicate()

    # Event build
    S2PLUS_OUTPUT = OUTPUT_DATA_PATH + "s2plus_apv" + runnum + "_sh" + runnumge + ".root"
    MERGED_OUTPUT = OUTPUT_DATA_PATH + "merged_apv" + runnum + "_ge" + runnumge + "_sh" + runnumsh +".root"
    yaml_file = open(YAML_FILE_NAME)
    yaml_data = yaml.safe_load(yaml_file) 
    yaml_file.close()
    yaml_data["SH13EventBuilderConfig"]["EventLoaders"]["APV8008Loader"]["FileNames"][0] = apv009_rootname
    yaml_data["SH13EventBuilderConfig"]["EventLoaders"]["APV8104Loader"]["FileNames"][0] = apv128_rootname
    yaml_data["SH13EventBuilderConfig"]["EventLoaders"]["APV8508Loader"]["FileNames"][0] = apv129_rootname
    yaml_data["SH13EventBuilderConfig"]["OutputFileName"] = S2PLUS_OUTPUT
    yaml_data["SH13PIDTSScanner"]["InputFileName"] = sharaq_rootname
    yaml_data["S2PlusTSScanner"]["InputFileName"] = S2PLUS_OUTPUT
    yaml_data["S2PlusTSScanner"]["InputFileName"] = S2PLUS_OUTPUT
    yaml_data["Merger"]["OutputFileName"] = MERGED_OUTPUT
    config_file_name = YAML_FILE_PATH+"config_apv"+runnum+".yaml"
    output_yaml_file = open(config_file_name,'w')
    output_yaml_file.write(yaml.dump(yaml_data,default_flow_style=False))

    cmd = "source " + THIS_ISOMER_PATH +"; " + INSTALL_DIR + "evtbuilder -c " + config_file_name
    print(cmd)
    #subprocess.call([cmd], shell=True)

    # Event merge
    cmd = "source " + THIS_ISOMER_PATH +"; " + INSTALL_DIR + "merger -c " + config_file_name
    print(cmd)
    #subprocess.call([cmd], shell=True)