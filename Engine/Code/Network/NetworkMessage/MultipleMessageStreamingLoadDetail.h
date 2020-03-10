// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 15:57)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_LOAD_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_LOAD_DETAIL_H

#include "MultipleMessageStreamingLoad.h" 
#include "MessageSourceDetail.h"
#include "MultipleMessageContainer.h"
#include "System/EnumOperator/EnumCastDetail.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

template<int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageStreamingLoad<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>
	::MultipleMessageStreamingLoad()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

template<int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageStreamingLoad<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>
	::~MultipleMessageStreamingLoad()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template<int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
bool Network::MultipleMessageStreamingLoad<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template<int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
void Network::MultipleMessageStreamingLoad<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>
	::Load(MultipleMessageContainer& container, const MessageSourceSharedPtr& source) const
{
	ParentType::Load(container, source);

	using ValueType = typename MultipleMessageCast<MultipleMessageElement<Index - 1, MultipleMessageContainer>::sm_ByteType>::ValueType;

	ValueType value{};
	source->Read(value);

	container.SetValue<Index - 1>(value);
}

template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageStreamingLoad<1, Network::MultipleMessageContainer<E, ByteType, Types...>>
	::MultipleMessageStreamingLoad()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageStreamingLoad<1, Network::MultipleMessageContainer<E, ByteType, Types...>>
	::~MultipleMessageStreamingLoad()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
bool Network::MultipleMessageStreamingLoad<1, Network::MultipleMessageContainer<E, ByteType, Types...>>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
void Network::MultipleMessageStreamingLoad<1, Network::MultipleMessageContainer<E, ByteType, Types...>>
	::Load(MultipleMessageContainer& container, const MessageSourceSharedPtr& source) const
{
	using ValueType = typename MultipleMessageCast<MultipleMessageElement<0, MultipleMessageContainer>::sm_ByteType>::ValueType;

	ValueType value{};
	source->Read(value);

	container.SetValue<0>(value);
}

#endif // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_LOAD_DETAIL_H