/**
 * set-drives-position-cmd.hpp
 * Contains declaration of SetDrivesPositionCmd class
 * Author: akowalew
 */

#pragma once

#include "nfv2/command.hpp"

#include <cstdint>

namespace nfv2 {

class SetDrivesPositionCmd
	:	public Command
{
public:
	SetDrivesPositionCmd(int32_t position);

private:
	int32_t _position;
};

} // namespace nfv2
