#pragma once

#include "comms/comms.h"

#include "nfv2/common/MsgId.hpp"
#include "nfv2/common/CommandExtraOptions.hpp"

namespace nfv2 {
namespace msg {

// fields for GetDrivePositionCmd message
using GetDrivePositionCmdFields =
	std::tuple<
		// this command has no fields
	>;

// declaration of GetDrivePositionCmdBase message.
// Base class to implement client/server versions
template<typename TMessage, common::MessageMode TMessageMode>
class GetDrivePositionCmdBase
	:	public comms::MessageBase<
			TMessage,
			comms::option::StaticNumIdImpl<common::MsgId::GetDrivePositionMsgId>,
			comms::option::MsgType<GetDrivePositionCmdBase<TMessage, TMessageMode>>,
			comms::option::FieldsImpl<GetDrivePositionCmdFields>,
			typename common::CommandExtraOptions<TMessageMode>::Type
		>
{
public:

};

} // namespace msg
} // namespace nfv2
