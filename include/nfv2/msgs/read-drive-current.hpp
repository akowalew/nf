#pragma once

#include <cstdint>

#include "nfv2/msgs/types.hpp"

namespace nfv2 {

struct ReadDriveCurrentCommand
{
	NFV2_COMMAND(0x1B)

	// empty command
};

struct ReadDriveCurrentAnswer
{
	NFV2_ANSWER(0x1B)

	int16_t current;
};

// no answer specified

} // namespace nfv2