#pragma once

#include "nfv2/common/Message.hpp"
#include "nfv2/msg/GetDriveCurrentCmdBase.hpp"

namespace nfv2 {
namespace client {

template<typename... TOptions>
using GetDriveCurrentCmd =
	msg::GetDriveCurrentCmdBase<
		common::Message<TOptions...>,
		common::MessageMode::ClientOnly
	>;

} // namespace client
} // namespace nfv2
