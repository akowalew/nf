# CMakeLists.txt
# Top-level CMakeLists, NFv2 library configuration
# Author: akowalew

cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)
project(nfv2)

set(PROJECT_VERSION_MAJOR 2)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)

option(NFV2_BUILD_EXAMPLES
	"Build examples of usage of NFv2" ON)
option(NFV2_ETL_PROFILE_PROVIDED 
	"Use another etl_profile.h file for ETLCPP, instead of selected by this library" OFF)
option(NFV2_ETL_PROVIDED
	"Use other source of etlcpp library instead of placed in subdirectory" OFF)

if(NOT DEFINED NFV2_ETL_PATH)
	if(NFV2_ETL_PROVIDED)
		message(FATAL_ERROR "NFV2_ETL_PATH not specified")
	else()
		set(NFV2_ETL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/etl")
	endif()
endif()

if(NOT NFV2_ETL_PROFILE_PROVIDED)
	configure_file(${NFV2_ETL_PATH}/src/profiles/gcc_generic.h
		${CMAKE_BINARY_DIR}/include/etl_profile.h
		COPYONLY)
	include_directories(${CMAKE_BINARY_DIR}/include)
endif()

include_directories(
	${NFV2_ETL_PATH}/src
	include
)
add_subdirectory(src)

if(NFV2_BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()
