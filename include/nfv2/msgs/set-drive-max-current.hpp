#pragma once

#include <cstdint>

#include "nfv2/msgs/types.hpp"

namespace nfv2 {

using MaxCurrent = int16_t;

NFV2_COMMAND(SetDriveMaxCurrentCommand, 0x1F, NoAnswerTag)
    SetDriveMaxCurrentCommand() noexcept = default;

    constexpr explicit SetDriveMaxCurrentCommand(MaxCurrent maxCurrent) noexcept
        :   maxCurrent(maxCurrent)
    {}

	MaxCurrent maxCurrent;
NFV2_COMMAND_END;

} // namespace nfv2