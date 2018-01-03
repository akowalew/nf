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

void SlaveEndpoint::send(const Frame& request, Frame& response)
{
	send(request);
}

} // namespace nfv2