#pragma once

#include "comms/protocol/checksum/Crc.h"

#include "nfv2/checksum/CrcInitTable_8_D8.hpp"

namespace nfv2 {
namespace checksum {

using Crc_8_D8 =
	comms::protocol::checksum::Crc<std::uint8_t, 0xD8>;

} // namespace checksum
} // namespace nfv2
