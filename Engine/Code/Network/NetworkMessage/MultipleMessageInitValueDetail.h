///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/06 17:49)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_INIT_VALUE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_INIT_VALUE_DETAIL_H

#include "MultipleMessageInitValue.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
template <typename T, typename... OtherT>
Network::MultipleMessageInitValue<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::MultipleMessageInitValue(MultipleMessageContainer& container, T value, OtherT&&... otherValues)
    : ParentType{ container, std::forward<OtherT>(otherValues)... }
{
    container.SetValue<MultipleMessageSize<MultipleMessageContainer>::value - Index>(value);

    NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
bool Network::MultipleMessageInitValue<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
template <typename T>
Network::MultipleMessageInitValue<1, Network::MultipleMessageContainer<E, ByteType, Types...>>::MultipleMessageInitValue(MultipleMessageContainer& container, T value)
{
    container.SetValue<MultipleMessageSize<MultipleMessageContainer>::value - 1>(value);

    NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
bool Network::MultipleMessageInitValue<1, Network::MultipleMessageContainer<E, ByteType, Types...>>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_INIT_VALUE_DETAIL_H