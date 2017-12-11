/**
 * example.cpp
 * Example of usage of NFv2 library in Master mode
 * Author: akowalew
 */

#include <iostream>
#include <array>

#include "nfv2/nfv2.hpp"

int main()
{
	nfv2::Request request(nfv2::Address(0x01));

	nfv2::SetDrivesModeCmd setDrivesModeCmd(nfv2::DrivesMode::Current);
	// nfv2::SetDrivesCurrentCmd setDrivesCurrentCmd(int16_t(256));

	request.addCommand(&setDrivesModeCmd);
	// request.addCommand(&setDrivesCurrentCmd);

	std::array<uint8_t, 128> buffer;
	const auto writtenBytes = request.write(buffer.data(), buffer.size());

	std::cout << "Written: " << writtenBytes << std::endl;
	std::cout << std::hex << std::showbase;
	for(size_t i = 0; i < writtenBytes; ++i)
	{
		std::cout << (int)buffer[i] << ", ";
	}
	std::cout << std::endl;
}