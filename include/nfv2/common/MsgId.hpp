#pragma once

#include <cstdint>

namespace nfv2 {
namespace common {

enum MsgId : std::uint8_t
{
	SetDriveModeMsgId = 0x10,
	SetDrivePwmMsgId = 0x14,
	SetDriveMaxCurrentMsgId = 0x15,
	GetDrivePositionMsgId = 0x1A,
	GetDriveCurrentMsgId = 0x1B,
	GetDriveStatusMsgId = 0x1F,
	SetDriveMiscMsgId = 0x1E
};

} // namespace common
} // namespace nfv2
