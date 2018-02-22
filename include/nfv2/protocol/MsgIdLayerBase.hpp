#pragma once

#include "comms/comms.h"

#include "nfv2/common/Message.hpp"
#include "nfv2/field/MsgIdField.hpp"
#include "nfv2/protocol/MsgDataSizeLayer.hpp"

namespace nfv2 {
namespace protocol {

template<typename TAllInputMessages, typename... TOptions>
using MsgIdLayerBase =
	comms::protocol::MsgIdLayer<
		field::MsgIdField,
		common::Message<TOptions...>,
		TAllInputMessages,
		MsgDataSizeLayer
	>;

} // namespace protocol
} // namespace nfv2
