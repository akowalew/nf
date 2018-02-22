#pragma once

#include "comms/comms.h"

#include "nfv2/client/GetDriveCurrentAns.hpp"
#include "nfv2/client/GetDrivePositionAns.hpp"
#include "nfv2/client/GetDriveStatusAns.hpp"

namespace nfv2 {
namespace client {

template<typename... TOptions>
using AllInputMessages =
	std::tuple<
		// don't reorder - sorted by growing MsgId
		GetDrivePositionAns<TOptions...>,
		GetDriveCurrentAns<TOptions...>,
		GetDriveStatusAns<TOptions...>
	>;

} // namespace client
} // namespace nfv2
