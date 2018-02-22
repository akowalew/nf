#pragma once

#include "comms/comms.h"

#include "nfv2/field/ChecksumField.hpp"
#include "nfv2/checksum/Crc_8_D8.hpp"
#include "nfv2/protocol/AddressLayerBase.hpp"

namespace nfv2 {
namespace protocol {

using ChecksumCalculator = checksum::Crc_8_D8;

template<typename TAllInputMessages, typename... TOptions>
using ChecksumLayerBase =
	comms::protocol::ChecksumLayer<
		field::ChecksumField,
		ChecksumCalculator,
		AddressLayerBase<TAllInputMessages, TOptions...> // next layer
	>;

} // namespace protocol
} // namespace nfv2
