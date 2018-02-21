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

inline bool operator==(const Message& msg1, const Message& msg2) noexcept
{
	return (msg1.id == msg2.id && msg1.data == msg2.data);
}

inline bool operator!=(const Message& msg1, const Message& msg2) noexcept
{
	return !(msg1 == msg2);
}

} // namespace nfv2
