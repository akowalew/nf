add_library(nfv2_cmds
	set-drives-mode-cmd.cpp
	set-drives-speed-cmd.cpp
	set-drives-current-cmd.cpp
	set-drives-position-cmd.cpp
)

set_target_properties(nfv2_cmds PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)