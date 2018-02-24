#pragma once

#include "comms/comms.h"

#include "nfv2/common/MsgId.hpp"
#include "nfv2/common/AnswerExtraOptions.hpp"
#include "nfv2/field/DriveStatusField.hpp"

namespace nfv2 {
namespace msg {

// fields for GetDriveStatusAns message
using GetDriveStatusAnsFields =
	std::tuple<
		field::DriveStatusField
	>;

// declaration of GetDriveStatusAnsBase message.
// Base class to implement client/server versions
template<typename TMessage, common::MessageMode TMessageMode>
class GetDriveStatusAnsBase
	:	public comms::MessageBase<
			TMessage,
			comms::option::StaticNumIdImpl<common::MsgId::GetDriveStatusMsgId>,
			comms::option::MsgType<GetDriveStatusAnsBase<TMessage, TMessageMode>>,
			comms::option::FieldsImpl<GetDriveStatusAnsFields>,
			typename common::AnswerExtraOptions<TMessageMode>::Type
		>
{
public:
	COMMS_MSG_FIELDS_ACCESS(DriveStatus);
};

} // namespace msg
} // namespace nfv2
