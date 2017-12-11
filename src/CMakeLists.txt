# CMakeLists.txt
# Adds nfv2 target library
# Author: akowalew

add_library(nfv2
	address.cpp
	command.cpp
	crc.cpp
	master.cpp
	message.cpp
	reply.cpp
	request.cpp
	response.cpp
	slave.cpp
)

add_subdirectory(cmds)

target_link_libraries(nfv2
	nfv2_cmds
)

set_target_properties(nfv2 PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)