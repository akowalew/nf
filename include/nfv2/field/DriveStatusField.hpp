#pragma once

#include "comms/comms.h"

#include "nfv2/common/Field.hpp"

namespace nfv2 {
namespace field {

struct DriveStatusField
	:	public comms::field::BitmaskValue<
			common::Field,
			comms::option::FixedLength<2>, // two-bytes wide
			comms::option::BitmaskReservedBits<0x3E0>
		>
{
	COMMS_BITMASK_BITS(
		LimitSwitchUp = 0,
		LimitSwitchDown = 1,
		SynchroSwitch = 2,
		EncoderIndexSignal = 3,
		Synchronized = 4,
		PositionLimit = 10,
		SpeedLimit = 11,
		CurrentLimit = 12,
		OverCurrent = 13,
		PowerStageFault = 14,
		Error = 15
	);

	COMMS_BITMASK_BITS_ACCESS(
		LimitSwitchUp,
		LimitSwitchDown,
		SynchroSwitch,
		EncoderIndexSignal,
		Synchronized,
		PositionLimit,
		SpeedLimit,
		CurrentLimit,
		OverCurrent,
		PowerStageFault,
		Error
	);
};

} // namespace field
} // namespace nfv2
