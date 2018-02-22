#pragma once

#include "comms/comms.h"

#include "nfv2/common/Field.hpp"

namespace nfv2 {
namespace field {

using AddressType = std::uint8_t;

using AddressField =
	comms::field::IntValue<
		common::Field,
		AddressType
	>;

} // namespace field
} // namespace nfv2
