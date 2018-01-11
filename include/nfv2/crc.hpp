/**
 * crc.h
 * Contains declarations to perform CRC calculation used by NFv2
 * Author: akowalew
 */

#pragma once

#include <cstdint>
#include <array>

namespace nfv2 {
    
/**
 * Class for calculating CRC, used by nf protocol
 * Uses CRC8 algorithm with 0xD8 polynomial
 */
class Crc
{
public:
    explicit constexpr Crc(uint8_t data = 0) noexcept
        : _remainder(crcTable[data])
    {}

    void init(uint8_t data) noexcept
    {
        _remainder = crcTable[data];
    }

    void step(uint8_t data) noexcept
    {
        _remainder = crcTable[data ^ _remainder];
    }

    uint8_t getRemainder() const noexcept
    {
        return _remainder;
    }

private:
    static const std::array<uint8_t, 256> crcTable;

    uint8_t _remainder;
};

} // namespace nfv2
