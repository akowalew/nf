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
    using Messages = etl::vector<Message, MaxMessages>;

    Address address;
    Messages messages;

    size_t toBuffer(uint8_t* buffer, size_t size) const;

    constexpr static auto MaxLength = 4 // FL + ~FL + Addr + CRC
    	+ MaxMessages * Message::MaxLength;
    static_assert(MaxLength < std::numeric_limits<uint8_t>::max(),
        "Maximum frame length exceedes FrameLength field values range");

    constexpr static auto MaxSize = MaxLength + 1; // + startByte

	uint8_t getLength() const;
};

} // namespace nfv2
