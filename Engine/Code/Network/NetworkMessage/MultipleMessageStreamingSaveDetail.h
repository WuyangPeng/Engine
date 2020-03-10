// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 15:57)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SAVE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SAVE_DETAIL_H

#include "MultipleMessageStreamingSave.h"  
#include "MessageTargetDetail.h"
#include "MultipleMessageContainer.h"
#include "System/EnumOperator/EnumCastDetail.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

template<int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageStreamingSave<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>
	::MultipleMessageStreamingSave()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

template<int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageStreamingSave<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>
	::~MultipleMessageStreamingSave()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template<int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
bool Network::MultipleMessageStreamingSave<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template<int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
void Network::MultipleMessageStreamingSave<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>
	::Save(const MultipleMessageContainer& container, const MessageTargetSharedPtr& target) const
{
	ParentType::Save(container, target);

	auto value = container.GetValue<System::UnderlyingCastEnum<E>(Index - 1)>();
	target->Write(value);
}

template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageStreamingSave<1, Network::MultipleMessageContainer<E, ByteType, Types...>>
	::MultipleMessageStreamingSave()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageStreamingSave<1, Network::MultipleMessageContainer<E, ByteType, Types...>>
	::~MultipleMessageStreamingSave()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
bool Network::MultipleMessageStreamingSave<1, Network::MultipleMessageContainer<E, ByteType, Types...>>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
void Network::MultipleMessageStreamingSave<1, Network::MultipleMessageContainer<E, ByteType, Types...>>
	::Save(const MultipleMessageContainer& container, const MessageTargetSharedPtr& target) const
{
	auto value = container.GetValue<System::UnderlyingCastEnum<E>(0)>();
	target->Write(value);
}

#endif // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SAVE_DETAIL_H