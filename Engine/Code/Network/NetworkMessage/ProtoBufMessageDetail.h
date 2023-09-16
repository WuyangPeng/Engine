///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:05)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_PROTO_BUF_MESSAGE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_PROTO_BUF_MESSAGE_DETAIL_H

#include "MessageSource.h"
#include "MessageTarget.h"
#include "ProtoBufMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

template <typename T>
requires(std::is_base_of_v<google::protobuf::Message, T>)
Network::ProtoBufMessage<T>::ProtoBufMessage(MessageHeadStrategy messageHeadStrategy, int64_t messageId, const T& message)
    : ParentType{ messageHeadStrategy, messageId }, length{ boost::numeric_cast<int>(message.ByteSizeLong()) }, message{ message }
{
    if (!IsUseProtoBuf())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("ProtoBufMessage 只能使用ProtoBuf消息创建。"))
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
requires(std::is_base_of_v<google::protobuf::Message, T>) bool Network::ProtoBufMessage<T>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
requires(std::is_base_of_v<google::protobuf::Message, T>)
const CoreTools::Rtti& Network::ProtoBufMessage<T>::GetRttiType() const noexcept
{
    return GetCurrentRttiType();
}

template <typename T>
requires(std::is_base_of_v<google::protobuf::Message, T>)
const CoreTools::Rtti& Network::ProtoBufMessage<T>::GetCurrentRttiType() noexcept
{
    static const auto rtti = CoreTools::Rtti{ typeid(T).name(), &ParentType::GetCurrentRttiType() };

    return rtti;
}

template <typename T>
requires(std::is_base_of_v<google::protobuf::Message, T>)
Network::MessageInterfaceSharedPtr Network::ProtoBufMessage<T>::Factory(MessageSource& source, MessageHeadStrategy messageHeadStrategy, int64_t messageId)
{
    auto object = std::make_shared<ClassType>(LoadConstructor::ConstructorLoader, messageHeadStrategy, messageId);

    object->Load(source);

    return object;
}

template <typename T>
requires(std::is_base_of_v<google::protobuf::Message, T>)
Network::ProtoBufMessage<T>::ProtoBufMessage(LoadConstructor loadConstructor, MessageHeadStrategy messageHeadStrategy, int64_t messageId) noexcept
    : ParentType{ loadConstructor, messageHeadStrategy, messageId }, length{}, message{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

template <typename T>
requires(std::is_base_of_v<google::protobuf::Message, T>)
T Network::ProtoBufMessage<T>::GetProtoBufMessage() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return message;
}

template <typename T>
requires(std::is_base_of_v<google::protobuf::Message, T>)
void Network::ProtoBufMessage<T>::Load(MessageSource& source)
{
    NETWORK_CLASS_IS_VALID_9;

    NETWORK_BEGIN_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(length);

    std::vector<char> buffer(length);
    source.Read(length, buffer.data());

    if (!message.ParseFromArray(buffer.data(), length))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("反序列化 Proto Buf 失败。"))
    }

    NETWORK_END_STREAM_LOAD(source);
}

template <typename T>
requires(std::is_base_of_v<google::protobuf::Message, T>)
void Network::ProtoBufMessage<T>::Save(MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    NETWORK_BEGIN_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(length);

    std::vector<char> buffer(length);
    if (message.SerializeToArray(buffer.data(), length))
    {
        target.WriteWithoutNumber(length, buffer.data());
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("序列化 Proto Buf 失败。"))
    }

    NETWORK_END_STREAM_SAVE(target);
}

template <typename T>
requires(std::is_base_of_v<google::protobuf::Message, T>)
int Network::ProtoBufMessage<T>::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize() + CoreTools::GetStreamSize(length) + length;
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_PROTO_BUF_MESSAGE_DETAIL_H
