#pragma once

#include "comms/comms.h"

#include "nfv2/common/MsgId.hpp"
#include "nfv2/common/CommandExtraOptions.hpp"
#include "nfv2/field/DriveModeField.hpp"

namespace nfv2 {
namespace msg {

// fields for SetDriveModeCmd message
using SetDriveModeCmdFields =
	std::tuple<
		field::DriveModeField
	>;

// declaration of SetDriveModeCmdBase message.
// Base class to implement client/server versions
template<typename TMessage, common::MessageMode TMessageMode>
class SetDriveModeCmdBase
	:	public comms::MessageBase<
			TMessage,
			comms::option::StaticNumIdImpl<common::MsgId::SetDriveModeMsgId>,
			comms::option::MsgType<SetDriveModeCmdBase<TMessage, TMessageMode>>,
			comms::option::FieldsImpl<SetDriveModeCmdFields>,
			typename common::CommandExtraOptions<TMessageMode>::Type
		>
{
public:
	COMMS_MSG_FIELDS_ACCESS(DriveMode);
};

} // namespace msg
} // namespace nfv2
