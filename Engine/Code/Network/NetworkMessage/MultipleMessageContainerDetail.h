///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:04)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_DETAIL_H

#include "MultipleMessageContainer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/NetworkMessage/MultipleMessageInitValueDetail.h"
#include "Network/NetworkMessage/MultipleMessageStreamingLoadDetail.h"
#include "Network/NetworkMessage/MultipleMessageStreamingSaveDetail.h"
#include "Network/NetworkMessage/MultipleMessageStreamingSizeDetail.h"

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
Network::MultipleMessageContainer<E, ByteType, Types...>::MultipleMessageContainer() noexcept
    : message{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
template <typename T, typename... OtherTypes>
Network::MultipleMessageContainer<E, ByteType, Types...>::MultipleMessageContainer(T value, OtherTypes&&... otherValue)
    : message{}
{
    MultipleMessageInitValue<size, ClassType>(*this, value, std::forward<OtherTypes>(otherValue)...);

    NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>) bool Network::MultipleMessageContainer<E, ByteType, Types...>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
void Network::MultipleMessageContainer<E, ByteType, Types...>::Load(MessageSource& source)
{
    NETWORK_CLASS_IS_VALID_9;

    return MultipleMessageStreamingLoad<size, ClassType>{}.Load(*this, source);
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
void Network::MultipleMessageContainer<E, ByteType, Types...>::Save(MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return MultipleMessageStreamingSave<size, ClassType>{}.Save(*this, target);
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
int Network::MultipleMessageContainer<E, ByteType, Types...>::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return MultipleMessageStreamingSize<size, ClassType>{}.GetStreamingSize(*this);
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
template <int Index>
void Network::MultipleMessageContainer<E, ByteType, Types...>::SetValue(typename MultipleMessageParameterCast<MultipleMessageElement<Index, ClassType>::byteType>::ValueType value)
{
    NETWORK_CLASS_IS_VALID_9;

    static_assert(0 <= Index && Index < size, "The index is out of bounds.");

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    message[Index] = value;

#include SYSTEM_WARNING_POP
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
int Network::MultipleMessageContainer<E, ByteType, Types...>::GetSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(message.size());
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_DETAIL_H