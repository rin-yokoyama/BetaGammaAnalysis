cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(BetaGammaAnalysis)

# ROOT 6 installation
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

# Default installation dir
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install/ CACHE PATH "install dir" FORCE)

# work dir
set(WORK_DIR ${CMAKE_SOURCE_DIR}/work CACHE PATH "workdir" FORCE)

#---Locate the ROOT package and defines a number of variables (e.g. ROOT_INCLUDE_DIRS)
find_package(ROOT REQUIRED COMPONENTS RIO Net Proof Minuit Minuit2 Physics Genetic)
#---Define useful ROOT functions and macros (e.g. ROOT_GENERATE_DICTIONARY)
include(${ROOT_USE_FILE})

#set(YAML_CPP_PATH /home/sh13/local/yaml-cpp CACHE PATH "path to yaml-cpp installation dir" FORCE)
#find_package(yaml-cpp)
find_package(PkgConfig REQUIRED)
pkg_check_modules(yaml_cpp REQUIRED yaml-cpp)

find_package(Threads)

option(BUILD_APV "Build and install APV analysis tools" OFF)
option(BUILD_EURICA "Build and install Eurica analysis tools" OFF)

include_directories(${yaml_cpp_INCLUDEDIR})
include_directories(core/include)

link_directories(${ROOTSYS}/lib)
link_directories(${yaml_cpp_LIBDIR})

add_subdirectory(core)

if(BUILD_APV)
    add_subdirectory(APV)
endif()

if(BUILD_EURICA)
    add_subdirectory(eurica)
endif()

add_subdirectory(share)