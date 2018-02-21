/**
 * address.hpp
 * Contains declaration of Address class
 * Author: akowalew
 */

#pragma once

#include <cstdint>

namespace nfv2 {

class Address
{
public:
	using Rep = uint8_t;

	constexpr explicit Address(Rep value) noexcept
		:	_value(value)
	{}

	static constexpr Address Broadcast() noexcept
	{
		return Address(0xFF);
	}

	constexpr Rep getValue() const noexcept
	{
		return _value;
	}

	constexpr bool operator<(Address other) noexcept
	{
		return _value < other._value;
	}

	constexpr bool operator==(Address other) const noexcept
	{
		return _value == other._value;
	}

	constexpr bool operator!=(Address other) const noexcept
	{
		return !(*this == other);
	}

private:
	Rep _value;
};

} // namespace nfv2
