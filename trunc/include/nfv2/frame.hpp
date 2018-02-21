/**
 * frame.hpp
 * Contains declaration of Frame class
 * Author: akowalew
 */

#pragma once

#include <limits>

#include "vector.h" // ETLCPP

#include "address.hpp"
#include "message.hpp"

namespace nfv2 {

struct Frame
{
    constexpr static auto MaxMessages = 4;
    constexpr static auto MaxLength = 4 // FL + ~FL + Addr + CRC
        + MaxMessages * Message::MaxLength;
    constexpr static auto MaxSize = MaxLength + 1; // + startByte
    static_assert(MaxLength < std::numeric_limits<uint8_t>::max(),
        "Maximum frame length exceedes FrameLength field values range");
        
    using Messages = etl::vector<Message, MaxMessages>;

    Address address;
    Messages messages;

    size_t toBuffer(uint8_t* buffer, size_t size) const noexcept;

private:
    uint8_t getLength() const noexcept;
};

inline bool operator==(const Frame& f1, const Frame& f2) noexcept
{
    return (f1.address == f2.address && f1.messages == f2.messages);
}

inline bool operator!=(const Frame& f1, const Frame& f2) noexcept
{
    return !(f1 == f2);
}

} // namespace nfv2
