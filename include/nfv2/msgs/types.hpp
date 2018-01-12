#pragma once

#include <type_traits>
#include <cstring>
#include "optional.h" // ETLCPP

#include "nfv2/message.hpp"

namespace nfv2 {

namespace impl {
    
struct EmptyTag {};
struct NonEmptyTag {};

template<typename T>
constexpr static size_t getSize(EmptyTag)
{
    return 0;
}

template<typename T>
constexpr static size_t getSize(NonEmptyTag)
{
    return sizeof(T);
}

template<Id::Rep IdValue, typename T>
void writeMessage(Message& message, const T& t)
{
    constexpr auto Size = getSize<T>(std::conditional_t<
        std::is_empty<T>::value, 
        EmptyTag, 
        NonEmptyTag>());
    message.data.resize(Size);

    static_assert(std::is_trivially_copyable<T>::value,
        "Source type must be trivially copyable");
    std::memcpy(message.data.data(), &t, Size);
}

template<Id::Rep IdValue, typename T>
bool tryReadMessage(const Message& message, T& t)
{
    constexpr auto Size = getSize<T>(std::conditional_t<
        std::is_empty<T>::value, 
        EmptyTag, 
        NonEmptyTag>());
    if(message.id != Id(IdValue) || message.data.size() != Size)
    {
        return false;
    }

    static_assert(std::is_trivially_copyable<T>::value,
        "Target type must be trivially copyable");
    std::memcpy(&t, message.data.data(), Size);
    return true;
}

} // namespace impl

struct NoAnswerTag {};

template<Id::Rep _IdValue>
struct Answer
{
    constexpr static auto IdValue = _IdValue;
};

template<Id::Rep _IdValue, typename AnswerT>
struct Command
{
    constexpr static auto IdValue = _IdValue;

    static_assert(std::is_base_of<Answer<_IdValue>, AnswerT>::value,
        "AnswerT must be derived from Answer");
    static_assert(IdValue == AnswerT::IdValue,
        "Id's of answer and command must be the same");

    template<typename ...Args>
    static AnswerT makeAnswer(Args&& ...args)
    {
        return AnswerT(std::forward<Args>(args)...);
    }
};

template<Id::Rep _IdValue>
struct Command<_IdValue, NoAnswerTag>
{
    constexpr static auto IdValue = _IdValue;
};

#define NFV2_ANSWER(AnswerType, IdValue) \
struct AnswerType \
    :   public Answer<IdValue> \
{ \
    using ThisType = AnswerType; \
    \
    void writeMessage(Message& message) const \
    { \
        impl::writeMessage<IdValue>(message, *this); \
    } \
    \
    bool tryReadMessage(const Message& message) \
    { \
        return impl::tryReadMessage<IdValue>(message, *this); \
    } \
    \
    Message toMessage() const \
    { \
        Message message{Id(IdValue)}; \
        writeMessage(message); \
        return message; \
    } \
    \
    static etl::optional<ThisType> \
    fromMessage(const Message& message) \
    { \
        ThisType cmd; \
        if(cmd.tryReadMessage(message)) \
        { \
            return cmd; \
        } \
        return etl::nullopt; \
    } \

#define NFV2_ANSWER_END \
}

#define NFV2_COMMAND(CommandType, IdValue, AnswerType) \
struct CommandType \
    :   public Command<IdValue, AnswerType> \
{ \
    using ThisType = CommandType; \
    \
    void writeMessage(Message& message) const \
    { \
        impl::writeMessage<IdValue>(message, *this); \
    } \
    \
    bool tryReadMessage(const Message& message) \
    { \
        return impl::tryReadMessage<IdValue>(message, *this); \
    } \
    \
    Message toMessage() const \
    { \
        Message message{Id(IdValue)}; \
        writeMessage(message); \
        return message; \
    } \
    \
    static etl::optional<ThisType> \
    fromMessage(const Message& message) \
    { \
        ThisType cmd; \
        if(cmd.tryReadMessage(message)) \
        { \
            return cmd; \
        } \
        return etl::nullopt; \
    } \

#define NFV2_COMMAND_END \
}

} // nfv2
