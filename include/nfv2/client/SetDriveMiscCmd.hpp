#pragma once

#include "nfv2/common/Message.hpp"
#include "nfv2/msg/SetDriveMiscCmdBase.hpp"

namespace nfv2 {
namespace client {

template<typename... TOptions>
using SetDriveMiscCmd =
	msg::SetDriveMiscCmdBase<
		common::Message<TOptions...>,
		common::MessageMode::ClientOnly
	>;

} // namespace client
} // namespace nfv2
