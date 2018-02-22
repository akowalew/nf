#pragma once

#include "comms/comms.h"

#include "nfv2/field/SyncField.hpp"
#include "nfv2/protocol/MsgSizeLayerBase.hpp"

namespace nfv2 {
namespace protocol {

template<typename TAllInputMessages, typename... TOptions>
using SyncPrefixLayerBase =
	comms::protocol::SyncPrefixLayer<
		field::SyncField,
		MsgSizeLayerBase<TAllInputMessages, TOptions...>
	>;

} // namespace protocol
} // namespace nfv2
