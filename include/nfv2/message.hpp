/**
 * Message.hpp
 * Contains declaration of Message class
 * Author: akowalew
 */

#pragma once

#include "vector.h" // ETLCPP

#include "nfv2/id.hpp"

namespace nfv2 {

struct Message
{
    constexpr static auto MaxDataLength = 8;
    constexpr static auto MaxLength = MaxDataLength + 2; // data + dataLength + id
    using Data = etl::vector<uint8_t, MaxDataLength>;

    Id id;
    Data data;
};

} // namespace nfv2
