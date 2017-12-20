/**
 * frame.hpp
 * Contains declaration of Frame class
 * Author: akowalew
 */

#pragma once

#include "vector.h" // ETLCPP

#include "message.hpp"

namespace nfv2 {

struct Frame
{
    constexpr static auto MaxMessages = 4;
    using Messages = etl::vector<Message, MaxMessages>;

    uint8_t address;
    Messages messages;

    size_t toBuffer(uint8_t* buffer, size_t size) const;

    constexpr static auto MaxBufferSize = 5 // start + CL + ~CL + Addr + CRC
    	+ MaxMessages * Message::MaxBufferSize;
};

} // namespace nfv2
