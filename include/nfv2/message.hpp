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
    constexpr static auto MaxDataBytes = 8;
    using Data = etl::vector<uint8_t, MaxDataBytes>;

    uint8_t code;
    Data data;

    constexpr static auto MaxBufferSize = 1 + MaxDataBytes;
};

} // namespace nfv2
