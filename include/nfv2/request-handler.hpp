/**
 * request-handler.hpp
 * Contains declaration of RequestHandler class
 * Author: akowalew
 */

#pragma once

#include "flat_map.h" // ETLCPP

#include "nfv2/message.hpp"
#include "nfv2/frame.hpp"

namespace nfv2 {

class RequestHandler
{
public:
    enum class HandlerResult
    {
        NoResponse,
        ResponseSet
    };

    using Handler = HandlerResult (*)(const Message& command, Message& result);

    void addHandler(uint8_t code, Handler handler)
    {
        _commandsHandlers.insert(std::make_pair(code, handler));
    }

    HandlerResult handle(const Frame& request);

    const Frame& getResponse() const
    {
        return _response;
    }

private:
    using CommandsHandlers = etl::flat_map<uint8_t, Handler, 16>; 

    CommandsHandlers _commandsHandlers;
    Frame _response;
};

} // namespace nfv2
