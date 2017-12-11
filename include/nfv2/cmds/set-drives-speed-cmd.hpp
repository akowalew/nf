/**
 * set-drives-speed-cmd.hpp
 * Contains declaration of SetDrivesSpeedCmd class
 * Author: akowalew
 */

#pragma once

#include "nfv2/command.hpp"

#include <cstdint>

namespace nfv2 {

class SetDrivesSpeedCmd
	:	public Command
{
public:
	SetDrivesSpeedCmd(int32_t speed);

private:
	int32_t _speed;
};

} // namespace nfv2
