#pragma once

#include "comms/comms.h"

#include "nfv2/common/MsgId.hpp"
#include "nfv2/common/CommandExtraOptions.hpp"
#include "nfv2/field/DriveMiscField.hpp"

namespace nfv2 {
namespace msg {

// fields for SetDriveMiscCmd message
using SetDriveMiscCmdFields =
	std::tuple<
		field::DriveMiscField
	>;

// declaration of SetDriveMiscCmdBase message.
// Base class to implement client/server versions
template<typename TMessage, common::MessageMode TMessageMode>
class SetDriveMiscCmdBase
	:	public comms::MessageBase<
			TMessage,
			comms::option::StaticNumIdImpl<common::MsgId::SetDriveMiscMsgId>,
			comms::option::MsgType<SetDriveMiscCmdBase<TMessage, TMessageMode>>,
			comms::option::FieldsImpl<SetDriveMiscCmdFields>,
			typename common::CommandExtraOptions<TMessageMode>::Type
		>
{
public:
	COMMS_MSG_FIELDS_ACCESS(DriveMisc);
};

} // namespace msg
} // namespace nfv2
