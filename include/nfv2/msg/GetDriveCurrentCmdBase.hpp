#pragma once

#include "comms/comms.h"

#include "nfv2/common/MsgId.hpp"
#include "nfv2/common/MessageExtraOptions.hpp"

namespace nfv2 {
namespace msg {

// fields for GetDriveCurrentCmd message
using GetDriveCurrentCmdFields =
	std::tuple<
		// this command has no fields
	>;

// declaration of GetDriveCurrentCmdBase message.
// Base class to implement client/server versions
template<typename TMessage, common::MessageMode TMessageMode>
class GetDriveCurrentCmdBase
	:	public comms::MessageBase<
			TMessage,
			comms::option::StaticNumIdImpl<common::MsgId::GetDriveCurrentMsgId>,
			comms::option::MsgType<GetDriveCurrentCmdBase<TMessage, TMessageMode>>,
			comms::option::FieldsImpl<GetDriveCurrentCmdFields>,
			typename common::MessageExtraOptions<TMessageMode>::Type
		>
{
public:

};

} // namespace msg
} // namespace nfv2
