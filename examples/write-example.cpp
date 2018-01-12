/**
 * example.cpp
 * Example of usage of NFv2 library
 * Writing out a frame to a byte stream
 * Author: akowalew
 */

#include <iostream>

#include "nfv2/nfv2.hpp"

#include <array>

int main(int argc, char** argv)
{
	nfv2::Frame frame{nfv2::Address(0x01)};

	nfv2::Message message{nfv2::Id(0x01)};
	message.data.push_back(0x01);
	message.data.push_back(0x02);
	frame.messages.push_back(message);

	std::array<uint8_t, 128> buffer;
	const auto bytesWritten = 
		frame.toBuffer(buffer.data(), buffer.size());

	std::cout << "Buffer with frame data (" 
		<< bytesWritten << " bytes): ";
	std::cout << std::hex << std::showbase;
	for(const auto data : buffer)
	{
		std::cout << (int)data << ", ";
	}
	std::cout << '\n';
}
