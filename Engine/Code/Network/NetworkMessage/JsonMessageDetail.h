///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/06 14:56)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_JSON_MESSAGE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_JSON_MESSAGE_DETAIL_H

#include "JsonMessage.h"
#include "MessageSource.h"
#include "MessageTarget.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

template <typename T>
Network::JsonMessage<T>::JsonMessage(MessageHeadStrategy messageHeadStrategy, int64_t messageId, const std::string& message)
    : ParentType{ messageHeadStrategy, messageId }, message{ message }
{
    if (!IsUseJson())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("JsonMessage 只能使用Json消息创建。"))
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Network::JsonMessage<T>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
const CoreTools::Rtti& Network::JsonMessage<T>::GetRttiType() const noexcept
{
    return GetCurrentRttiType();
}

template <typename T>
const CoreTools::Rtti& Network::JsonMessage<T>::GetCurrentRttiType() noexcept
{
    static const auto rtti = CoreTools::Rtti{ typeid(T).name(), &ParentType::GetCurrentRttiType() };

    return rtti;
}

template <typename T>
Network::MessageInterfaceSharedPtr Network::JsonMessage<T>::Factory(MessageSource& source, MessageHeadStrategy messageHeadStrategy, int64_t messageId)
{
    auto object = std::make_shared<ClassType>(LoadConstructor::ConstructorLoader, messageHeadStrategy, messageId);

    object->Load(source);

    return object;
}

template <typename T>
Network::JsonMessage<T>::JsonMessage(LoadConstructor loadConstructor, MessageHeadStrategy messageHeadStrategy, int64_t messageId) noexcept
    : ParentType{ loadConstructor, messageHeadStrategy, messageId }, message{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

template <typename T>
T Network::JsonMessage<T>::GetJsonMessage() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return T{ message };
}

template <typename T>
void Network::JsonMessage<T>::Load(MessageSource& source)
{
    NETWORK_CLASS_IS_VALID_9;

    NETWORK_BEGIN_STREAM_LOAD(source);

    ParentType::Load(source);

    message = source.ReadString();

    NETWORK_END_STREAM_LOAD(source);
}

template <typename T>
void Network::JsonMessage<T>::Save(MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    NETWORK_BEGIN_STREAM_SAVE(target);

    ParentType::Save(target);

    target.WriteString(message);

    NETWORK_END_STREAM_SAVE(target);
}

template <typename T>
int Network::JsonMessage<T>::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize() + CoreTools::GetStreamSize(message);
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_JSON_MESSAGE_DETAIL_H
