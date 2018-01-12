/**
 * Message.hpp
 * Contains declaration of Message class
 * Author: akowalew
 */

#pragma once

#include "vector.h" // ETLCPP

#include "nfv2/code.hpp"

namespace nfv2 {

struct Message
{
    constexpr static auto MaxDataLength = 8;
    constexpr static auto MaxLength = MaxDataLength + 2; // data + dataLength + code
    using Data = etl::vector<uint8_t, MaxDataLength>;

    Code code;
    Data data;

    uint8_t getLength() const noexcept
    {
    	return data.size() + 2; // data + dataLength + code;
    }
};

} // namespace nfv2
