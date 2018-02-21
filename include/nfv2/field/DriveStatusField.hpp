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
		LimitSwitchUp = (1 << 0),
		LimitSwitchDown = (1 << 1),
		SynchroSwitch = (1 << 2),
		EncoderIndexSignal = (1 << 3),
		Synchronized = (1 << 4),
		PositionLimit = (1 << 10),
		SpeedLimit = (1 << 11),
		CurrentLimit = (1 << 12),
		OverCurrent = (1 << 13),
		PowerStageFault = (1 << 14),
		Error = (1 << 15)
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
