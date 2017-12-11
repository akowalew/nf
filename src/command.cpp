/**
 * command.cpp
 * Contains implementation of class Command
 * Author: akowalew
 */

#include "nfv2/command.hpp"

#include <cassert>

namespace nfv2 {
	
Command::Command(uint8_t code, int8_t length)
	:	_code(code),
		_length(length)
{
	assert(length > 0);
	assert(length <= data.size());
}

size_t Command::write(uint8_t* buffer, size_t bufferSize) const
{
	*(buffer++) = _code;
	*(buffer++) = _length;

	for(int i = 0; i < _length; ++i)
	{
		buffer[i] = data[i];
	}

	return _length + 2;
}

} // namespace nfv2