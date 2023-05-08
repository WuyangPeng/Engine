///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.7 (2023/05/06 17:51)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SAVE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SAVE_DETAIL_H

#include "MessageTargetDetail.h"
#include "MultipleMessageContainer.h"
#include "MultipleMessageStreamingSave.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageStreamingSave<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::MultipleMessageStreamingSave() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
bool Network::MultipleMessageStreamingSave<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
void Network::MultipleMessageStreamingSave<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::Save(const MultipleMessageContainer& container, MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_9;

    ParentType::Save(container, target);

    const auto value = container.GetValue<System::UnderlyingCastEnum<E>(Index - 1)>();
    target.Write(value);
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageStreamingSave<1, Network::MultipleMessageContainer<E, ByteType, Types...>>::MultipleMessageStreamingSave() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
bool Network::MultipleMessageStreamingSave<1, Network::MultipleMessageContainer<E, ByteType, Types...>>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
void Network::MultipleMessageStreamingSave<1, Network::MultipleMessageContainer<E, ByteType, Types...>>::Save(const MultipleMessageContainer& container, MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_9;

    const auto value = container.GetValue<System::UnderlyingCastEnum<E>(0)>();
    target.Write(value);
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SAVE_DETAIL_H