#pragma once

#include "comms/comms.h"

#include "nfv2/common/MsgId.hpp"
#include "nfv2/common/MessageExtraOptions.hpp"
#include "nfv2/field/DrivePositionField.hpp"

namespace nfv2 {
namespace msg {

// fields for GetDrivePositionAns message
using GetDrivePositionAnsFields =
	std::tuple<
		field::DrivePositionField
	>;

// declaration of GetDrivePositionAnsBase message.
// Base class to implement client/server versions
template<typename TMessage, common::MessageMode TMessageMode>
class GetDrivePositionAnsBase
	:	public comms::MessageBase<
			TMessage,
			comms::option::StaticNumIdImpl<common::MsgId::GetDrivePositionMsgId>,
			comms::option::MsgType<GetDrivePositionAnsBase<TMessage, TMessageMode>>,
			comms::option::FieldsImpl<GetDrivePositionAnsFields>,
			typename common::MessageExtraOptions<TMessageMode>::Type
		>
{
public:

};

} // namespace msg
} // namespace nfv2
