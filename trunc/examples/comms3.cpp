#include "comms/comms.h"

enum MsgId : std::uint8_t
{

};

using Message =
	comms::Message<
		comms::option::LittleEndian,
		comms::option::MsgIdType<MsgId>
	>;

int main()
{

}
