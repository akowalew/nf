#pragma once

#include "comms/comms.h"

#include "nfv2/common/Field.hpp"

namespace nfv2 {
namespace field {

using ChecksumType = std::uint8_t;

using ChecksumField =
	comms::field::IntValue<
		common::Field,
		ChecksumType
	>;

} // namespace field
} // namespace nfv2
