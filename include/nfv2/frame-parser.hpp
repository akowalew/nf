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
        Good,
        Bad,
        Indeterminate
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
                reset();
                return std::make_pair(status, begin);
            }
        }

        return std::make_pair(Status::Indeterminate, end);
    }

    void reset();

    const Frame& getFrame() const
    {
        return _frame;
    }

private:
    enum class State
    {
        StartByte,
        FrameLength,
        FrameLengthBitwiseNegated,
        Address,
        MessageCode,
        MessageDataLength,
        MessageData,
        Crc
    };

	Status consume(uint8_t byte);

    State _state = State::StartByte;
    uint8_t _frameLength;
    uint8_t _bytesCount;
    Message _message;
    uint8_t _bufferIdx;
    Crc _crc;
    Frame _frame;
};

} // namespace nfv2
