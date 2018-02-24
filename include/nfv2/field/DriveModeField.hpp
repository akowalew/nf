#pragma once

#include "comms/comms.h"

#include "nfv2/common/DriveMode.hpp"
#include "nfv2/common/Field.hpp"

namespace nfv2 {
namespace field {

using DriveModeField =
	comms::field::EnumValue<
		common::Field,
		common::DriveMode
	>;

} // namespace field
} // namespace nfv2
