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
		0x01, // message#0 code
		0x02, // message#0 data length
		0x01, // message#0 data byte#0
		0x02, // message#0 data byte#0
		0x48  // crc
	};

	nfv2::FrameParser::Status status;
	uint8_t* parsedIt;
	std::tie(status, parsedIt) = 
		frameParser.parse(buffer.begin(), buffer.end());

	if(status == nfv2::FrameParser::Status::Good)
	{
		const auto& frame = frameParser.getFrame();
		std::cout << "Frame good, "
			<< "address: " << (int)frame.address << ", "
			<< "messages size: " << frame.messages.size() << '\n';

		int i = 0;
		for(const auto& message : frame.messages)
		{
			std::cout << "message#" << i++ << ":\n"
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
	else if(status == nfv2::FrameParser::Status::Bad)
	{
		std::cout << "Frame bad\n";
	}
	else
	{
		std::cout << "Frame not yet determinated\n";
	}
}
