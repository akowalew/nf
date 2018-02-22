#include <vector>
#include <iostream>

#include "nfv2/client.hpp"

using DataType = std::uint8_t;
using StorageType = std::vector<DataType>;
using WriteIteratorType = std::back_insert_iterator<StorageType>;
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
using SetDriveModeCmd = nfv2::client::SetDriveModeCmd<OutputMessageOptions>;
using GetDrivePositionCmd = nfv2::client::GetDrivePositionCmd<OutputMessageOptions>;
using GetDriveStatusAns = nfv2::client::GetDriveStatusAns<InputMessageOptions>;

using ProtocolStack = nfv2::client::ProtocolStack<InputMessageOptions>;

void setDrivePWMCmdWriteExample()
{
	std::cout << "Making SetDrivePWMCmd message" << std::endl;
	SetDrivePWMCmd setDrivePWMCmd;
	setDrivePWMCmd.field_PWM().value() = 1000;
	assert(setDrivePWMCmd.field_PWM().valid());

	std::cout << "Writing message" << std::endl;
	StorageType outData;
	auto writeIter = std::back_inserter(outData);
	const auto es = setDrivePWMCmd.write(writeIter, outData.max_size());
	assert(es == comms::ErrorStatus::Success);

	std::cout << "outData: ";
	for(const auto elem : outData)
	{
		std::cout << std::hex << (int)elem << ", ";
	}

	std::cout << std::endl;
}

void setDriveModeCmdWriteExampTOptionsle()
{
	std::cout << "Making SetDriveModeCmd message" << std::endl;
	SetDriveModeCmd setDriveModeCmd;
	setDriveModeCmd.field_DriveMode().value() = nfv2::field::DriveMode::SyncPWM0;
	assert(setDriveModeCmd.field_DriveMode().valid());

	std::cout << "Writing out message" << std::endl;
	StorageType outData;
	auto writeIter = std::back_inserter(outData);
	const auto es = setDriveModeCmd.write(writeIter, outData.max_size());
	assert(es == comms::ErrorStatus::Success);

	std::cout << "outData: ";
	for(const auto elem : outData)
	{
		std::cout << std::hex << (int)elem << ", ";
	}

	std::cout << std::endl;
}

void driveStatusFieldWriteExample()
{
	std::cout << "Making DriveStatusField" << std::endl;

	nfv2::field::DriveStatusField driveStatusField;
	driveStatusField.setBitValue_SpeedLimit(true);
	driveStatusField.setBitValue_Synchronized(true);
	driveStatusField.setBitValue_Error(true);
	driveStatusField.setBitValue_LimitSwitchUp(true);
	driveStatusField.setBitValue_LimitSwitchDown(true);
	driveStatusField.setBitValue_SynchroSwitch(true);
	assert(driveStatusField.valid());

	std::cout << "Writing out field" << std::endl;
	StorageType outData;
	auto writeIter = std::back_inserter(outData);
	const auto es = driveStatusField.write(writeIter, outData.max_size());
	assert(es == comms::ErrorStatus::Success);

	std::cout << "outData: ";
	for(const auto elem : outData)
	{
		std::cout << std::hex << (int)elem << ", ";
	}

	std::cout << std::endl;
}

void msgSizeFieldWriteExample()
{
	std::cout << "Making MsgSizeField" << std::endl;

	nfv2::field::MsgSizeField msgSizeField;
	msgSizeField.value() = 0xAB;
	assert(msgSizeField.valid());

	std::cout << "Writing out field" << std::endl;
	StorageType outData;
	auto writeIter = std::back_inserter(outData);
	const auto es = msgSizeField.write(writeIter, outData.max_size());
	assert(es == comms::ErrorStatus::Success);

	std::cout << "outData: ";
	for(const auto elem : outData)
	{
		std::cout << std::hex << (int)elem << ", ";
	}

	std::cout << std::endl;
}

void msgSizeFieldReadExample()
{
	static constexpr std::uint8_t Data[] = { 0xAB, 0x54 };
	static constexpr std::size_t DataLen = std::extent<decltype(Data)>::value;

	std::cout << "Reading MsgSizeField" << std::endl;
	nfv2::field::MsgSizeField msgSizeField;
	auto* readIter = &Data[0];
	const auto es = msgSizeField.read(readIter, DataLen);
	std::cout << static_cast<int>(es) << std::endl;
	assert(es == comms::ErrorStatus::Success);

	std::cout << "Value is: " << (int)msgSizeField.value() << std::endl;
}

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
	auto writeIter = std::back_inserter(outData);
	const auto es = protStack.write(setDrivePWMCmd, writeIter, outData.max_size());
	std::cout << "ErrorStatus: " << static_cast<int>(es) << std::endl;
	if(es == comms::ErrorStatus::UpdateRequired)
	{
		auto* updateIter = &outData[0];
		const auto updateEs = protStack.update(updateIter, outData.size());
		assert(updateEs == comms::ErrorStatus::Success);
	}

	std::cout << "outData: " << std::endl;
	for(const auto elem : outData)
	{
		std::cout << std::hex << (int)elem << ", ";
	}

	std::cout << std::endl;
}

void protocolStackWriteExample2()
{
	std::cout << "Making GetDrivePositionCmd message" << std::endl;
	GetDrivePositionCmd getDrivePositionCmd;
	// no members = no valid() method

	std::cout << "Calculating required length for message... ";
	ProtocolStack protStack(nfv2::field::AddressField(0x01));

	const auto reqLen = protStack.length(getDrivePositionCmd);
	std::cout << reqLen << std::endl;

	std::cout << "Writing out data" << std::endl;
	StorageType outData;
	auto writeIter = std::back_inserter(outData);
	const auto es = protStack.write(getDrivePositionCmd, writeIter, outData.max_size());
	// assert(es == comms::ErrorStatus::Success);

	if(es == comms::ErrorStatus::UpdateRequired)
	{
		auto* updateIter = &outData[0];
		const auto updateEs = protStack.update(updateIter, outData.size());
		assert(updateEs == comms::ErrorStatus::Success);
	}

	std::cout << "outData: ";
	for(const auto elem : outData)
	{
		std::cout << std::hex << (int)elem << ", ";
	}

	std::cout << std::endl;
}

int main()
{
	protocolStackWriteExample2();
}
