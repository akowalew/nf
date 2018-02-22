#pragma once

#include "comms/comms.h"
#include "nfv2/common/Field.hpp"

namespace nfv2 {
namespace field {

using MsgDataSizeType = std::uint8_t;

using MsgDataSizeField =
	comms::field::IntValue<
		common::Field,
		MsgDataSizeType
	>;

} // namespace field
} // namespace nfv2
