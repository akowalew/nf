#include <array>

#include "UnitTest++/UnitTest++.h"

#include "nfv2/crc.hpp"

using namespace nfv2;

constexpr auto Polynomial = 0xD8;  /* 11011 followed by 0's */
constexpr auto Width = (8 * sizeof(uint8_t));
constexpr auto TopBit = (1 << (Width - 1));

using CrcTable = std::array<uint8_t, 256>;

CrcTable generateCrcTable()
{
	CrcTable crcTable;

    // compute the remainder of each possible dividend.
    for(uint16_t dividend = 0; dividend < 256; ++dividend)
    {
        uint8_t remainder = dividend;
        
        // Perform modulo-2 division, a bit at a time.
        for (uint8_t b = 8; b > 0; --b)
        {
            // Try to divide the current data bit.
            if (remainder & TopBit)
            {
                remainder = (remainder << 1) ^ Polynomial;
            }
            else
            {
                remainder = (remainder << 1);
            }
        }
        // Store the result into the table.
        crcTable[dividend] = remainder;
    }

    return crcTable;
}

SUITE(CrcTest)
{
	TEST(Constructor)
	{
		// remainder should be initialized to a value from crc table
		const auto crcTable = generateCrcTable();
		for(int16_t value = 0x0000; value <= 0x00FF; ++value)
		{
			const auto u8value = static_cast<uint8_t>(value);
			const auto crc = Crc(u8value);
			CHECK_EQUAL(crc.getRemainder(), crcTable[u8value]);
		}
	}

	TEST(Stepping)
	{
		// each next step should do lookup to crcTable at: (value ^ remainder)
		const auto crcTable = generateCrcTable();
		for(int16_t value = 0x0000; value <= 0x00FF; ++value)
		{
			const auto u8value = static_cast<uint8_t>(value);
			for(int16_t stepValue = 0x0000; stepValue <= 0x00FF; ++stepValue)
			{
				const auto u8stepValue = static_cast<uint8_t>(stepValue);

				auto remainder = crcTable[u8value];
				remainder = crcTable[u8stepValue ^ remainder];

				Crc crc(u8value);
				crc.step(u8stepValue);
				CHECK_EQUAL(crc.getRemainder(), remainder);
			}
		}
	}
}

int main(int, const char *[])
{
   return UnitTest::RunAllTests();
}
