#pragma once

#include "comms/comms.h"
#include "nfv2/common/Field.hpp"

namespace nfv2 {
namespace field {

using MsgSizeType = std::uint8_t;

class MsgSizeField
	:	public common::Field
{
	// total length is two bytes
	static constexpr std::size_t TotalLength = 2 * sizeof(std::uint8_t);

public:
	using Tag = comms::field::tag::Int;

	using ValueType = MsgSizeType;

	// Length required to serialise current value
	std::size_t length() const
	{
		return TotalLength;
	}

	// Minimal length required to serialise any value this field may contain
	static constexpr std::size_t minLength()
	{
		return TotalLength;
	}

	// Maximal length required to serialise any value this field may contain.
	static constexpr std::size_t maxLength()
	{
		return TotalLength;
	}

	// Check validity of the internal value
	bool valid() const
	{
		return true;
	}

	// Bring field's value into the consistent state,
	// return true if the field's value has been updated, false otherwise
	bool refresh()
	{
		return true;
	}

	// Read field value from input data sequence, using any type of input iterator
	template <typename TIter>
	comms::ErrorStatus read(TIter& iter, std::size_t size)
	{
		if(size < length())
		{
			return comms::ErrorStatus::NotEnoughData;
		}

		const ValueType value = readData<ValueType>(iter);
		const ValueType negatedValue = readData<ValueType>(iter);
		if(value != static_cast<std::uint8_t>(~negatedValue))
		{
			return comms::ErrorStatus::ProtocolError;
		}

		_value = value - (2 * sizeof(std::uint8_t));

		return comms::ErrorStatus::Success;
	}

	// Write field value to output data sequence, using any type of output iterator
	template <typename TIter>
	comms::ErrorStatus write(TIter& iter, std::size_t size) const
	{
		if(size < length())
		{
			return comms::ErrorStatus::BufferOverflow;
		}

		const std::uint8_t value = _value + (2 * sizeof(std::uint8_t));
		const std::uint8_t negatedValue = ~value;

		writeData(value, iter);
		writeData(negatedValue, iter);

		return comms::ErrorStatus::Success;
	}

	ValueType& value()
	{
		return _value;
	}

	const ValueType& value() const
	{
		return _value;
	}

private:
	ValueType _value;
};

} // namespace field
} // namespace nfv2
