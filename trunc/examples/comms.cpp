#include <iostream>

#include "comms/comms.h"

#include "vector.h"

using FieldBase = comms::Field<comms::option::LittleEndian>;
using Int16Field = comms::field::IntValue<FieldBase, std::int16_t>;
using Int32Field = comms::field::IntValue<FieldBase, std::int32_t>;

using YearField =
	comms::field::IntValue<
		FieldBase,
		std::int16_t,
		comms::option::FixedLength<1>,
		comms::option::NumValueSerOffset<-2000>
	>;

using DistanceField =
	comms::field::IntValue<
		FieldBase,
		std::uint16_t,
		comms::option::ScalingRatio<1, 1000>
	>;

enum class Baud : std::uint8_t
{
	_9600,
	_14400,
	_19200,
	_28800,
	_38400,
	_57600,
	_115200
};

using BaudField =
	comms::field::EnumValue<
		FieldBase,
		Baud
	>;

struct Bitmask
	:	public comms::field::BitmaskValue<
			FieldBase,
			comms::option::FixedLength<1>,
			comms::option::BitmaskReservedBits<0x2>
		>
{
	COMMS_BITMASK_BITS(first, third=2, fourth, fifth, sixth, seventh, eighth);
	COMMS_BITMASK_BITS_ACCESS(first, third, fourth, fifth, sixth, seventh, eighth);
};

enum class Parity : std::uint8_t
{
	None,
	Odd,
	Even
};

using SerialConfig =
	comms::field::Bitfield<
		FieldBase,
		std::tuple<
			comms::field::EnumValue<
				FieldBase,
				Baud,
				comms::option::FixedBitLength<3>
			>,
			comms::field::EnumValue<
				FieldBase,
				Parity,
				comms::option::FixedBitLength<2>
			>,
			comms::field::BitmaskValue<
				FieldBase,
				comms::option::FixedBitLength<3>
			>
		>
	>;

using SeqLengthField =
	comms::field::IntValue<
		FieldBase,
		std::uint8_t
	>;

using SomeBitmask =
	comms::field::BitmaskValue<
		FieldBase,
		comms::option::FixedLength<1>
	>;

using List =
	comms::field::ArrayList<
		FieldBase,
		comms::field::IntValue<
			FieldBase,
			std::uint16_t
		>,
		comms::option::FixedSizeStorage<10>,
		comms::option::SequenceSizeForcingEnabled
	>;

static const std::uint8_t SerData[] = { 15 };
static const std::size_t SerDataLen = std::extent<decltype(SerData)>::value;

void readYear()
{
	YearField year;
	auto* it = &SerData[0];
	auto es = year.read(it, SerDataLen);
	assert(es == comms::ErrorStatus::Success);
	std::cout << year.value() << std::endl;
}

void writeYear()
{
	YearField year;
	year.value() = 2016;
	std::vector<std::uint8_t> outData;
	auto writeIter = std::back_inserter(outData);
	auto es = year.write(writeIter, outData.max_size());
	assert(es == comms::ErrorStatus::Success);
	assert(outData.size() == 1U);
	assert(outData[0] == 16);
}

static const std::uint8_t InData[] = { 0xE8, 0x03 }; // 1000
static const std::size_t InDataSize = std::extent<decltype(InData)>::value;

void readDistance()
{
	DistanceField dist;
	const auto* readIter = &InData[0];
	const auto es = dist.read(readIter, InDataSize);
	assert(es == comms::ErrorStatus::Success);

	std::cout << "Distance mm: " << dist.value() << '\n';
	std::cout << "Distance m: " << dist.getScaled<float>() << std::endl;

	dist.setScaled(2.3);
	std::cout << "New distance mm: " << dist.value() << std::endl;
}

void writeBaud()
{
	BaudField baud;
	baud.value() = Baud::_115200;

	std::vector<std::uint8_t> outData;
	auto writeIter = std::back_inserter(outData);
	const auto es = baud.write(writeIter, outData.max_size());
	assert(es == comms::ErrorStatus::Success);
	assert(outData.size() == 1);
	assert(outData[0] == static_cast<std::uint8_t>(Baud::_115200));
}

void writeBitmask()
{
	std::clog << "Writing bitmask..." << std::endl;

	Bitmask bitmask;
	bitmask.setBitValue(Bitmask::BitIdx_first, true);
	bitmask.setBitValue_eighth(true);

	std::vector<std::uint8_t> outData;
	auto writeIter = std::back_inserter(outData);
	const auto es = bitmask.write(writeIter, outData.max_size());
	assert(es == comms::ErrorStatus::Success);
	assert(outData.size() == 1);
	assert(outData[0] == 0x81);

	std::clog << "done" << std::endl;
}

void writeSerialConfig()
{
	std::clog << "Writing serial config..." << std::endl;

	SerialConfig serialConfig;

	auto& [baud, parity, flags] = serialConfig.value();

	baud.value() = Baud::_115200; // =6
	parity.value() = Parity::Even; // =2
	flags.value() = 0x2;

	std::vector<std::uint8_t> outData; // Pretend output buffer
	auto writeIter = std::back_inserter(outData);
	const auto es = serialConfig.write(writeIter, outData.max_size());
	assert(es == comms::ErrorStatus::Success); // No error is expected
	assert(outData.size() == 1); // Single byte output is expected
	assert(outData[0] == 0x56); // Binary value split to 3-2-3 bits: 010|10|110

	std::clog << "done" << std::endl;
}

int main()
{
	writeSerialConfig();
}
