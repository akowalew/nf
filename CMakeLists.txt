# CMakeLists.txt
# Top-level CMakeLists, NFv2 library configuration
# Author: akowalew

cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)
project(nfv2)

set(PROJECT_VERSION_MAJOR 2)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)

option(BUILD_EXAMPLES "Build examples of usage of NFv2" ON)
option(NFV2_ETL_PROFILE_PROVIDED 
	"Use another etl_profile.h file for ETLCPP, instead of selected by this library" OFF)

include_directories(etl/src)

if(NOT NFV2_ETL_PROFILE_PROVIDED)
	configure_file(etl/src/profiles/gcc_generic.h
		${CMAKE_BINARY_DIR}/include/etl_profile.h
		COPYONLY)
	include_directories(${CMAKE_BINARY_DIR}/include)
endif()

include_directories(include)
add_subdirectory(src)

if(BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()
