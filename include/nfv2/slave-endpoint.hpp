/**
 * slave-endpoint.hpp
 * Contains declaration of SlaveEndpoint class
 * Author: akowalew
 */

#pragma once

#include <array>

#include "nfv2/address.hpp"
#include "nfv2/frame.hpp"

namespace nfv2 {

class SlaveEndpoint
{
public:
	using SendHandler = void (*)(const uint8_t* buffer, size_t size);

	SlaveEndpoint(Address address, SendHandler sendHandler);

	void send(const Frame& request, Frame& response);
	void send(const Frame& request);

	Address getAddress() const
	{
		return _address;
	}

private:
	Address _address;
	SendHandler _sendHandler;
	std::array<uint8_t, Frame::MaxSize> _buffer;
};

} // namespace nfv2
