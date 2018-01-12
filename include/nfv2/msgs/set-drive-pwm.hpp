#pragma once

#include <cstdint>

#include "nfv2/msgs/types.hpp"

namespace nfv2 {

using Pwm = int16_t;
	
NFV2_COMMAND(SetDrivePwmCommand, 0x14, NoAnswerTag)
    SetDrivePwmCommand() noexcept = default;

    constexpr explicit SetDrivePwmCommand(Pwm pwm) noexcept
        :   pwm(pwm)
    {}

	Pwm pwm;
NFV2_COMMAND_END;

} // namespace nfv2