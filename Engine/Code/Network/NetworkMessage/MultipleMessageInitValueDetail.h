/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:10)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_INIT_VALUE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_INIT_VALUE_DETAIL_H

#include "MultipleMessageInitValue.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
template <typename T, typename... OtherT>
Network::MultipleMessageInitValue<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::MultipleMessageInitValue(MultipleMessageContainerType& container, T value, OtherT&&... otherValues)
    : ParentType{ container, std::forward<OtherT>(otherValues)... }
{
    container.template SetValue<MultipleMessageSize<MultipleMessageContainerType>::value - Index>(value);

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
Network::MultipleMessageInitValue<1, Network::MultipleMessageContainer<E, ByteType, Types...>>::MultipleMessageInitValue(MultipleMessageContainerType& container, T value)
{
    container.template SetValue<MultipleMessageSize<MultipleMessageContainerType>::value - 1>(value);

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