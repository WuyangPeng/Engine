//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 11:39)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SAVE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SAVE_DETAIL_H

#include "MessageTargetDetail.h"
#include "MultipleMessageContainer.h"
#include "MultipleMessageStreamingSave.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageStreamingSave<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::MultipleMessageStreamingSave()
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
bool Network::MultipleMessageStreamingSave<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <int Index, typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
void Network::MultipleMessageStreamingSave<Index, Network::MultipleMessageContainer<E, ByteType, Types...>>::Save(const MultipleMessageContainer& container, const MessageTargetSharedPtr& target) const
{
    ParentType::Save(container, target);

    auto value = container.GetValue<System::UnderlyingCastEnum<E>(Index - 1)>();
    target->Write(value);
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageStreamingSave<1, Network::MultipleMessageContainer<E, ByteType, Types...>>::MultipleMessageStreamingSave()
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
void Network::MultipleMessageStreamingSave<1, Network::MultipleMessageContainer<E, ByteType, Types...>>::Save(const MultipleMessageContainer& container, const MessageTargetSharedPtr& target) const
{
    auto value = container.GetValue<System::UnderlyingCastEnum<E>(0)>();
    target->Write(value);
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SAVE_DETAIL_H