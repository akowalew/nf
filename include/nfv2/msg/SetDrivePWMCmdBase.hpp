#pragma once

#include "comms/comms.h"

#include "nfv2/common/MsgId.hpp"
#include "nfv2/common/SetterExtraOptions.hpp"
#include "nfv2/field/PWMField.hpp"

namespace nfv2 {
namespace msg {

// fields for SetDrivePWMCmd message
using SetDrivePWMCmdFields =
	std::tuple<
		field::PWMField
	>;

// declaration of SetDrivePWMCmdBase message.
// Base class to implement client/server versions
template<typename TMessage, common::MessageMode TMessageMode>
class SetDrivePWMCmdBase
	:	public comms::MessageBase<
			TMessage,
			comms::option::StaticNumIdImpl<common::MsgId::SetDrivePwmMsgId>,
			comms::option::MsgType<SetDrivePWMCmdBase<TMessage, TMessageMode>>,
			comms::option::FieldsImpl<SetDrivePWMCmdFields>,
			typename common::SetterExtraOptions<TMessageMode>::Type
		>
{
public:
	COMMS_MSG_FIELDS_ACCESS(pwm);
};

} // namespace msg
} // namespace nfv2
