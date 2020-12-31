//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 11:39)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_INIT_VALUE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_INIT_VALUE_DETAIL_H

#include "MultipleMessageInitValue.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
template <typename T, typename... OtherT>
Network::MultipleMessageInitValue<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::MultipleMessageInitValue(MultipleMessageContainer& container, T value, OtherT... otherValues)
    : ParentType{ container, otherValues... }
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