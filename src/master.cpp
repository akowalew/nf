/**
 * master.cpp
 * Contains implementation of Master class
 * Author: akowalew
 */

#include "nfv2/master.hpp"

#include <cassert>

namespace nfv2 {
	
void Master::addSlaveInstance(SlaveInstance slaveInstance)
{
	const auto slaveAddress = slaveInstance.getAddress();
	_slavesInstances.insert(
		std::make_pair(slaveAddress, std::move(slaveInstance)));
}

void Master::send(Address address, const Frame& request, Frame& response)
{
	auto slaveInstance = _slavesInstances.find(address);
	assert(slaveInstance != _slavesInstances.end()); // assume that found
	slaveInstance->second.send(request, response);
}

void Master::send(Address address, const Frame& request)
{
	auto slaveInstance = _slavesInstances.find(address);
	assert(slaveInstance != _slavesInstances.end()); // assume that found
	slaveInstance->second.send(request);
}

} // namespace nfv2