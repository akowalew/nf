add_executable(master-example
	master-example.cpp
)

target_link_libraries(master-example
	nfv2
)

set_target_properties(master-example PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)


add_executable(slave-example
	slave-example.cpp
)

target_link_libraries(slave-example
	nfv2
)

set_target_properties(slave-example PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
