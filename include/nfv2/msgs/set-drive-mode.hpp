#pragma once

#include <cstdint>

#include "nfv2/msgs/types.hpp"

namespace nfv2 {
	
enum class DriveMode : uint8_t
{
	Error = 0x00,
	Manual = 0x01,
	Speed = 0x02,
	Current = 0x03,
	Position = 0x04,
	Pwm = 0x05,
	SyncPwm0 = 0x10,
	SyncCurrent0 = 0x11,
	SyncPos0 = 0x12
};

struct SetDriveModeCommand
{
	NFV2_COMMAND(0x10)

	DriveMode driveMode;	
};

// no answer specified

} // namespace nfv2