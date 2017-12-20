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

	constexpr explicit Address(Rep value)
		:	_value(value)
	{}

	constexpr operator Rep() const
	{
		return _value;
	}

	static constexpr Address makeBroadcast()
	{
		return Address(0xFF);
	}

	constexpr bool isBroadcast() const
	{
		return _value == 0xFF;
	}

private:
	friend bool operator<(Address addr1, Address addr2);

	Rep _value;
};

bool operator<(Address addr1, Address addr2)
{
	return addr1._value < addr2._value;
}

} // namespace nfv2
