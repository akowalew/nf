#pragma once

#include "comms/comms.h"

#include "nfv2/common/MessageMode.hpp"

namespace nfv2 {
namespace common {

// extra options for setters messages in server or client version
template<MessageMode TMessageMode>
struct SetterExtraOptions
{
	using Type = std::tuple<>;
};

// client only specialization, no need to read nor dispatch this command
template<>
struct SetterExtraOptions<MessageMode::ClientOnly>
{
	using Type = std::tuple<
		comms::option::NoReadImpl,
		comms::option::NoDispatchImpl
	>;
};

// server only specialization, no need to write this command
template<>
struct SetterExtraOptions<MessageMode::ServerOnly>
{
	using Type = std::tuple<
		comms::option::NoWriteImpl
	>;
};


} // namespace common
} // namespace nfv2
