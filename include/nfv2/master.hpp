/**
 * master.hpp
 * Contains declaration of Master class
 * Author: akowalew
 */

#pragma once

#include "flat_map.h" // ETLCPP

#include "nfv2/address.hpp"
#include "nfv2/frame.hpp"
#include "nfv2/slave-endpoint.hpp"

namespace nfv2 {

class Master
{
public:
	void addSlaveEndpoint(SlaveEndpoint slaveEndpoint);

	void send(const Frame& request, SlaveEndpoint::Callback callback);
	void send(const Frame& request);

	void handleReceive(Address address, const uint8_t* buffer, size_t size);

private:
	constexpr static auto SlavesMax = 8;
	using SlavesEndpoints = etl::flat_map<Address, SlaveEndpoint, SlavesMax>;

	SlavesEndpoints _slavesEndpoints;
};

} // namespace nfv2
