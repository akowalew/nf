#pragma once

#include "nfv2/common/Message.hpp"
#include "nfv2/msg/GetDriveStatusCmdBase.hpp"

namespace nfv2 {
namespace client {

template<typename... TOptions>
using GetDriveStatusCmd =
	msg::GetDriveStatusCmdBase<
		common::Message<TOptions...>,
		common::MessageMode::ClientOnly
	>;

} // namespace client
} // namespace nfv2
