/**
 * example.cpp
 * Example of usage of NFv2 library in Master mode
 * Author: akowalew
 */

#include <iostream>

#include "nfv2/nfv2.hpp"

#include "array.h"

int main(int argc, char** argv)
{
	nfv2::FrameParser frameParser;

	etl::array<uint8_t, 16> buffer = { '#', 6, static_cast<uint8_t>(~6), 1, 1, 0, 12 };
	nfv2::FrameParser::Status status;
	std::tie(status, std::ignore) = 
		frameParser.parse(buffer.begin(), buffer.end());

	if(status == nfv2::FrameParser::Status::Good)
	{
		std::cout << "good" << std::endl;
	} 
	else if(status == nfv2::FrameParser::Status::Bad)
	{
		std::cout << "bad" << std::endl;
	}
	else
	{
		std::cout << "unknown" << std::endl;
	}
}