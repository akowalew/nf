/**
 * msgs-write-example.cpp
 * Example of usage of NFv2 library
 * Writing out a frame with messages to a byte stream
 * Author: akowalew
 */

#include <iostream>

#include "nfv2/nfv2.hpp"

#include <array>

int main(int argc, char** argv)
{
	nfv2::Frame frame{nfv2::Address(0x01)};
	frame.messages.push_back(nfv2::SetDrivePwmCommand(0x6666).toMessage());	
	frame.messages.push_back(nfv2::ReadDriveStatusCommand().toMessage());

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
