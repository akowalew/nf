/**
 * request.hpp
 * Contains declaration of Request class
 * Author: akowalew
 */

#pragma once

#include <array>

#include "nfv2/address.hpp"
#include "nfv2/command.hpp"

namespace nfv2 {

class Request
{
public:
	Request(Address address);

	void addCommand(const Command* command);

	size_t write(uint8_t* buffer, size_t size) const;
	size_t read(const uint8_t* buffer, size_t size);

private:
	size_t writeCommands(uint8_t* buffer, size_t size) const;

	const Address _address;
	std::array<const Command*, 10> _commands;
	int _commandsCount = 0;
};

} // namespace nfv2
