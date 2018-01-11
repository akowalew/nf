/**
 * crc.h
 * Contains declarations to perform CRC calculation used by NFv2
 * Author: akowalew
 */

#pragma once

#include <cstdlib>
#include <cstdint>

namespace nfv2 {
	
/**
 * Class for calculating CRC, used by nf protocol
 * Uses CRC8 algorithm with 0xD8 polynomial
 */
class Crc
{
public:
	Crc() = default;

	explicit Crc(uint8_t data)
	{
		init(data);
	}

    void init(uint8_t data);
    void step(uint8_t data);

    uint8_t getRemainder() const
    {
        return _remainder;
    }

private:
    uint8_t _remainder;
};

} // namespace nfv2
