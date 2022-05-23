cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(DAMerger)

# ROOT 6 installation
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

# Default installation dir
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install/ CACHE PATH "install dir" FORCE)

#---Locate the ROOT package and defines a number of variables (e.g. ROOT_INCLUDE_DIRS)
find_package(ROOT REQUIRED COMPONENTS RIO Net Proof Minuit Physics)
#---Define useful ROOT functions and macros (e.g. ROOT_GENERATE_DICTIONARY)
include(${ROOT_USE_FILE})

set(YAML_CPP_PATH /home/sh13/local/yaml-cpp CACHE PATH "path to yaml-cpp installation dir" FORCE)
#find_package(yaml-cpp)

find_package(Threads)

set(ARTEMIS_PATH /opt/local/artemis CACHE PATH "path to artemis install" FORCE)
set(ARTEMIS_OEDO_PATH /home/sh13/art_analysis/user/okawa/src-oedo CACHE PATH "path to artemis src-oedo" FORCE)

include_directories(${YAML_CPP_PATH}/include)
#include_directories(${YAML_CPP_INCLUDE_DIR})
include_directories(${ARTEMIS_PATH}/include)
include_directories(${ARTEMIS_OEDO_PATH})
include_directories(core/include)
include_directories(decoder/include)
include_directories(data/include)
link_directories(${ROOTSYS}/lib)
#link_directories(${YAML_CPP_LIB_DIR})
link_directories(${YAML_CPP_PATH}/lib64)
link_directories(${ARTEMIS_PATH}/lib)
link_directories(${ARTEMIS_OEDO_PATH})

add_subdirectory(data)
add_subdirectory(core)
add_subdirectory(decoder)
add_subdirectory(evtbuilder)
add_subdirectory(share)