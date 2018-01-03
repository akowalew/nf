/**
 * example.cpp
 * Example of usage of NFv2 library in Master mode
 * Author: akowalew
 */

#include <iostream>

#include "nfv2/nfv2.hpp"

#include "array.h"

void sendHandler(const uint8_t* buffer, size_t size)
{
	std::cout << "sendHandler: sending data: ";
	const auto bufferEnd = buffer + size;
	while(buffer != bufferEnd)
	{
		std::cout << (int)*(buffer++) << ", ";
	}
	std::cout << "\n";
}

int main(int argc, char** argv)
{
	nfv2::Master master;
	master.addSlaveEndpoint(
		nfv2::SlaveEndpoint(nfv2::Address(0x01), sendHandler));

	nfv2::Frame request;
	request.address = nfv2::Address(0x01);

	nfv2::Message message;
	message.code = 0x01;
	request.messages.push_back(message);

	master.send(request);
}