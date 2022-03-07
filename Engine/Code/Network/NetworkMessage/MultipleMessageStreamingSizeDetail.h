///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 19:26)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SIZE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SIZE_DETAIL_H

#include "MultipleMessageContainer.h"
#include "MultipleMessageStreamingSize.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageStreamingSize<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::MultipleMessageStreamingSize() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
bool Network::MultipleMessageStreamingSize<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
int Network::MultipleMessageStreamingSize<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::GetStreamingSize(const MultipleMessageContainer& container) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    const auto value = container.GetValue<System::UnderlyingCastEnum<E>(Index - 1)>();
    return ParentType::GetStreamingSize(container) + CORE_TOOLS_STREAM_SIZE(value);
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
int Network::MultipleMessageStreamingSize<1, Network::MultipleMessageContainer<E, ByteType, Types...>>::GetStreamingSize(const MultipleMessageContainer& container) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    const auto value = container.GetValue<System::UnderlyingCastEnum<E>(0)>();

    return CORE_TOOLS_STREAM_SIZE(value);
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SIZE_DETAIL_H