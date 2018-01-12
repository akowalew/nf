#pragma once

#include <cstdint>

#include "nfv2/msgs/types.hpp"

namespace nfv2 {

using Current = int16_t;

NFV2_ANSWER(ReadDriveCurrentAnswer, 0x1B)
    ReadDriveCurrentAnswer() noexcept = default;

    constexpr explicit ReadDriveCurrentAnswer(Current current) noexcept
        :   current(current)
    {}

    Current current = 0;
NFV2_ANSWER_END;

NFV2_COMMAND(ReadDriveCurrentCommand, 0x1B, ReadDriveCurrentAnswer)
	// empty command
NFV2_COMMAND_END;

} // namespace nfv2