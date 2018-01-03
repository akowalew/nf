/**
 * master.cpp
 * Contains implementation of Master class
 * Author: akowalew
 */

#include "nfv2/master.hpp"

#include <cassert>

namespace nfv2 {
	
void Master::addSlaveEndpoint(SlaveEndpoint slaveEndpoint)
{
	const auto slaveAddress = slaveEndpoint.getAddress();
	_slavesEndpoints.insert(
		std::make_pair(slaveAddress, std::move(slaveEndpoint)));
}

void Master::send(const Frame& request, SlaveEndpoint::Callback callback)
{
	auto slaveEndpoint = _slavesEndpoints.find(request.address);
	assert(slaveEndpoint != _slavesEndpoints.end()); // assume that found
	slaveEndpoint->second.send(request, callback);
}

void Master::send(const Frame& request)
{
	auto slaveEndpoint = _slavesEndpoints.find(request.address);
	assert(slaveEndpoint != _slavesEndpoints.end()); // assume that found
	slaveEndpoint->second.send(request);
}

void Master::handleReceive(Address address, const uint8_t* buffer, size_t size)
{
	auto slaveEndpoint = _slavesEndpoints.find(address);
	assert(slaveEndpoint != _slavesEndpoints.end()); // assume that found
	slaveEndpoint->second.handleReceive(buffer, size);	
}

} // namespace nfv2