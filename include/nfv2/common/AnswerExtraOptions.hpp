#pragma once

#include "comms/comms.h"

#include "nfv2/common/MessageMode.hpp"

namespace nfv2 {
namespace common {

// Extra options for Answers messages in server or client version.
template<MessageMode TMessageMode>
struct AnswerExtraOptions
{
	using Type = std::tuple<>;
};

// Client only specialization, which disables write operations.
// Client can only receive Answers, not send them.
template<>
struct AnswerExtraOptions<MessageMode::ClientOnly>
{
	using Type = std::tuple<
		comms::option::NoWriteImpl
	>;
};

// Server only specialization, which disables read and dispatch operations.
// Server can only send Answers, not receive or handle them.
template<>
struct AnswerExtraOptions<MessageMode::ServerOnly>
{
	using Type = std::tuple<
		comms::option::NoReadImpl,
		comms::option::NoDispatchImpl
	>;
};

} // namespace common
} // namespace nfv2
