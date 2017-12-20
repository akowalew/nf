/**
 * frame-parser.hpp
 * Contains declaration of FrameParser class
 * Author: akowalew
 */

#pragma once

#include "nfv2/frame.hpp"
#include "nfv2/message.hpp"
#include "nfv2/crc.hpp"

namespace nfv2 {

class FrameParser
{
public:
    enum class Status
    {
        Unknown,
        Good,
        Bad
    };

    template<typename InputIterator>
    std::pair<Status, InputIterator> 
    parse(InputIterator begin, InputIterator end)
    {
        while(begin != end)
        {
            const auto status = consume(*begin++);
            if(status == Status::Good || status == Status::Bad)
            {
                _state = State::StartByte;
                return std::make_pair(status, begin);
            }
        }

        return std::make_pair(Status::Unknown, end);
    }

    const Frame& getFrame() const
    {
        return _frame;
    }

private:
    enum class State
    {
        StartByte,
        ContentLength,
        ContentLengthBitwiseNegated,
        Address,
        MessageCode,
        MessageDataLength,
        MessageData,
        Crc
    };

	Status consume(uint8_t byte);

    constexpr static bool 
    isContentLengthValid(uint8_t contentLength)
    {
        constexpr auto maxContentLength = 
        	1 + 1 + 1 + 1 + 1 // start + CL + ~CL + Addr
            + Frame::MaxMessages * (1 + 1 + Message::MaxDataBytes); // Code + Size + Data
        static_assert(maxContentLength <= std::numeric_limits<uint8_t>::max(),
        	"Maximum content length exceedes uint8_t values range");
        return contentLength <= maxContentLength;
    }

    State _state = State::StartByte;
    uint8_t _contentLength;
    uint8_t _bytesCount;
    Message _message;
    uint8_t _bufferIdx;
    Crc _crc;
    Frame _frame;
};

} // namespace nfv2
