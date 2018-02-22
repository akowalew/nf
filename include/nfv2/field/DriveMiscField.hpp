#pragma once

#include "comms/comms.h"

#include "nfv2/common/Field.hpp"

namespace nfv2 {
namespace field {

struct DriveMiscField
	:	public comms::field::BitmaskValue<
			common::Field,
			comms::option::FixedLength<4>,
			comms::option::BitmaskReservedBits<0xFFFFFFFC>
		>
{
	COMMS_BITMASK_BITS(
		SetSynchronized = 0,
		ResetSynchronized = 1
	);

	COMMS_BITMASK_BITS_ACCESS(
		SetSynchronized,
		ResetSynchronized
	);
};

} // namespace field
} // namespace nfv2
