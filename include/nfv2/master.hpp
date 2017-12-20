/**
 * master.hpp
 * Contains declaration of Master class
 * Author: akowalew
 */

#pragma once

#include "flat_map.h" // ETLCPP

#include "nfv2/address.hpp"
#include "nfv2/frame.hpp"
#include "nfv2/slave-instance.hpp"

namespace nfv2 {

class Master
{
public:
	void addSlaveInstance(SlaveInstance slaveInstance);

	void send(Address address, const Frame& request, Frame& response);
	void send(Address address, const Frame& request);

private:
	using SlavesInstances = etl::flat_map<Address, SlaveInstance, 8>;

	SlavesInstances _slavesInstances;
};

} // namespace nfv2
