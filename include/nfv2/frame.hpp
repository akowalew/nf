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
    constexpr static auto MessagesMax = 4;
    using Messages = etl::vector<Message, MessagesMax>;

    uint8_t address;
    Messages messages;
};
} // namespace nfv2
