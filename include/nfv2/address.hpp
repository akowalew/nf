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

	constexpr explicit Address(Rep value = 0)
		:	_value(value)
	{}

	constexpr operator Rep() const
	{
		return _value;
	}

	static constexpr Address Broadcast()
	{
		return Address(0xFF);
	}

	friend bool operator<(Address addr1, Address addr2);

private:
	Rep _value = 0;
};

inline bool operator<(Address addr1, Address addr2)
{
	return addr1._value < addr2._value;
}

} // namespace nfv2
