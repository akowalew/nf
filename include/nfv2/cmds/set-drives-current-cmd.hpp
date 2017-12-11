/**
 * set-drives-current-cmd.hpp
 * Contains declaration of SetDrivesCurrentCmd class
 * Author: akowalew
 */

#pragma once

#include "nfv2/command.hpp"

#include <cstdint>

namespace nfv2 {

class SetDrivesCurrentCmd
	:	public Command
{
public:
	SetDrivesCurrentCmd(int16_t current);

private:
	int16_t _current;
};

} // namespace nfv2
