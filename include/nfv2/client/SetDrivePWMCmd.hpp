#pragma once

#include "nfv2/common/Message.hpp"
#include "nfv2/msg/SetDrivePWMCmdBase.hpp"

namespace nfv2 {
namespace client {

template<typename... TOptions>
using SetDrivePWMCmd =
	msg::SetDrivePWMCmdBase<
		common::Message<TOptions...>,
		common::MessageMode::ClientOnly
	>;

} // namespace client
} // namespace nfv2
