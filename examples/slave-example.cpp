/**
 * example.cpp
 * Example of usage of NFv2 library in Slave mode
 * Author: akowalew
 */

#include <iostream>
#include <array>

#include "nfv2/nfv2.hpp"

int main()
{
	nfv2::Slave slave();
	nfv2::Request request(nfv2::Address(0x01));

	std::array<uint8_t, 128> buffer;
	request.read(buffer.data(), buffer.size());
}