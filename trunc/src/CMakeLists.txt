# CMakeLists.txt
# Adds nfv2 target library
# Author: akowalew

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
-std=c++17 \
-Wall \
-Wno-long-long \
-Werror \
-fno-exceptions \
-fno-rtti \
-fno-unwind-tables \
-fno-asynchronous-unwind-tables \
")

add_library(nfv2
	crc.cpp
	frame-parser.cpp
	frame.cpp
)

