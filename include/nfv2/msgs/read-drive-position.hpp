#pragma once

#include <cstdint>

#include "nfv2/msgs/types.hpp"

namespace nfv2 {

using Position = int16_t;

NFV2_ANSWER(ReadDrivePositionAnswer, 0x1A)
    ReadDrivePositionAnswer() noexcept = default;

    constexpr explicit ReadDrivePositionAnswer(Position position) noexcept
        :   position(position)
    {}

    Position position = 0;
NFV2_ANSWER_END;

NFV2_COMMAND(ReadDrivePositionCommand, 0x1A, ReadDrivePositionAnswer)
	// empty command
NFV2_COMMAND_END;

} // namespace nfv2