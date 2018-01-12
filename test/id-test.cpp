#include "UnitTest++/UnitTest++.h"

#include "nfv2/id.hpp"

using namespace nfv2;

SUITE(IdTest)
{
	TEST(Constructor)
	{
		const uint8_t value = 5;
		Id id(value);
		CHECK_EQUAL(id.getValue(), value);
		CHECK_EQUAL(id.getValue(), 5);
	}

	TEST(RelationalOperators)
	{
		const uint8_t value1 = 5;
		const uint8_t value2 = 10;
		const uint8_t value3 = 5;
		Id id1(value1);
		Id id2(value2);
		Id id3(value3);

		CHECK_EQUAL(value1 < value2, true);
		CHECK_EQUAL(id1 < id2, true);
		CHECK_EQUAL(id2 < id1, false);
		CHECK_EQUAL(id1 == id2, false);
		CHECK_EQUAL(id2 == id1, false);
		CHECK_EQUAL(id1 != id2, true);
		CHECK_EQUAL(id2 != id1, true);

		CHECK_EQUAL(value1 == value3, true);
		CHECK_EQUAL(id1 < id3, false);
		CHECK_EQUAL(id3 < id1, false);
		CHECK_EQUAL(id1 == id3, true);
		CHECK_EQUAL(id3 == id1, true);
		CHECK_EQUAL(id1 != id3, false);
		CHECK_EQUAL(id3 != id1, false);	
	}

	TEST(CopyConstructor)
	{
		const uint8_t value = 5;
		Id id1(value);
		Id id2(id1);
		CHECK(id1 == id2);
	}

	TEST(AssignOperator)
	{
		const uint8_t value = 5;
		const uint8_t value2 = 8;
		Id id1(value);
		Id id2(value2);
		id1 = id2;
		CHECK(id1 == id2);

		id2 = id1;
		CHECK(id1 == id2);
	}
}

int main(int, const char *[])
{
   return UnitTest::RunAllTests();
}