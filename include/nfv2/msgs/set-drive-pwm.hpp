#pragma once

#include <cstdint>

#include "nfv2/msgs/types.hpp"

namespace nfv2 {
	
struct SetDrivePwmCommand
{
	NFV2_COMMAND(0x14)

	int16_t pwm;	
};

// no answer specified

} // namespace nfv2