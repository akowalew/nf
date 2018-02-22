#pragma once

#include "comms/comms.h"

#include "nfv2/field/MsgSizeField.hpp"
#include "nfv2/protocol/ChecksumLayerBase.hpp"

namespace nfv2 {
namespace protocol {

template<typename TAllInputMessages, typename... TOptions>
using MsgSizeLayerBase =
	comms::protocol::MsgSizeLayer<
		field::MsgSizeField,
		protocol::ChecksumLayerBase<TAllInputMessages, TOptions...>
	>;

} // namespace protocol
} // namespace nfv2
