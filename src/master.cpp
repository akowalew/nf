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

void Master::send(const Frame& request, Frame& response)
{
	auto slaveEndpoint = _slavesEndpoints.find(request.address);
	assert(slaveEndpoint != _slavesEndpoints.end()); // assume that found
	slaveEndpoint->second.send(request, response);
}

void Master::send(const Frame& request)
{
	auto slaveEndpoint = _slavesEndpoints.find(request.address);
	assert(slaveEndpoint != _slavesEndpoints.end()); // assume that found
	slaveEndpoint->second.send(request);
}

} // namespace nfv2