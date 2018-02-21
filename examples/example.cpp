#include <vector>
#include <iostream>

#include "nfv2/client.hpp"
#include "nfv2/field/DriveStatusField.hpp"

using WriteIteratorType = std::back_insert_iterator<std::vector<std::uint8_t>>;

using OutputMessageOptions =
	std::tuple<
		comms::option::WriteIterator<WriteIteratorType>
	>;

using SetDrivePWMCmd = nfv2::client::SetDrivePWMCmd<OutputMessageOptions>;
using SetDriveModeCmd = nfv2::client::SetDriveModeCmd<OutputMessageOptions>;

void setDrivePWMCmdWriteExample()
{
	std::cout << "Making SetDrivePWMCmd message" << std::endl;
	SetDrivePWMCmd setDrivePWMCmd;
	setDrivePWMCmd.field_PWM().value() = 1000;
	assert(setDrivePWMCmd.field_PWM().valid());

	std::cout << "Writing message" << std::endl;
	std::vector<std::uint8_t> outData;
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

void setDriveModeCmdWriteExample()
{
	std::cout << "Making SetDriveModeCmd message" << std::endl;
	SetDriveModeCmd setDriveModeCmd;
	setDriveModeCmd.field_DriveMode().value() = nfv2::field::DriveMode::SyncPWM0;
	assert(setDriveModeCmd.field_DriveMode().valid());

	std::cout << "Writing out message" << std::endl;
	std::vector<std::uint8_t> outData;
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
	std::vector<std::uint8_t> outData;
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

int main()
{
	driveStatusFieldWriteExample();
}
