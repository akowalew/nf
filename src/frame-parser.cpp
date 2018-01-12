#include "nfv2/frame-parser.hpp"

#include <iostream>

namespace nfv2 {

void FrameParser::reset() noexcept
{
    _state = State::StartByte;
}

FrameParser::Result 
FrameParser::consume(uint8_t byte) noexcept
{
    switch(_state)
    {
        case State::StartByte:
            if(byte != '#')
            {
                return Result::Bad;
            }

            _state = State::FrameLength;
            
            return Result::Indeterminate;
        
        case State::FrameLength:
            if(byte > Frame::MaxLength)
            {
                return Result::Bad;
            }

            _frameLength = byte;
            _state = State::FrameLengthBitwiseNegated;

            return Result::Indeterminate;

        case State::FrameLengthBitwiseNegated:
            if(byte != static_cast<uint8_t>(~_frameLength))
            {
                return Result::Bad;
            }

            _state = State::Address;

            return Result::Indeterminate;

        case State::Address:
            _frame.address = Address(byte);
            _crc.init(byte); // calculate CRC from address to last's message last data
            _state = State::MessageId;
            _bytesCount = 4; // four bytes processed from now

            return Result::Indeterminate;

        case State::MessageId:
            if(_bytesCount++ >= _frameLength)
            {
                return Result::Bad;
            }

            _message.id = Id(byte);
            _crc.step(byte);
            _state = State::MessageDataLength;
            
            return Result::Indeterminate;

        case State::MessageDataLength:
            if(_bytesCount++ >= _frameLength
                || byte > Message::MaxDataLength)
            {
                return Result::Bad;
            }

            _message.data.resize(byte);
            _crc.step(byte);

            if(byte != 0) // non-zero message data length
            {
                _bufferIdx = 0;
                _state = State::MessageData;
            }
            else // empty message data
            {
                _frame.messages.push_back(_message);
                if(_bytesCount == _frameLength) // this was the last message
                {
                    _state = State::Crc;
                }
                else // parse next message
                {
                    _state = State::MessageId;
                }
            }

            return Result::Indeterminate;

        case State::MessageData:
            if(_bytesCount++ >= _frameLength
                ||  _bufferIdx >= _message.data.size())
            {
                return Result::Bad;
            }

            _message.data[_bufferIdx++] = byte;
            _crc.step(byte);

            if(_bufferIdx == _message.data.size()) // if message data completed
            {
                if(_frame.messages.size() == Frame::MaxMessages)
                {
                    return Result::Bad;
                }

                _frame.messages.push_back(_message);
                if(_bytesCount == _frameLength) // this was the last message
                {
                    _state = State::Crc;
                }
                else // parse next message
                {
                    _state = State::MessageId;
                }
            }

            return Result::Indeterminate;
        
        case State::Crc:
            if(byte != _crc.getRemainder())
            {
                return Result::Bad;
            }

            return Result::Good;

        default:
        	assert(false && "Unexpected State in switch");
    }
}

} // namespace nfv2