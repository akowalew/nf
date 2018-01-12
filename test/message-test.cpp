#include "UnitTest++/UnitTest++.h"

#include "nfv2/message.hpp"

using namespace nfv2;

SUITE(MessageTest)
{
	TEST(BraceInitializationIdOnly)
	{
		Id id(0xAB);
		Message message{id};

		// `id` should be copied and `data` should be empty
		CHECK(id == message.id);
		CHECK(message.data.empty());
	}

	TEST(BraceInitializationFull)
	{
		Id id(0xAB);
		Message::Data data;
		data.push_back(0x11);
		data.push_back(0x22);
		data.push_back(0x33);
		data.push_back(0x44);
		Message message{id, data};

		// both `id` and `data` should be copied
		CHECK(id == message.id);
		CHECK(data == message.data);
	}

	TEST(CopyConstructor)
	{
		Id id(0xAB);
		Message::Data data;
		data.push_back(0x11);
		data.push_back(0x22);
		data.push_back(0x33);
		data.push_back(0x44);
		Message message1{id, data};
		Message message2(message1);

		// both `id` and `data` should be copied
		CHECK(message1.id == message2.id);
		CHECK(message1.data == message2.data);
	}

	TEST(AssignmentOperator)
	{
		Id id1(0xAB);
		Message::Data data1;
		data1.push_back(0x11);
		data1.push_back(0x22);
		data1.push_back(0x33);
		data1.push_back(0x44);
		Message message1{id1, data1};

		Id id2(0xBA);
		Message::Data data2;
		data2.push_back(0x44);
		data2.push_back(0x33);
		data2.push_back(0x22);
		data2.push_back(0x11);
		Message message2{id2, data2};

		// at beginning, `id`s and `data`s are different
		CHECK(message1.id != message2.id);
		CHECK(message1.data != message2.data);

		message1 = message2;

		// both `id` and `data` should be copied
		CHECK(message1.id == message2.id);
		CHECK(message1.data == message2.data);
	}
}

int main(int, const char *[])
{
   return UnitTest::RunAllTests();
}
