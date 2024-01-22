/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:10)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_GROUP_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_GROUP_DETAIL_H

#include "MultipleMessageContainerDetail.h"
#include "MultipleMessageContainerGroup.h"

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
Network::MultipleMessageContainerGroup<E, ByteType, Types...>::MultipleMessageContainerGroup() noexcept
    : group{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
Network::MultipleMessageContainerGroup<E, ByteType, Types...>::MultipleMessageContainerGroup(const GroupType& group)
    : group{ group }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>) bool Network::MultipleMessageContainerGroup<E, ByteType, Types...>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
void Network::MultipleMessageContainerGroup<E, ByteType, Types...>::Load(MessageSource& source)
{
    NETWORK_CLASS_IS_VALID_9;

    int32_t size{ 0 };
    source.Read(size);

    group.resize(size);
    for (auto& value : group)
    {
        value.Load(source);
    }
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
void Network::MultipleMessageContainerGroup<E, ByteType, Types...>::Save(MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto size = boost::numeric_cast<int32_t>(group.size());
    target.Write(size);

    for (const auto& value : group)
    {
        value.Save(target);
    }
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
int Network::MultipleMessageContainerGroup<E, ByteType, Types...>::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto streamingSize = CoreTools::GetStreamSize<int32_t>();

    for (const auto& value : group)
    {
        streamingSize += value.GetStreamingSize();
    }

    return streamingSize;
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
int Network::MultipleMessageContainerGroup<E, ByteType, Types...>::GetSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(group.size());
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
typename Network::MultipleMessageContainerGroup<E, ByteType, Types...>::MessageType Network::MultipleMessageContainerGroup<E, ByteType, Types...>::GetValue(int index) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return group.at(index);
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
typename Network::MultipleMessageContainerGroup<E, ByteType, Types...>::GroupConstIter Network::MultipleMessageContainerGroup<E, ByteType, Types...>::begin() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return group.begin();
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
requires(std::is_enum_v<E>)
typename Network::MultipleMessageContainerGroup<E, ByteType, Types...>::GroupConstIter Network::MultipleMessageContainerGroup<E, ByteType, Types...>::end() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return group.end();
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_GROUP_DETAIL_H