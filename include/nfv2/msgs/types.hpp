#pragma once

#include <type_traits>
#include <cstring>

#include "nfv2/message.hpp"

namespace nfv2 {

struct CommandTag {};
struct AnswerTag {};

#define NFV2_COMMAND(IdValue) \
public: \
    constexpr static auto CommandId = Id(IdValue); \
    using MessageCategory = CommandTag; \
    \
    void writeMessage(Message& message) const \
    { \
        using ThisType = std::remove_pointer<decltype(this)>::type; \
	    message.id = CommandId; \
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
	    if(message.id != CommandId \
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

#define NFV2_ANSWER(IdValue) \
public: \
    constexpr static auto AnswerId = Id(IdValue); \
    using MessageCategory = AnswerTag; \
    \
    void writeMessage(Message& message) const \
    { \
        using ThisType = std::remove_pointer<decltype(this)>::type; \
	    message.id = AnswerId; \
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
	    if(message.id != AnswerId \
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
