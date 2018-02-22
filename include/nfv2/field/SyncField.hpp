#pragma once

#include "comms/comms.h"

#include "nfv2/common/Field.hpp"

namespace nfv2 {
namespace field {

using SyncFieldType = std::uint8_t;

using SyncField =
	comms::field::IntValue<
		common::Field,
		SyncFieldType,
		comms::option::DefaultNumValue<'#'>
	>;

} // namespace field
} // namespace nfv2
