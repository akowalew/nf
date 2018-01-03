/**
 * slave-endpoint.cpp
 * Contains implementation of SlaveEndpoint class
 * Author: akowalew
 */

#include "nfv2/slave-endpoint.hpp"

#include <cassert>

namespace nfv2 {
	
SlaveEndpoint::SlaveEndpoint(Address address, SendHandler sendHandler)
	:	_address(address),
		_sendHandler(sendHandler)
{
	assert(sendHandler != nullptr);
}

void SlaveEndpoint::send(const Frame& request)
{
	auto requestSize = request.toBuffer(_buffer.data(), _buffer.size());
	_sendHandler(_buffer.data(), requestSize);
}

bool SlaveEndpoint::send(const Frame& request, Callback callback)
{
	send(request);
	if(_callbacks.full())
	{
		return false;
	}

	_callbacks.push(callback);
	return true;
}

void SlaveEndpoint::handleReceive(const uint8_t* buffer, size_t size)
{
	const auto bufferEnd = buffer + size;
	do
	{
		FrameParser::Status status;
		const uint8_t* parseEnd;
		std::tie(status, parseEnd) = _responseParser.parse(buffer, bufferEnd);
		if(status == FrameParser::Status::Good)
		{
			if(_callbacks.empty())
			{
				// TODO: LOG SOMETHING
			}
			else
			{
				const auto callback = _callbacks.front();
				callback(_responseParser.getFrame());
				_callbacks.pop();
			}
		}
		else if(status == FrameParser::Status::Bad)
		{
			// TODO: LOG SOMETHING
		}

		buffer = parseEnd;
	}
	while(buffer != bufferEnd);
}

} // namespace nfv2