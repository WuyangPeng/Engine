//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 11:38)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_GROUP_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_GROUP_DETAIL_H

#include "MultipleMessageContainerDetail.h"
#include "MultipleMessageContainerGroup.h"

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageContainerGroup<E, ByteType, Types...>::MultipleMessageContainerGroup()
    : m_Group{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessageContainerGroup<E, ByteType, Types...>::MultipleMessageContainerGroup(const GroupType& group)
    : m_Group{ group }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
bool Network::MultipleMessageContainerGroup<E, ByteType, Types...>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
void Network::MultipleMessageContainerGroup<E, ByteType, Types...>::Load(const MessageSourceSharedPtr& source)
{
    NETWORK_CLASS_IS_VALID_9;

    int32_t size{ 0 };
    source->Read(size);

    m_Group.resize(size);
    for (auto& value : m_Group)
    {
        value.Load(source);
    }
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
void Network::MultipleMessageContainerGroup<E, ByteType, Types...>::Save(const MessageTargetSharedPtr& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto size = boost::numeric_cast<int32_t>(m_Group.size());
    target->Write(size);

    for (const auto& value : m_Group)
    {
        value.Save(target);
    }
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
int Network::MultipleMessageContainerGroup<E, ByteType, Types...>::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto streamingSize = CoreTools::GetStreamSize<int32_t>();

    for (const auto& value : m_Group)
    {
        streamingSize += value.GetStreamingSize();
    }

    return streamingSize;
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
int Network::MultipleMessageContainerGroup<E, ByteType, Types...>::GetSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Group.size());
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
const typename Network::MultipleMessageContainerGroup<E, ByteType, Types...>::MessageType Network::MultipleMessageContainerGroup<E, ByteType, Types...>::GetValue(int index) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Group.at(index);
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
typename Network::MultipleMessageContainerGroup<E, ByteType, Types...>::GroupConstIter Network::MultipleMessageContainerGroup<E, ByteType, Types...>::begin() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Group.begin();
}

template <typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
typename Network::MultipleMessageContainerGroup<E, ByteType, Types...>::GroupConstIter Network::MultipleMessageContainerGroup<E, ByteType, Types...>::end() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Group.end();
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_GROUP_DETAIL_H