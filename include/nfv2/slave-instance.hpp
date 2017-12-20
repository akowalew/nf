/**
 * slave-instance.hpp
 * Contains declaration of SlaveInstance class
 * Author: akowalew
 */

#pragma once

#include <array>

#include "nfv2/address.hpp"
#include "nfv2/frame.hpp"

namespace nfv2 {

class SlaveInstance
{
public:
	using SendHandler = size_t (*)(const uint8_t* buffer, size_t size);

	SlaveInstance(Address address, SendHandler sendHandler);

	void send(const Frame& request, Frame& response);
	void send(const Frame& request);

	Address getAddress() const
	{
		return _address;
	}

private:
	Address _address;
	SendHandler _sendHandler;
	std::array<uint8_t, Frame::MaxBufferSize> _buffer;
};

} // namespace nfv2
