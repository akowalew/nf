#include <iostream>
#include <array>

#include "nfv2/client.hpp"

using DataType = std::uint8_t;
using StorageType = std::array<DataType, 128>;
using WriteIteratorType = DataType*;
using ReadIteratorType = const DataType*;

using OutputMessageOptions =
	std::tuple<
		comms::option::WriteIterator<WriteIteratorType>
	>;

using InputMessageOptions =
	std::tuple<
		comms::option::ReadIterator<ReadIteratorType>
	>;

using SetDrivePWMCmd = nfv2::client::SetDrivePWMCmd<OutputMessageOptions>;

using ProtocolStack = nfv2::client::ProtocolStack<InputMessageOptions>;

void protocolStackWriteExample1()
{
	std::cout << "Making SetDrivePWMCmd message" << std::endl;
	SetDrivePWMCmd setDrivePWMCmd;
	setDrivePWMCmd.field_PWM().value() = 0x00AB;
	assert(setDrivePWMCmd.field_PWM().valid());

	std::cout << "Calculating required length for message... ";
	ProtocolStack protStack(nfv2::field::AddressField(0x01));

	const auto reqLen = protStack.length(setDrivePWMCmd);
	std::cout << reqLen << std::endl;

	std::cout << "Writing out data" << std::endl;
	StorageType outData;
	auto writeIter = &outData[0];
	const auto es = protStack.write(setDrivePWMCmd, writeIter, outData.max_size());
	std::cout << "ErrorStatus: " << static_cast<int>(es) << std::endl;
	assert(es == comms::ErrorStatus::Success);

	std::cout << "outData: " << std::endl;
	for(auto iter = outData.begin(); iter != writeIter; ++iter)
	{
		std::cout << std::hex << (int)*iter << ", ";
	}

	std::cout << std::endl;
}

int main()
{
	protocolStackWriteExample1();
}
