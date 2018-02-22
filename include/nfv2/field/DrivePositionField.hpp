#pragma once

#include "comms/comms.h"

#include "nfv2/common/Field.hpp"

namespace nfv2 {
namespace field {

using DrivePositionField =
	comms::field::IntValue<
		common::Field,
		std::int16_t,
		comms::option::ValidNumValueRange<-32767, 32767>
	>;

} // namespace field
} // namespace nfv2
