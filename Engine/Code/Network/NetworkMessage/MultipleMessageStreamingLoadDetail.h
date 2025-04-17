/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:10)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_LOAD_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_LOAD_DETAIL_H

#include "MessageSourceDetail.h"
#include "MultipleMessageContainer.h"
#include "MultipleMessageStreamingLoad.h"

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageStreamingLoad<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::MultipleMessageStreamingLoad() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

#include SYSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
bool Network::MultipleMessageStreamingLoad<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
void Network::MultipleMessageStreamingLoad<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::Load(MultipleMessageContainerType& container, MessageSource& source) const
{
    NETWORK_CLASS_IS_VALID_9;

    ParentType::Load(container, source);

    using ValueType = typename MultipleMessageCast<MultipleMessageElement<Index - 1, MultipleMessageContainerType>::byteType>::ValueType;

    ValueType value{};
    source.Read(value);

    container.template SetValue<Index - 1>(value);
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageStreamingLoad<1, Network::MultipleMessageContainer<E, ByteType, Types...>>::MultipleMessageStreamingLoad() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
bool Network::MultipleMessageStreamingLoad<1, Network::MultipleMessageContainer<E, ByteType, Types...>>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
void Network::MultipleMessageStreamingLoad<1, Network::MultipleMessageContainer<E, ByteType, Types...>>::Load(MultipleMessageContainerType& container, MessageSource& source) const
{
    NETWORK_CLASS_IS_VALID_9;

    using ValueType = typename MultipleMessageCast<MultipleMessageElement<0, MultipleMessageContainerType>::byteType>::ValueType;

    ValueType value{};
    source.Read(value);

    container.SetValue<0>(value);
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_LOAD_DETAIL_H