#pragma once

#include "comms/comms.h"
#include "nfv2/common/Field.hpp"
#include "nfv2/common/MsgId.hpp"

namespace nfv2 {
namespace field {

using MsgIdField =
	comms::field::EnumValue<
		common::Field,
		common::MsgId
	>;

} // namespace field
} // namespace nfv2
