#pragma once

#include "nfv2/common/Message.hpp"
#include "nfv2/msg/GetDriveStatusAnsBase.hpp"

namespace nfv2 {
namespace client {

template<typename... TOptions>
using GetDriveStatusAns =
	msg::GetDriveStatusAnsBase<
		common::Message<TOptions...>,
		common::MessageMode::ClientOnly
	>;

} // namespace client
} // namespace nfv2
