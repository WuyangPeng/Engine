///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 18:31)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_DOUBLE_MESSAGE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_DOUBLE_MESSAGE_DETAIL_H

#include "MessageContainerDetail.h"
#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "MultipleDoubleMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleDoubleMessage<E, ByteType, Types...>::MultipleDoubleMessage(int64_t messageID, const MessageType& messageType)
    : ParentType{ messageID }, message{ messageType }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
template <typename T, typename... OtherTypes>
Network::MultipleDoubleMessage<E, ByteType, Types...>::MultipleDoubleMessage(int64_t messageID, T value, OtherTypes&&... otherValue)
    : ParentType{ messageID }, message{ value, std::forward<OtherTypes>(otherValue)... }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
bool Network::MultipleDoubleMessage<E, ByteType, Types...>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
const CoreTools::Rtti& Network::MultipleDoubleMessage<E, ByteType, Types...>::GetRttiType() const noexcept
{
    return GetCurrentRttiType();
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
const CoreTools::Rtti& Network::MultipleDoubleMessage<E, ByteType, Types...>::GetCurrentRttiType() noexcept
{
    static const auto rtti = CoreTools::Rtti{ typeid(ClassType).name(), &ParentType::GetCurrentRttiType() };

    return rtti;
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MessageInterfaceSharedPtr Network::MultipleDoubleMessage<E, ByteType, Types...>::Factory(MessageSource& source, int64_t messageID)
{
    auto object = std::make_shared<ClassType>(LoadConstructor::ConstructorLoader, messageID);

    object->Load(source);

    return object;
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleDoubleMessage<E, ByteType, Types...>::MultipleDoubleMessage(LoadConstructor value, int64_t messageID) noexcept
    : ParentType{ value, messageID }, message{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
void Network::MultipleDoubleMessage<E, ByteType, Types...>::Load(MessageSource& source)
{
    NETWORK_CLASS_IS_VALID_9;

    NETWORK_BEGIN_STREAM_LOAD(source);

    ParentType::Load(source);

    message.Load(source);

    NETWORK_END_STREAM_LOAD(source);
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
void Network::MultipleDoubleMessage<E, ByteType, Types...>::Save(MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    NETWORK_BEGIN_STREAM_SAVE(target);

    ParentType::Save(target);

    message.Save(target);

    NETWORK_END_STREAM_SAVE(target);
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
int Network::MultipleDoubleMessage<E, ByteType, Types...>::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize() + message.GetStreamingSize();
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
int Network::MultipleDoubleMessage<E, ByteType, Types...>::GetSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return message.GetSize();
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_DOUBLE_MESSAGE_DETAIL_H