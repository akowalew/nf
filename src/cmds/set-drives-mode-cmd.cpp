/**
 * set-drives-mode-cmd.cpp
 * Contains implementation of SetDrivesModeCmd class
 * Author: akowalew
 */

#include "nfv2/cmds/set-drives-mode-cmd.hpp"

namespace nfv2 {
	
SetDrivesModeCmd::SetDrivesModeCmd(DrivesMode drivesMode)
	:	Command(0x10, 1),
		_drivesMode(drivesMode)
{
	data[0] = static_cast<uint8_t>(_drivesMode);
}

} // namespace nfv2
