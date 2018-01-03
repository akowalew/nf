/**
 * slave-endpoint.hpp
 * Contains declaration of SlaveEndpoint class
 * Author: akowalew
 */

#pragma once

#include <array>

#include "queue.h" // ETLCPP

#include "nfv2/address.hpp"
#include "nfv2/frame.hpp"
#include "nfv2/frame-parser.hpp"

namespace nfv2 {

class SlaveEndpoint
{
public:
	using SendHandler = void (*)(const uint8_t* buffer, size_t size);
	using Callback = void (*)(const Frame& response);

	SlaveEndpoint(Address address, SendHandler sendHandler);

	bool send(const Frame& request, Callback callback);
	void send(const Frame& request);

	void handleReceive(const uint8_t* buffer, size_t size);

	Address getAddress() const
	{
		return _address;
	}

private:
	static constexpr auto CallbacksMax = 8;

	Address _address;
	SendHandler _sendHandler;
	std::array<uint8_t, Frame::MaxSize> _buffer;
	etl::queue<Callback, CallbacksMax> _callbacks;
	FrameParser _responseParser;
};

} // namespace nfv2
