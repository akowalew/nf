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
    constexpr static auto BufferBytesMax = 8;
    using Buffer = etl::vector<uint8_t, BufferBytesMax>;

    uint8_t code;
    Buffer buffer;
};

} // namespace nfv2
