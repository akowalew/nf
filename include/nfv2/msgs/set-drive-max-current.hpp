#pragma once

#include <cstdint>

#include "nfv2/msgs/types.hpp"

namespace nfv2 {

struct SetDriveMaxCurrentCommand
{
	NFV2_COMMAND(0x15)

	int16_t maxCurrent;
};

// no answer specified

} // namespace nfv2