#pragma once

#include "nfv2/common/Message.hpp"
#include "nfv2/msg/GetDrivePositionCmdBase.hpp"

namespace nfv2 {
namespace client {

template<typename... TOptions>
using GetDrivePositionCmd =
	msg::GetDrivePositionCmdBase<
		common::Message<TOptions...>,
		common::MessageMode::ClientOnly
	>;

} // namespace client
} // namespace nfv2
