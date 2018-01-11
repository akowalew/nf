#pragma once

#include <cstdint>

#include <bitset>

#include "nfv2/msgs/types.hpp"

namespace nfv2 {

using DriveMisc = uint32_t;

constexpr int32_t SetSynchronized   = (1 << 0);
constexpr int32_t ResetSynchronized = (1 << 1);

struct SetDriveMiscCommand
{
	NFV2_COMMAND(0x1E)

	DriveMisc misc;
};

// no answer specified

} // namespace nfv2
