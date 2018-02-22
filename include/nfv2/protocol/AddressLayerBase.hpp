#pragma once

#include "comms/comms.h"

#include "nfv2/field/AddressField.hpp"
#include "nfv2/protocol/MsgIdLayerBase.hpp"

namespace nfv2 {
namespace protocol {

//! forward declaration, used in friend declaration for AddressLayer
template<typename TAllInputMessages, typename ...TOptions>
class ProtocolStackBase;

template<typename TAllInputMessages, typename... TOptions>
class AddressLayerBase
	:	public comms::protocol::ProtocolLayerBase<
			field::AddressField,
			protocol::MsgIdLayerBase<TAllInputMessages, TOptions...>, // next layer
			AddressLayerBase<TAllInputMessages, TOptions...>
		>
{
public:
	template<typename TMsgPtr, typename TIter, typename TNextLayerReader>
	comms::ErrorStatus doRead(
		field::AddressField& addressField,
		TMsgPtr& msgPtr,
		TIter& iter,
		std::size_t size,
		std::size_t* missingSize,
		TNextLayerReader&& nextLayerReader)
	{
		const auto es = addressField.read(iter, size);
		if(es != comms::ErrorStatus::Success)
		{
			return es;
		}

		// address field must be the same, as fixed one
		if(addressField != _addressField)
		{
			return comms::ErrorStatus::InvalidMsgData;
		}

		assert(_addressField.length() == addressField.length());
		return nextLayerReader.read(msgPtr, iter,
			size - _addressField.length(), missingSize);
	}

	template<typename TMsg, typename TIter, typename TNextLayerWriter>
	comms::ErrorStatus doWrite(
		field::AddressField& addressField,
		const TMsg& msg,
		TIter& iter,
		std::size_t size,
		TNextLayerWriter&& nextLayerWriter) const
	{
		static_cast<void>(addressField);

		auto es = _addressField.write(iter, size);
		if(es != comms::ErrorStatus::Success)
		{
			return es;
		}

		return nextLayerWriter.write(msg, iter, size - _addressField.length());
	}

private:
	friend class ProtocolStackBase<TAllInputMessages, TOptions...>;

	void fixAddressField(field::AddressField addressField)
	{
		_addressField = addressField;
	}

	field::AddressField _addressField;
};

} // namespace protocol
} // namespace nfv2
