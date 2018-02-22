#pragma once

#include "nfv2/protocol/SyncPrefixLayerBase.hpp"

namespace nfv2 {
namespace protocol {

template<typename TAllInputMessages, typename... TOptions>
class ProtocolStackBase
	:	public SyncPrefixLayerBase<
			TAllInputMessages,
			TOptions...
		>
{
	using Base = SyncPrefixLayerBase<
		TAllInputMessages,
		TOptions...
	>;

public:
	explicit ProtocolStackBase(field::AddressField addressField)
	{
		fixAddressField(addressField);
	}

private:
	void fixAddressField(field::AddressField addressField)
	{
		auto& msgSizeLayer = Base::nextLayer();
		auto& checksumLayer = msgSizeLayer.nextLayer();
		auto& addressLayer = checksumLayer.nextLayer();
		addressLayer.fixAddressField(addressField);
	}
};

} // namespace protocol
} // namespace nfv2
