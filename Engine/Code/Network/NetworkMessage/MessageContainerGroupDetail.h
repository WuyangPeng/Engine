//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 11:33)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_GROUP_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_GROUP_DETAIL_H

#include "MessageContainerDetail.h"
#include "MessageContainerGroup.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename E, typename T>
Network::MessageContainerGroup<E, T>::MessageContainerGroup()
    : m_Group{}
{
    NETWORK_SELF_CLASS_IS_VALID_3;
}

template <typename E, typename T>
Network::MessageContainerGroup<E, T>::MessageContainerGroup(const StructureType& group)
    : m_Group{}
{
    for (const auto& value : group)
    {
        if (value.size() != System::EnumCastUnderlying<size_t>(E::Count))
        {
            THROW_EXCEPTION(SYSTEM_TEXT("数组大小不符合。"));
        }

        m_Group.emplace_back(value);
    }

    NETWORK_SELF_CLASS_IS_VALID_3;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename E, typename T>
bool Network::MessageContainerGroup<E, T>::IsValid() const noexcept
{
    for (const auto& value : m_Group)
    {
        if (value.GetSize() != System::EnumCastUnderlying(E::Count))
            return false;
    }

    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename E, typename T>
void Network::MessageContainerGroup<E, T>::Load(const MessageSourceSharedPtr& source)
{
    NETWORK_CLASS_IS_VALID_3;

    int32_t size{ 0 };
    source->Read(size);

    m_Group.resize(size);
    for (auto& value : m_Group)
    {
        value.Load(source);
    }
}

template <typename E, typename T>
void Network::MessageContainerGroup<E, T>::Save(const MessageTargetSharedPtr& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_3;

    auto size = boost::numeric_cast<int32_t>(m_Group.size());
    target->Write(size);

    for (const auto& value : m_Group)
    {
        value.Save(target);
    }
}

template <typename E, typename T>
int Network::MessageContainerGroup<E, T>::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_3;

    auto streamingSize = CoreTools::GetStreamSize<int32_t>();

    for (const auto& value : m_Group)
    {
        streamingSize += value.GetStreamingSize();
    }

    return streamingSize;
}

template <typename E, typename T>
const typename Network::MessageContainerGroup<E, T>::ContainerType Network::MessageContainerGroup<E, T>::GetValue(int index) const
{
    NETWORK_CLASS_IS_VALID_CONST_3;

    return m_Group.at(index);
}

template <typename E, typename T>
int Network::MessageContainerGroup<E, T>::GetSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_3;

    return boost::numeric_cast<int>(m_Group.size());
}

template <typename E, typename T>
typename Network::MessageContainerGroup<E, T>::GroupConstIter Network::MessageContainerGroup<E, T>::begin() const
{
    NETWORK_CLASS_IS_VALID_CONST_3;

    return m_Group.begin();
}

template <typename E, typename T>
typename Network::MessageContainerGroup<E, T>::GroupConstIter Network::MessageContainerGroup<E, T>::end() const
{
    NETWORK_CLASS_IS_VALID_CONST_3;

    return m_Group.end();
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_GROUP_DETAIL_H