#pragma once

#include "comms/comms.h"

#include "nfv2/common/Field.hpp"

namespace nfv2 {
namespace field {

using DriveCurrentField =
	comms::field::IntValue<
		common::Field,
		std::int16_t,
		comms::option::ValidNumValueRange<-1000, 1000>,
		comms::option::UnitsMilliamps
	>;

} // namespace field
} // namespace nfv2
