#pragma once

#include "comms/comms.h"

namespace nfv2 {
namespace common {

using Field =
	comms::Field<
		comms::option::LittleEndian
	>;

} // namespace common
} // namespace nfv2
