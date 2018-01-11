#pragma once

#include <cstdint>

#include <bitset>

#include "nfv2/msgs/types.hpp"

namespace nfv2 {

using DriveStatus = uint16_t;

constexpr uint16_t LimitSwitchUp      = (1 << 0);
constexpr uint16_t LimitSwitchDown    = (1 << 1);
constexpr uint16_t SynchroSwitch      = (1 << 2);
constexpr uint16_t EncoderIndexSignal = (1 << 3);
constexpr uint16_t Synchronized       = (1 << 4);
constexpr uint16_t PositionLimit      = (1 << 10);		
constexpr uint16_t SpeedLimit         = (1 << 11);
constexpr uint16_t CurrentLimit       = (1 << 12);
constexpr uint16_t Overcurrent        = (1 << 13);	
constexpr uint16_t PowerStageFault    = (1 << 14);
constexpr uint16_t Error              = (1 << 15);

struct ReadDriveStatusCommand
{
	NFV2_COMMAND(0x1F)

	// empty command
};

struct ReadDriveStatusAnswer
{
	NFV2_ANSWER(0x1F)

	DriveStatus status;
};

// no answer specified

} // namespace nfv2