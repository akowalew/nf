/**
 * code.hpp
 * Contains declaration of Code class
 * Author: akowalew
 */

#pragma once

#include <cstdint>

namespace nfv2 {

class Code
{
public:
	using Rep = uint8_t;

	constexpr explicit Code(Rep value = 0) noexcept
		:	_value(value)
	{}

	constexpr Rep getValue() const noexcept
	{
		return _value;
	}

	constexpr bool operator<(Code other) const noexcept
	{
		return _value < other._value;
	}

	constexpr bool operator==(Code other) const noexcept
	{
		return _value == other._value;
	}

	constexpr bool operator!=(Code other) const noexcept
	{
		return !(*this == other);
	}

private:
	Rep _value = 0;
};

} // namespace nfv2
