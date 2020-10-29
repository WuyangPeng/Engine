//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 11:37)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_DETAIL_H

#include "MultipleMessageContainer.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/NetworkMessage/MultipleMessageInitValueDetail.h"
#include "Network/NetworkMessage/MultipleMessageStreamingLoadDetail.h"
#include "Network/NetworkMessage/MultipleMessageStreamingSaveDetail.h"
#include "Network/NetworkMessage/MultipleMessageStreamingSizeDetail.h"

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageContainer<E, ByteType, Types...>::MultipleMessageContainer()
    : m_Message{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
template <typename T, typename... OtherTypes>
Network::MultipleMessageContainer<E, ByteType, Types...>::MultipleMessageContainer(T value, OtherTypes... otherValue)
    : m_Message{}
{
    MultipleMessageInitValue<sm_Size, ClassType>(*this, value, otherValue...);

    NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
bool Network::MultipleMessageContainer<E, ByteType, Types...>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
void Network::MultipleMessageContainer<E, ByteType, Types...>::Load(const MessageSourceSharedPtr& source)
{
    NETWORK_CLASS_IS_VALID_9;

    return MultipleMessageStreamingLoad<sm_Size, ClassType>{}.Load(*this, source);
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
void Network::MultipleMessageContainer<E, ByteType, Types...>::Save(const MessageTargetSharedPtr& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return MultipleMessageStreamingSave<sm_Size, ClassType>{}.Save(*this, target);
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
int Network::MultipleMessageContainer<E, ByteType, Types...>::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return MultipleMessageStreamingSize<sm_Size, ClassType>{}.GetStreamingSize(*this);
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
template <int index>
void Network::MultipleMessageContainer<E, ByteType, Types...>::SetValue(typename MultipleMessageParameterCast<MultipleMessageElement<index, ClassType>::sm_ByteType>::ValueType value)
{
    NETWORK_CLASS_IS_VALID_9;

    static_assert(0 <= index && index < sm_Size, "The index is out of bounds.");

    m_Message[index] = value;
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
int Network::MultipleMessageContainer<E, ByteType, Types...>::GetSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Message.size());
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_DETAIL_H