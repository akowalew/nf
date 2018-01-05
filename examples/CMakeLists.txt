add_executable(parse-example
	parse-example.cpp
)

target_link_libraries(parse-example
	nfv2
)

set_target_properties(parse-example PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)


add_executable(write-example
	write-example.cpp
)

target_link_libraries(write-example
	nfv2
)

set_target_properties(write-example PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
