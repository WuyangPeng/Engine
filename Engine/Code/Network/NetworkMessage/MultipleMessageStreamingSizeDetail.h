///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/06 17:52)

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
int Network::MultipleMessageStreamingSize<1, Network::MultipleMessageContainer<E, ByteType, Types...>>::GetStreamingSize(const MultipleMessageContainer& container) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    const auto value = container.GetValue<System::UnderlyingCastEnum<E>(0)>();

    return CoreTools::GetStreamSize(value);
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SIZE_DETAIL_H