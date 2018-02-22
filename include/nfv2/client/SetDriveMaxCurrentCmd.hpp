#pragma once

#include "nfv2/common/Message.hpp"
#include "nfv2/msg/SetDriveMaxCurrentCmdBase.hpp"

namespace nfv2 {
namespace client {

template<typename... TOptions>
using SetDriveMaxCurrentCmd =
	msg::SetDriveMaxCurrentCmdBase<
		common::Message<TOptions...>,
		common::MessageMode::ClientOnly
	>;

} // namespace client
} // namespace nfv2
