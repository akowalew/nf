/**
 * command.hpp
 * Contains declaration of Command class
 * Author: akowalew
 */

#pragma once

#include <array>
#include <cstdint>
#include <cstdlib>

namespace nfv2 {

using Data = std::array<uint8_t, 8>;

class Command
{
public:
	Command(uint8_t code, int8_t length);

	size_t write(uint8_t* buffer, size_t size) const;
	// size_t read(const uint8_t* buffer, size_t size);

	Data data;

private:
	const uint8_t _code;
	const int8_t _length;
};

} // namespace nfv2
