/**
 * request.cpp
 * Contains implementation of Request class
 * Author: akowalew
 */

#include "nfv2/request.hpp"
#include "nfv2/crc.hpp"

#include <cassert>

namespace nfv2 {
	
Request::Request(Address address)
	:	_address(address)
{

}

void Request::addCommand(const Command* command)
{
	assert(_commandsCount < _commands.size());
	_commands[_commandsCount] = command;
	++_commandsCount;
}

size_t Request::write(uint8_t* buffer, size_t bufferSize) const
{
	size_t writtenBytes = writeCommands(buffer + 4, bufferSize - 4);

	// contentLength is the total length of message (without start-byte)
	uint8_t contentLength = 4 + writtenBytes;

	assert(static_cast<int>(bufferSize) >= contentLength + 1);
	
	buffer[0] = '#'; // start byte
	buffer[1] = contentLength;
	buffer[2] = ~contentLength;
	buffer[3] = _address;
	buffer[contentLength] = crcU8(buffer + 3, bufferSize - 3);

	return contentLength + 1;
}

size_t Request::writeCommands(uint8_t* buffer, size_t bufferSize) const
{
	int elapsedBytes = bufferSize;

	const Command* command = _commands[0];
	for(int i = 0; i < _commandsCount; ++i)
	{
		assert(elapsedBytes > 0);
		size_t writtenBytes = command->write(buffer, elapsedBytes);
		elapsedBytes -= writtenBytes;
		buffer += writtenBytes;
	}

	return bufferSize - elapsedBytes;
}

} // namespace nfv2

