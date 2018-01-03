/**
 * Message.hpp
 * Contains declaration of Message class
 * Author: akowalew
 */

#pragma once

#include "vector.h" // ETLCPP

namespace nfv2 {

struct Message
{
    constexpr static auto MaxDataLength = 8;
    using Data = etl::vector<uint8_t, MaxDataLength>;

    uint8_t code;
    Data data;

    constexpr static auto MaxLength = MaxDataLength + 2; // data + dataLength + code

    uint8_t getLength() const
    {
    	return data.size() + 2; // data + dataLength + code;
    }
};

} // namespace nfv2
