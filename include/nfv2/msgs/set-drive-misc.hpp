#pragma once

#include <cstdint>

#include <bitset>

#include "nfv2/msgs/types.hpp"

namespace nfv2 {

using DriveMisc = uint32_t;

constexpr int32_t SetSynchronized   = (1 << 0);
constexpr int32_t ResetSynchronized = (1 << 1);

NFV2_COMMAND(SetDriveDriveMiscCommand, 0x1E, NoAnswerTag)
    SetDriveDriveMiscCommand() noexcept = default;

    constexpr explicit SetDriveDriveMiscCommand(DriveMisc driveMisc) noexcept
        :   driveMisc(driveMisc)
    {}

	DriveMisc driveMisc;
NFV2_COMMAND_END;

} // namespace nfv2
