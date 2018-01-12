/**
 * id.hpp
 * Contains declaration of Id class
 * Author: akowalew
 */

#pragma once

#include <cstdint>

namespace nfv2 {

class Id
{
public:
	using Rep = uint8_t;

	constexpr explicit Id(Rep value = 0) noexcept
		:	_value(value)
	{}

	constexpr Rep getValue() const noexcept
	{
		return _value;
	}

	constexpr bool operator<(Id other) const noexcept
	{
		return _value < other._value;
	}

	constexpr bool operator==(Id other) const noexcept
	{
		return _value == other._value;
	}

	constexpr bool operator!=(Id other) const noexcept
	{
		return !(*this == other);
	}

private:
	Rep _value = 0;
};

} // namespace nfv2
