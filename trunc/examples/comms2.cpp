#include "comms/comms.h"

#include <iostream>

using FieldBase =
	comms::Field<
		comms::option::LittleEndian
	>;

enum MsgId : std::uint8_t
{
	SetDrivePwmCmdId = 54
};

using MessageBase =
	comms::Message<
		comms::option::ReadIterator<const std::uint8_t*>,
		comms::option::MsgIdType<MsgId>
	>;

using MsgDataLayer =
	comms::protocol::MsgDataLayer<
	>;

using SetDrivePwmCmdFields =
	std::tuple<
		comms::field::IntValue<
			FieldBase,
			std::int16_t,
			comms::option::ValidNumValueRange<-1000, 1000>
		>
	>;

template<typename TMessage>
class SetDrivePwmCmd
	:	public comms::MessageBase<
			TMessage,
			comms::option::StaticNumIdImpl<MsgId::SetDrivePwmCmdId>,
			comms::option::MsgType<SetDrivePwmCmd<TMessage>>,
			comms::option::FieldsImpl<SetDrivePwmCmdFields>
		>
{};

using MsgIdField =
	comms::field::EnumValue<
		FieldBase,
		MsgId
	>;

using AllInputMessages =
	std::tuple<
		SetDrivePwmCmd<MessageBase>
	>;

using MsgIdLayer =
	comms::protocol::MsgIdLayer<
		MsgIdField,
		MessageBase,
		AllInputMessages,
		MsgDataLayer,
		comms::option::InPlaceAllocation
	>;

using MsgSizeField =
	comms::field::IntValue<
		FieldBase,
		std::uint8_t,
		comms::option::NumValueSerOffset<sizeof(std::uint8_t)>
	>;

using MsgSizeLayer =
	comms::protocol::MsgSizeLayer<
		MsgSizeField,
		MsgIdLayer
	>;

using ChecksumField =
	comms::field::IntValue<
		FieldBase,
		std::uint8_t
	>;

using ChecksumLayer =
	comms::protocol::ChecksumLayer<
		ChecksumField,
		comms::protocol::checksum::Crc_CCITT,
		MsgSizeLayer
	>;

using SyncPrefixField =
	comms::field::IntValue<
		FieldBase,
		std::uint8_t,
		comms::option::DefaultNumValue<'#'>
	>;

using SyncPrefixLayer =
	comms::protocol::SyncPrefixLayer<
		SyncPrefixField,
		ChecksumLayer
	>;

typedef SyncPrefixLayer ProtocolStack;
using MsgPtr = ProtocolStack::MsgPtr;

int main()
{
	ProtocolStack protStack;
	std::array<std::uint8_t, 32> dataToSend;

	SetDrivePwmCmd<MessageBase> msg;
	auto& [pwm] = msg.fields();
	pwm.value() = 0x00AB;

	auto writeIter = dataToSend.begin();
	auto es = protStack.write(msg, writeIter, dataToSend.size());

	std::cout << (int)es << std::endl;
	assert(es == comms::ErrorStatus::Success);

	std::cout << dataToSend.begin() - writeIter << std::endl;

	std::cout << "Written data: ";
	for(auto iter = dataToSend.begin(); iter != writeIter; ++iter)
	{
		std::cout << std::hex << (int)*iter << ", ";
	}
	std::cout << std::endl;
}




// using SetDriveModeCmd =
// 	comms::Message<
// 		comms::option::MsgIdType<MsgId>,
// 		comms::option::NoVirtualDestructor,
// 		comms::option::ReadIterator<const std::uint8_t*>,
// 		comms::option::WriteIterator<std::uint8_t*>,
// 		comms::option::LengthInfoInterface
// 	>;
