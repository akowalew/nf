#include "nfv2/frame-parser.hpp"

#include <iostream>

namespace nfv2 {

FrameParser::Status 
FrameParser::consume(uint8_t byte)
{
    switch(_state)
    {
        case State::StartByte:
	        std::cout << "StartByte\n";
            if(byte != '#')
            {
                return Status::Bad;
            }

            _state = State::ContentLength;
            
            return Status::Unknown;
        
        case State::ContentLength:
	        std::cout << "ContentLength\n";

            if(!isContentLengthValid(byte))
            {
                return Status::Bad;
            }

            _contentLength = byte;
            _state = State::ContentLengthBitwiseNegated;

            return Status::Unknown;

        case State::ContentLengthBitwiseNegated:
	        std::cout << "ContentLengthBitwiseNegated\n";

            if(byte != static_cast<uint8_t>(~_contentLength))
            {
                return Status::Bad;
            }

            _state = State::Address;

            return Status::Unknown;

        case State::Address:
	        std::cout << "Address\n";

            _frame.address = byte;
            _crc.init(byte); // calculate CRC from address to last's message last data
            _state = State::MessageCode;
            _bytesCount = 4; // four bytes processed from now

            return Status::Unknown;

        case State::MessageCode:
	        std::cout << "MessageCode\n";

            if(_bytesCount++ >= _contentLength)
            {
                return Status::Bad;
            }

            _message.code = byte;
            _crc.step(byte);
            _state = State::MessageDataLength;
            
            return Status::Unknown;

        case State::MessageDataLength:
	        std::cout << "MessageDataLength\n";

            if(_bytesCount++ >= _contentLength
                || byte > Message::MaxDataBytes)
            {
                return Status::Bad;
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
                if(_bytesCount == _contentLength) // this was the last message
                {
                    _state = State::Crc;
                }
                else // parse next message
                {
                    _state = State::MessageCode;
                }
            }

            return Status::Unknown;

        case State::MessageData:
	        std::cout << "MessageData\n";

            if(_bytesCount++ >= _contentLength
                ||  _bufferIdx >= _message.data.size())
            {
                return Status::Bad;
            }

            _message.data[_bufferIdx++] = byte;
            _crc.step(byte);

            if(_bufferIdx == _message.data.size()) // if message data completed
            {
                if(_frame.messages.size() == Frame::MaxMessages)
                {
                    return Status::Bad;
                }

                _frame.messages.push_back(_message);
                if(_bytesCount == _contentLength) // this was the last message
                {
                    _state = State::Crc;
                }
                else // parse next message
                {
                    _state = State::MessageCode;
                }
            }

            return Status::Unknown;
        
        case State::Crc:
	        std::cout << "Crc\n";
        
            if(byte != _crc.getRemainder())
            {
                return Status::Bad;
            }

            return Status::Good;

        default:
        	assert(false && "Unexpected State in switch");
    }
}

} // namespace nfv2