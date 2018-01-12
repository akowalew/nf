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
            if(byte != '#') // wrong start byte
            {
                return Result::Bad;
            }

            _state = State::FrameLength;
            
            return Result::Indeterminate;
        
        case State::FrameLength:
            if(byte > Frame::MaxLength) // wrong frame length
            {
                return Result::Bad;
            }

            _frameLength = byte;
            _state = State::FrameLengthBitwiseNegated;

            return Result::Indeterminate;

        case State::FrameLengthBitwiseNegated:
            if(byte != static_cast<uint8_t>(~_frameLength)) // wrong format
            {
                return Result::Bad;
            }

            _state = State::Address;

            return Result::Indeterminate;

        case State::Address:
            _frame = Frame{Address(byte)};
            _crc = Crc(byte); // calculate CRC from address to last's message last data
            _state = State::MessageId;
            _bytesCount = 4; // four bytes processed from now

            return Result::Indeterminate;

        case State::MessageId:
            if(_bytesCount++ >= _frameLength) // frame overflow
            {
                return Result::Bad;
            }

            _message = Message{Id(byte)};
            _crc->step(byte);
            _state = State::MessageDataLength;
            
            return Result::Indeterminate;

        case State::MessageDataLength:
            if(_bytesCount++ >= _frameLength // frame overflow
                || byte > Message::MaxDataLength) // message length too big
            {
                return Result::Bad;
            }

            _message->data.resize(byte);
            _crc->step(byte);

            if(byte != 0) // non-zero message data length
            {
                _dataIt = _message->data.begin();
                _state = State::MessageData;
            }
            else // empty message data
            {
                _frame->messages.push_back(*_message);
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
            if(_bytesCount++ >= _frameLength // frame overflow
                ||  _dataIt == _message->data.end()) // message overflow
            {
                return Result::Bad;
            }

            *(_dataIt++) = byte;
            _crc->step(byte);

            if(_dataIt == _message->data.end()) // message completed
            {
                if(_frame->messages.size() == Frame::MaxMessages) // messages overflow
                {
                    return Result::Bad;
                }

                _frame->messages.push_back(*_message);
                if(_bytesCount == _frameLength) // messages completed
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
            if(byte != _crc->getRemainder()) // wrong crc
            {
                return Result::Bad;
            }

            return Result::Good;

        default:
        	assert(false && "Unexpected State in switch");
    }
}

} // namespace nfv2