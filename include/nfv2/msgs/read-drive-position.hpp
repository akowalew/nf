#pragma once

#include <cstdint>

#include "nfv2/msgs/types.hpp"

namespace nfv2 {

struct ReadDrivePositionCommand
{
	NFV2_COMMAND(0x1A)

	// empty command
};

struct ReadDrivePositionAnswer
{
	NFV2_ANSWER(0x1A)

	int32_t position;
};

// no answer specified

} // namespace nfv2