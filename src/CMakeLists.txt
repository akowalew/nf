# CMakeLists.txt
# Adds nfv2 target library
# Author: akowalew

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
	-std=gnu++14 \
	-Wall \
	-Wno-long-long \
	-pedantic \
")

add_library(nfv2
	crc.cpp
	frame-parser.cpp
	frame.cpp
)

