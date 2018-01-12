/**
 * frame.cpp
 * Contains implementation of Frame class
 * Author: akowalew
 */

#include "nfv2/frame.hpp"
#include "nfv2/crc.hpp"

namespace nfv2 {
	
size_t Frame::toBuffer(uint8_t* buffer, size_t size) const noexcept
{
	assert(!messages.empty());
	
	uint8_t frameLength = getLength();
	uint8_t frameSize = frameLength + 1; // + startByte
	assert(size >= frameSize);

	*(buffer++) = '#'; // start byte
	*(buffer++) = frameLength;
	*(buffer++) = ~frameLength;

	Crc crc(address.getValue());
	*(buffer++) = address.getValue();

	for(const auto& message : messages)
	{
		crc.step(message.id.getValue());
		*(buffer++) = message.id.getValue();

		const auto dataLength = message.data.size();
		crc.step(dataLength);
		*(buffer++) = dataLength;

		for(const auto& dataItem : message.data)
		{
			crc.step(dataItem);
			*(buffer++) = dataItem;
		}
	}

	*(buffer++) = crc.getRemainder();

	return frameSize;
}

uint8_t Frame::getLength() const noexcept
{
	uint8_t messagesLength = 0;
	for(const auto& message : messages)
	{
		messagesLength += message.data.size() + 2; // data + dataLength + id
	}

	uint8_t frameLength = messagesLength + 4; // FL + ~FL + ADDR + CRC + MsL
	return frameLength;
}

} // namespace nfv2
