/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:10)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SIZE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SIZE_DETAIL_H

#include "MultipleMessageContainer.h"
#include "MultipleMessageStreamingSize.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageStreamingSize<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::MultipleMessageStreamingSize() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

#include SYSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
bool Network::MultipleMessageStreamingSize<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
int Network::MultipleMessageStreamingSize<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::GetStreamingSize(const MultipleMessageContainerType& container) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    const auto value = container.template GetValue<System::UnderlyingCastEnum<E>(Index - 1)>();
    return ParentType::GetStreamingSize(container) + CoreTools::GetStreamSize(value);
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageStreamingSize<1, Network::MultipleMessageContainer<E, ByteType, Types...>>::MultipleMessageStreamingSize() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
bool Network::MultipleMessageStreamingSize<1, Network::MultipleMessageContainer<E, ByteType, Types...>>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
int Network::MultipleMessageStreamingSize<1, Network::MultipleMessageContainer<E, ByteType, Types...>>::GetStreamingSize(const MultipleMessageContainerType& container) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    const auto value = container.template GetValue<System::UnderlyingCastEnum<E>(0)>();

    return CoreTools::GetStreamSize(value);
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SIZE_DETAIL_H