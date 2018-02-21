#pragma once

#include "nfv2/common/Message.hpp"
#include "nfv2/msg/SetDriveModeCmdBase.hpp"

namespace nfv2 {
namespace client {

template<typename... TOptions>
using SetDriveModeCmd =
	msg::SetDriveModeCmdBase<
		common::Message<TOptions...>,
		common::MessageMode::ClientOnly
	>;

} // namespace client
} // namespace nfv2
