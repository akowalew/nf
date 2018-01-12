/**
 * example.cpp
 * Example of usage of NFv2 library in Slave 
 * Parsing input byte stream into a Frame
 * Author: akowalew
 */

#include <iostream>

#include "nfv2/nfv2.hpp"

int main()
{
	nfv2::FrameParser frameParser;
	std::array<uint8_t, 9> buffer{
		0x23, // start byte
		0x08, // frame length
		0xf7, // bitwise negated frame length
		0x01, // address
		0x01, // message#0 id
		0x02, // message#0 data length
		0x01, // message#0 data byte#0
		0x02, // message#0 data byte#0
		0x48  // crc
	};

	nfv2::FrameParser::Result result;
	uint8_t* parsedIt;
	std::tie(result, parsedIt) = 
		frameParser.parse(buffer.begin(), buffer.end());

	if(result == nfv2::FrameParser::Result::Good)
	{
		const auto& frame = frameParser.getFrame();
		std::cout << "Frame good, "
			<< "address: " << (int)frame.address.getValue() << ", "
			<< "messages size: " << frame.messages.size() << '\n';

		int i = 0;
		for(const auto& message : frame.messages)
		{
			std::cout << "message#" << i++ << ":\n"
				<< "\tid: " << (int)message.id.getValue() << '\n'
				<< "\tdata length: " << message.data.size() << '\n'
				<< "\tdata: "
				<< std::hex << std::showbase;
			for(const auto data : message.data)
			{
				std::cout << (int)data << ", ";
			}
			std::cout << '\n';
		}
	}
	else if(result == nfv2::FrameParser::Result::Bad)
	{
		std::cout << "Frame bad\n";
	}
	else
	{
		std::cout << "Frame not yet determinated\n";
	}
}
