# CMakeLists.txt
# Top-level CMakeLists, NFv2 library configuration
# Author: akowalew

cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)
project(nfv2)

set(PROJECT_VERSION_MAJOR 2)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)

option(BUILD_EXAMPLES "Build examples of usage of NFv2" ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")

include_directories(include)
add_subdirectory(src)

if(BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()
