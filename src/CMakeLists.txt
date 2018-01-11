# CMakeLists.txt
# Adds nfv2 target library
# Author: akowalew

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")

add_library(nfv2
	crc.cpp
	frame-parser.cpp
	frame.cpp
)

target_link_libraries(nfv2)

set_target_properties(nfv2 PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
)