/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:09)

#ifndef NETWORK_NETWORK_MESSAGE_INTEGER_MESSAGE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_INTEGER_MESSAGE_DETAIL_H

#include "IntegerMessage.h"
#include "MessageContainerDetail.h"
#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

template <typename E>
requires(std::is_enum_v<E>)
Network::IntegerMessage<E>::IntegerMessage(MessageHeadStrategy messageHeadStrategy, int64_t messageId, const IntegerType& message)
    : ParentType{ messageHeadStrategy, messageId }, message{ message }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename E>
requires(std::is_enum_v<E>) bool Network::IntegerMessage<E>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename E>
requires(std::is_enum_v<E>)
const CoreTools::Rtti& Network::IntegerMessage<E>::GetRttiType() const noexcept
{
    return GetCurrentRttiType();
}

template <typename E>
requires(std::is_enum_v<E>)
const CoreTools::Rtti& Network::IntegerMessage<E>::GetCurrentRttiType() noexcept
{
    static const auto rtti = CoreTools::Rtti{ typeid(ClassType).name(), &ParentType::GetCurrentRttiType() };

    return rtti;
}

template <typename E>
requires(std::is_enum_v<E>)
Network::MessageInterfaceSharedPtr Network::IntegerMessage<E>::Factory(MessageSource& source, MessageHeadStrategy messageHeadStrategy, int64_t messageId)
{
    auto object = std::make_shared<ClassType>(LoadConstructor::ConstructorLoader, messageHeadStrategy, messageId);

    object->Load(source);

    return object;
}

template <typename E>
requires(std::is_enum_v<E>)
Network::IntegerMessage<E>::IntegerMessage(LoadConstructor loadConstructor, MessageHeadStrategy messageHeadStrategy, int64_t messageId) noexcept
    : ParentType{ loadConstructor, messageHeadStrategy, messageId }, message{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

template <typename E>
requires(std::is_enum_v<E>)
void Network::IntegerMessage<E>::Load(MessageSource& source)
{
    NETWORK_CLASS_IS_VALID_9;

    NETWORK_BEGIN_STREAM_LOAD(source);

    ParentType::Load(source);

    message.Load(source);

    NETWORK_END_STREAM_LOAD(source);
}

template <typename E>
requires(std::is_enum_v<E>)
void Network::IntegerMessage<E>::Save(MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    NETWORK_BEGIN_STREAM_SAVE(target);

    ParentType::Save(target);

    message.Save(target);

    NETWORK_END_STREAM_SAVE(target);
}

template <typename E>
requires(std::is_enum_v<E>)
int Network::IntegerMessage<E>::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize() + message.GetStreamingSize();
}

template <typename E>
requires(std::is_enum_v<E>)
int32_t Network::IntegerMessage<E>::GetValue(E index) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return message.GetValue(index);
}

template <typename E>
requires(std::is_enum_v<E>)
int Network::IntegerMessage<E>::GetSize() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return message.GetSize();
}

#endif  // NETWORK_NETWORK_MESSAGE_INTEGER_MESSAGE_DETAIL_H