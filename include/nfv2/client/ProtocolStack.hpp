#pragma once

#include "nfv2/protocol/ProtocolStackBase.hpp"
#include "nfv2/client/AllInputMessages.hpp"

namespace nfv2 {
namespace client {

template<typename... TOptions>
using ProtocolStack =
	protocol::ProtocolStackBase<
		client::AllInputMessages<TOptions...>,
		TOptions...
	>;

} // namespace client
} // namespace nfv2
