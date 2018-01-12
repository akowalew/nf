#include "UnitTest++/UnitTest++.h"

#include "nfv2/address.hpp"

using namespace nfv2;

SUITE(AddressTest)
{
	TEST(Constructor)
	{
		const uint8_t value = 5;
		Address address(value);
		CHECK_EQUAL(address.getValue(), value);
		CHECK_EQUAL(address.getValue(), 5);
	}

	TEST(RelationalOperators)
	{
		const uint8_t value1 = 5;
		const uint8_t value2 = 10;
		const uint8_t value3 = 5;
		Address address1(value1);
		Address address2(value2);
		Address address3(value3);

		CHECK_EQUAL(value1 < value2, true);
		CHECK_EQUAL(address1 < address2, true);
		CHECK_EQUAL(address2 < address1, false);
		CHECK_EQUAL(address1 == address2, false);
		CHECK_EQUAL(address2 == address1, false);
		CHECK_EQUAL(address1 != address2, true);
		CHECK_EQUAL(address2 != address1, true);

		CHECK_EQUAL(value1 == value3, true);
		CHECK_EQUAL(address1 < address3, false);
		CHECK_EQUAL(address3 < address1, false);
		CHECK_EQUAL(address1 == address3, true);
		CHECK_EQUAL(address3 == address1, true);
		CHECK_EQUAL(address1 != address3, false);
		CHECK_EQUAL(address3 != address1, false);	
	}

	TEST(BroadcastAddressValue)
	{
		Address broadcast = Address::Broadcast();
		CHECK_EQUAL(broadcast.getValue(), 0xFF);
	}
}

int main(int, const char *[])
{
   return UnitTest::RunAllTests();
}