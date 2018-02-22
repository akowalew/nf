#pragma once

#include "comms/comms.h"

#include "nfv2/common/MsgId.hpp"
#include "nfv2/common/MessageExtraOptions.hpp"

namespace nfv2 {
namespace msg {

// fields for GetDriveStatusCmd message
using GetDriveStatusCmdFields =
	std::tuple<
		// command has no fields
	>;

// declaration of GetDriveStatusCmdBase message.
// Base class to implement client/server versions
template<typename TMessage, common::MessageMode TMessageMode>
class GetDriveStatusCmdBase
	:	public comms::MessageBase<
			TMessage,
			comms::option::StaticNumIdImpl<common::MsgId::GetDriveStatusMsgId>,
			comms::option::MsgType<GetDriveStatusCmdBase<TMessage, TMessageMode>>,
			comms::option::FieldsImpl<GetDriveStatusCmdFields>,
			typename common::MessageExtraOptions<TMessageMode>::Type
		>
{
public:

};

} // namespace msg
} // namespace nfv2
