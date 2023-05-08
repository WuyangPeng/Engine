///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/08 09:33)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_DETAIL_H

#include "MessageContainerDetail.h"
#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "MultipleMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
Network::MultipleMessage<E, ByteType, Types...>::MultipleMessage(MessageHeadStrategy messageHeadStrategy, int64_t messageId, const MessageType& messageType)
    : ParentType{ messageHeadStrategy, messageId }, message{ messageType }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
template <typename T, typename... OtherTypes>
Network::MultipleMessage<E, ByteType, Types...>::MultipleMessage(MessageHeadStrategy messageHeadStrategy, int64_t messageId, T value, OtherTypes&&... otherValue)
    : ParentType{ messageHeadStrategy, messageId }, message{ value, std::forward<OtherTypes>(otherValue)... }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>) bool Network::MultipleMessage<E, ByteType, Types...>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
const CoreTools::Rtti& Network::MultipleMessage<E, ByteType, Types...>::GetRttiType() const noexcept
{
    return GetCurrentRttiType();
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
const CoreTools::Rtti& Network::MultipleMessage<E, ByteType, Types...>::GetCurrentRttiType() noexcept
{
    static const auto rtti = CoreTools::Rtti{ typeid(ClassType).name(), &ParentType::GetCurrentRttiType() };

    return rtti;
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
Network::MessageInterfaceSharedPtr Network::MultipleMessage<E, ByteType, Types...>::Factory(MessageSource& source, MessageHeadStrategy messageHeadStrategy, int64_t messageID)
{
    auto object = std::make_shared<ClassType>(LoadConstructor::ConstructorLoader, messageHeadStrategy, messageID);

    object->Load(source);

    return object;
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
Network::MultipleMessage<E, ByteType, Types...>::MultipleMessage(LoadConstructor value, MessageHeadStrategy messageHeadStrategy, int64_t messageID) noexcept
    : ParentType{ value, messageHeadStrategy, messageID }, message{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
void Network::MultipleMessage<E, ByteType, Types...>::Load(MessageSource& source)
{
    NETWORK_CLASS_IS_VALID_9;

    NETWORK_BEGIN_STREAM_LOAD(source);

    ParentType::Load(source);

    message.Load(source);

    NETWORK_END_STREAM_LOAD(source);
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
void Network::MultipleMessage<E, ByteType, Types...>::Save(MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    NETWORK_BEGIN_STREAM_SAVE(target);

    ParentType::Save(target);

    message.Save(target);

    NETWORK_END_STREAM_SAVE(target);
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
int Network::MultipleMessage<E, ByteType, Types...>::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize() + message.GetStreamingSize();
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
int Network::MultipleMessage<E, ByteType, Types...>::GetSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return message.GetSize();
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_DETAIL_H