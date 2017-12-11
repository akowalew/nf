/**
 * set-drives-mode-cmd.hpp
 * Contains declaration of SetDrivesModeCmd class
 * Author: akowalew
 */

#pragma once

#include "nfv2/command.hpp"
#include "nfv2/drives-mode.hpp"

namespace nfv2 {

class SetDrivesModeCmd
	:	public Command
{
public:
	SetDrivesModeCmd(DrivesMode drivesMode);
	
private:
	DrivesMode _drivesMode;
};

} // namespace nfv2
