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

# add_executable(parse-example
# 	parse-example.cpp
# )

# target_link_libraries(parse-example
# 	nfv2
# )

# set_target_properties(parse-example PROPERTIES
#     CXX_STANDARD 14
#     CXX_STANDARD_REQUIRED YES
#     CXX_EXTENSIONS NO
# )


# add_executable(write-example
# 	write-example.cpp
# )

# target_link_libraries(write-example
# 	nfv2
# )

# set_target_properties(write-example PROPERTIES
#     CXX_STANDARD 14
#     CXX_STANDARD_REQUIRED YES
#     CXX_EXTENSIONS NO
# )


# add_executable(msgs-write-example
#     msgs-write-example.cpp
# )

# target_link_libraries(msgs-write-example
#     nfv2
# )

# set_target_properties(msgs-write-example PROPERTIES
#     CXX_STANDARD 14
#     CXX_STANDARD_REQUIRED YES
#     CXX_EXTENSIONS NO
# )


add_executable(comms
    comms.cpp
)


add_executable(comms2
	comms2.cpp
)

add_executable(comms3
	comms3.cpp
)
