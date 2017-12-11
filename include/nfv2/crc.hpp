/**
 * crc.h
 * Contains declarations to perform CRC calculation used by NFv2
 * Author: akowalew
 */

#pragma once

#include <cstdint>
#include <cstdlib>

namespace nfv2 {
	
uint8_t crcU8(const uint8_t* buffer, size_t bufferSize);

} // namespace nfv2
