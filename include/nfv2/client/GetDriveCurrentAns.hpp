#pragma once

#include "nfv2/common/Message.hpp"
#include "nfv2/msg/GetDriveCurrentAnsBase.hpp"

namespace nfv2 {
namespace client {

template<typename... TOptions>
using GetDriveCurrentAns =
	msg::GetDriveCurrentAnsBase<
		common::Message<TOptions...>,
		common::MessageMode::ClientOnly
	>;

} // namespace client
} // namespace nfv2
