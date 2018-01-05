/**
 * example.cpp
 * Example of usage of NFv2 library in Slave mode
 * Author: akowalew
 */

#include <iostream>

#include "nfv2/nfv2.hpp"

int main()
{
	// nfv2::FrameParser frameParser;

	// nfv2::RequestHandler requestHandler;
	// requestHandler.addHandler(nfv2::Address(0x01), [](const auto& request, auto& response) {
	// 	std::cout << "Command 0x01" << std::endl;
	// 	return nfv2::RequestHandler::HandlerResult::NoResponse;
	// });

	// requestHandler.addHandler(nfv2::Address(0x02), [](const auto& request, auto& response) {
	// 	std::cout << "Command 0x02" << std::endl;
	// 	return nfv2::RequestHandler::HandlerResult::NoResponse;
	// });

	// requestHandler.addHandler(nfv2::Address(0x03), [](const auto& request, auto& response) {
	// 	std::cout << "Command 0x03" << std::endl;
	// 	return nfv2::RequestHandler::HandlerResult::NoResponse;
	// });

	// etl::array<uint8_t, 16> buffer = 
	// 	{ '#', 6, static_cast<uint8_t>(~6), 1, 1, 0, 144 };
	// nfv2::FrameParser::Status status;
	// std::tie(status, std::ignore) = 
	// 	frameParser.parse(buffer.begin(), buffer.end());

	// if(status == nfv2::FrameParser::Status::Good)
	// {
	// 	std::cout << "Handling request..." << std::endl;
	// 	const auto& request = frameParser.getFrame();
	// 	requestHandler.handle(request);
	// } 
	// else if(status == nfv2::FrameParser::Status::Bad)
	// {
	// 	std::cout << "Bad request" << std::endl;
	// }
	// else
	// {
	// 	std::cout << "Request not completed" << std::endl;
	// }
}