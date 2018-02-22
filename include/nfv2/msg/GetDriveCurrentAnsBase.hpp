#pragma once

#include "comms/comms.h"

#include "nfv2/common/MsgId.hpp"
#include "nfv2/common/MessageExtraOptions.hpp"
#include "nfv2/field/DriveCurrentField.hpp"

namespace nfv2 {
namespace msg {

// fields for GetDriveCurrentAns message
using GetDriveCurrentAnsFields =
	std::tuple<
		field::DriveCurrentField
	>;

// declaration of GetDriveCurrentAnsBase message.
// Base class to implement client/server versions
template<typename TMessage, common::MessageMode TMessageMode>
class GetDriveCurrentAnsBase
	:	public comms::MessageBase<
			TMessage,
			comms::option::StaticNumIdImpl<common::MsgId::GetDriveCurrentMsgId>,
			comms::option::MsgType<GetDriveCurrentAnsBase<TMessage, TMessageMode>>,
			comms::option::FieldsImpl<GetDriveCurrentAnsFields>,
			typename common::MessageExtraOptions<TMessageMode>::Type
		>
{
public:

};

} // namespace msg
} // namespace nfv2
