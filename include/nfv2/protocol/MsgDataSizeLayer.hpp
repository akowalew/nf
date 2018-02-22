#pragma once

#include "comms/comms.h"
#include "nfv2/field/MsgDataSizeField.hpp"
#include "nfv2/protocol/MsgDataLayer.hpp"

namespace nfv2 {
namespace protocol {

using MsgDataSizeLayer =
	comms::protocol::MsgSizeLayer<
		field::MsgDataSizeField,
		protocol::MsgDataLayer // next layer
	>;

} // namespace protocol
} // namespace nfv2
