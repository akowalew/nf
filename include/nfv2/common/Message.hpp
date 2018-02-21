#pragma once

#include "comms/comms.h"

#include "nfv2/common/MsgId.hpp"

namespace nfv2 {
namespace common {

template<typename... TOptions>
using Message =
	comms::Message<
		comms::option::LittleEndian,
		comms::option::MsgIdType<MsgId>,
		TOptions...
	>;

} // namespace common
} // namespace nfv2
