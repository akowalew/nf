/**
 * frame-parser.hpp
 * Contains declaration of FrameParser class
 * Author: akowalew
 */

#pragma once

#include "optional.h"

#include "nfv2/frame.hpp"
#include "nfv2/message.hpp"
#include "nfv2/crc.hpp"

namespace nfv2 {

/**
 * Class for parsing byte stream to nfv2::Frame objects
 * It uses state machine to manage parsing process.
 */
class FrameParser
{
public:
    /**
     * Result type of `parse` method indicates status of parsing process
     * @see parse
     */
    enum class Result
    {
        Good,
        Bad,
        Indeterminate
    };  

    /**
     * @brief Main parsing routine
     * @details Applies every byte in input sequence into state machine.
     * It returns after first item, which causes Result either Good or Bad,
     * and resets state machine to the beginning
     * 
     * @param begin pointer to begin of input sequence
     * @param end pointer to end of input sequence
     * 
     * @return pair: result of parse process and position in byte stream,
     * at which it ended.
     */
    std::pair<Result, uint8_t*> 
    parse(uint8_t* begin, uint8_t* end) noexcept
    {
        while(begin != end)
        { 
            const auto status = consume(*begin++);
            if(status == Result::Good || status == Result::Bad)
            {
                reset();
                return std::make_pair(status, begin);
            }
        }

        return std::make_pair(Result::Indeterminate, end);
    }

    /**
     * @brief Resets state machine to the beginning
     */
    void reset() noexcept;

    /**
     * @brief Returns Frame currently processed by parses
     * @details It should be called only after getting Result::Good in
     * in parse method, otherwise returned frame may be invalid or incomplete
     */
    const Frame& getFrame() const noexcept
    {
        return *_frame;
    }

private:
    /**
     * @brief States of Parsing State Machine
     */
    enum class State
    {
        StartByte,
        FrameLength,
        FrameLengthBitwiseNegated,
        Address,
        MessageId,
        MessageDataLength,
        MessageData,
        Crc
    };

    /**
     * @brief Applies one byte to a parsing state machine
     * 
     * @param byte item to be parsed
     * @return current status of parsing
     */
	Result consume(uint8_t byte) noexcept;

    State _state = State::StartByte;
    uint8_t _frameLength;
    uint8_t _bytesCount;
    etl::optional<Message> _message;
    Message::Data::iterator _dataIt;
    etl::optional<Crc> _crc;
    etl::optional<Frame> _frame;
};

} // namespace nfv2
