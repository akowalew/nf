#pragma once

#include "comms/comms.h"

#include "nfv2/common/MessageMode.hpp"

namespace nfv2 {
namespace common {

// Extra options for Commands messages in server or client version
template<MessageMode TMessageMode>
struct CommandExtraOptions
{
	using Type = std::tuple<>;
};

// Client only specialization, which disables read and dispatch operations.
// Client can only send Commands, not receive or handle them.
template<>
struct CommandExtraOptions<MessageMode::ClientOnly>
{
	using Type = std::tuple<
		comms::option::NoReadImpl,
		comms::option::NoDispatchImpl
	>;
};

// Server only specialization, which disables write operations.
// Server can only receive Commands, not send them.
template<>
struct CommandExtraOptions<MessageMode::ServerOnly>
{
	using Type = std::tuple<
		comms::option::NoWriteImpl
	>;
};

} // namespace common
} // namespace nfv2
