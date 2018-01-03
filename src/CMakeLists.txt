# CMakeLists.txt
# Adds nfv2 target library
# Author: akowalew

add_library(nfv2
	crc.cpp
	frame-parser.cpp
	frame.cpp
	master.cpp
	request-handler.cpp
	slave-endpoint.cpp
)

target_link_libraries(nfv2)

set_target_properties(nfv2 PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)