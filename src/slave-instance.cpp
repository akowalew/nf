/**
 * slave-instance.cpp
 * Contains implementation of SlaveInstance class
 * Author: akowalew
 */

#include "nfv2/slave-instance.hpp"

#include <cassert>

namespace nfv2 {
	
SlaveInstance::SlaveInstance(Address address, SendHandler sendHandler)
	:	_address(address),
		_sendHandler(sendHandler)
{
	assert(sendHandler);
}

// void SlaveInstance::send(const Frame& request, Frame& response)
// {
// 	auto slaveInstance = _slavesInstances.find(address);
// 	assert(slaveInstance != _slavesInstances.end()); // assume that found
// 	slaveInstance->second.send(request, response);
// }

void SlaveInstance::send(const Frame& request)
{
	auto requestSize = request.toBuffer(_buffer.data(), _buffer.size());
	do
	{
		const auto bytesSent = _sendHandler(_buffer.data(), requestSize);
		assert(bytesSent <= requestSize);
		requestSize -= bytesSent;
	}
	while(requestSize);
}

} // namespace nfv2