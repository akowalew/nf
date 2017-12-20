/**
 * example.cpp
 * Example of usage of NFv2 library in Slave mode
 * Author: akowalew
 */

#include <iostream>

#include "nfv2/nfv2.hpp"

int main()
{
	nfv2::Frame request;
	nfv2::Message message;
	message.code = 0x01;
	message.data.push_back(0x02);
	message.data.push_back(0x03);

	request.address = 0x01;
	request.messages.push_back(message);

	nfv2::RequestHandler requestHandler;
	requestHandler.addHandler(0x01, [](const auto& request, auto& response) {
		std::cout << "Command 0x01" << std::endl;
		return nfv2::RequestHandler::HandlerResult::NoResponse;
	});

	requestHandler.addHandler(0x02, [](const auto& request, auto& response) {
		std::cout << "Command 0x02" << std::endl;
		return nfv2::RequestHandler::HandlerResult::NoResponse;
	});

	requestHandler.addHandler(0x03, [](const auto& request, auto& response) {
		std::cout << "Command 0x03" << std::endl;
		return nfv2::RequestHandler::HandlerResult::NoResponse;
	});

	std::cout << "Handle request..." << std::endl;
	requestHandler.handle(request);
}