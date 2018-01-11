#pragma once

#include <type_traits>
#include <cstring>

#include "nfv2/message.hpp"

namespace nfv2 {

struct CommandTag {};
struct AnswerTag {};

#define NFV2_COMMAND(CmdCode) \
public: \
    constexpr static auto CommandCode = CmdCode; \
    using MessageCategory = CommandTag; \
    \
    void writeMessage(Message& message) const \
    { \
        using ThisType = std::remove_pointer<decltype(this)>::type; \
	    message.code = CommandCode; \
	    message.data.resize(sizeof(ThisType)); \
	    \
	    static_assert(std::is_trivially_copyable<ThisType>::value, \
            "source type must be trivially copyable"); \
	    std::memcpy(message.data.data(), this, sizeof(ThisType)); \
    } \
    \
    bool tryReadMessage(const Message& message) \
    { \
        using ThisType = std::remove_pointer<decltype(this)>::type; \
	    if(message.code != CommandCode \
	        || message.data.size() != sizeof(ThisType)) \
	    { \
	        return false; \
	    } \
	    \
	    static_assert(std::is_trivially_copyable<ThisType>::value, \
            "target type must be trivially copyable"); \
	    std::memcpy(this, message.data.data(), sizeof(ThisType)); \
	    return true; \
    } \
    \
    operator Message() const \
    { \
        Message message; \
        writeMessage(message); \
        return message; \
    } \

#define NFV2_ANSWER(AnsCode) \
public: \
    constexpr static auto AnswerCode = AnsCode; \
    using MessageCategory = AnswerTag; \
    \
    void writeMessage(Message& message) const \
    { \
        using ThisType = std::remove_pointer<decltype(this)>::type; \
	    message.code = AnswerCode; \
	    message.data.resize(sizeof(ThisType)); \
	    \
	    static_assert(std::is_trivially_copyable<ThisType>::value, \
            "source type must be trivially copyable"); \
	    std::memcpy(message.data.data(), this, sizeof(ThisType)); \
    } \
    \
    bool tryReadMessage(const Message& message) \
    { \
        using ThisType = std::remove_pointer<decltype(this)>::type; \
	    if(message.code != AnswerCode \
	        || message.data.size() != sizeof(ThisType)) \
	    { \
	        return false; \
	    } \
	    \
	    static_assert(std::is_trivially_copyable<ThisType>::value, \
            "target type must be trivially copyable"); \
	    std::memcpy(this, message.data.data(), sizeof(ThisType)); \
	    return true; \
    } \
    \
    operator Message() const \
    { \
        Message message; \
        writeMessage(message); \
        return message; \
    } \

} // nfv2
