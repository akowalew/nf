/**
 * request-handler.cpp
 * Contains implementation of RequestHandler class
 * Author: akowalew
 */

#include "nfv2/request-handler.hpp"

namespace nfv2 {
	
RequestHandler::HandlerResult
RequestHandler::handle(const Frame& request)
{
    _response.address = request.address;
    _response.messages.clear();

    Message result;
    for(const auto& command : request.messages)
    {
    	const auto commandHandler = _commandsHandlers.find(command.code);
        const auto commandsHandlersEnd = _commandsHandlers.end();
    	const auto found = (commandHandler != commandsHandlersEnd);
    	if(found)
    	{
            const auto handler = commandHandler->second;
            const auto handlerResult = handler(command, result);
    		if(handlerResult == HandlerResult::ResponseSet)
    		{
    			_response.messages.push_back(result);
    		}
    	}
    }

    return _response.messages.empty() 
        ? HandlerResult::NoResponse : HandlerResult::ResponseSet;
}

} // namespace nfv2