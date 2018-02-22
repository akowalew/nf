#pragma once

#include "comms/comms.h"

#include "nfv2/common/MsgId.hpp"
#include "nfv2/common/MessageExtraOptions.hpp"
#include "nfv2/field/DriveCurrentField.hpp"

namespace nfv2 {
namespace msg {

// fields for SetDriveMaxCurrentCmd message
using SetDriveMaxCurrentCmdFields =
	std::tuple<
		field::DriveCurrentField
	>;

// declaration of SetDriveMaxCurrentCmdBase message.
// Base class to implement client/server versions
template<typename TMessage, common::MessageMode TMessageMode>
class SetDriveMaxCurrentCmdBase
	:	public comms::MessageBase<
			TMessage,
			comms::option::StaticNumIdImpl<common::MsgId::SetDriveMaxCurrentMsgId>,
			comms::option::MsgType<SetDriveMaxCurrentCmdBase<TMessage, TMessageMode>>,
			comms::option::FieldsImpl<SetDriveMaxCurrentCmdFields>,
			typename common::MessageExtraOptions<TMessageMode>::Type
		>
{
public:
	COMMS_MSG_FIELDS_ACCESS(DriveMaxCurrent);
};

} // namespace msg
} // namespace nfv2
