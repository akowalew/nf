#pragma once

#include <cstdint>

namespace nfv2 {
namespace common {

enum class DriveMode : std::uint8_t
{
	Error = 0x00,
	Manual = 0x01,
	Speed = 0x02,
	Current = 0x04,
	PWM = 0x05,
	SyncPWM0 = 0x10,
	SyncCurrent0 = 0x11,
	SyncPos0 = 0x12
};

} // namespace common
} // namespace nfv2
