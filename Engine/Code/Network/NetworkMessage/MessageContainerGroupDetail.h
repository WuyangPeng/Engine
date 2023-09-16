///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:02)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_GROUP_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_GROUP_DETAIL_H

#include "MessageContainerDetail.h"
#include "MessageContainerGroup.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename E, typename T>
requires(std::is_enum_v<E>)
Network::MessageContainerGroup<E, T>::MessageContainerGroup() noexcept
    : group{}
{
    NETWORK_SELF_CLASS_IS_VALID_3;
}

template <typename E, typename T>
requires(std::is_enum_v<E>)
Network::MessageContainerGroup<E, T>::MessageContainerGroup(const StructureType& group)
    : group{}
{
    for (const auto& value : group)
    {
        if (value.size() != System::EnumCastUnderlying<size_t>(E::Count))
        {
            THROW_EXCEPTION(SYSTEM_TEXT("数组大小不符合。"));
        }

        this->group.emplace_back(value);
    }

    NETWORK_SELF_CLASS_IS_VALID_3;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename E, typename T>
requires(std::is_enum_v<E>) bool Network::MessageContainerGroup<E, T>::IsValid() const noexcept
{
    try
    {
        for (const auto& value : group)
        {
            if (value.GetSize() != System::EnumCastUnderlying(E::Count))
                return false;
        }

        return true;
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename E, typename T>
requires(std::is_enum_v<E>)
void Network::MessageContainerGroup<E, T>::Load(MessageSource& source)
{
    NETWORK_CLASS_IS_VALID_3;

    int32_t size{ 0 };
    source.Read(size);

    group.resize(size);
    for (auto& value : group)
    {
        value.Load(source);
    }
}

template <typename E, typename T>
requires(std::is_enum_v<E>)
void Network::MessageContainerGroup<E, T>::Save(MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_3;

    auto size = boost::numeric_cast<int32_t>(group.size());
    target.Write(size);

    for (const auto& value : group)
    {
        value.Save(target);
    }
}

template <typename E, typename T>
requires(std::is_enum_v<E>)
int Network::MessageContainerGroup<E, T>::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_3;

    auto streamingSize = CoreTools::GetStreamSize<int32_t>();

    for (const auto& value : group)
    {
        streamingSize += value.GetStreamingSize();
    }

    return streamingSize;
}

template <typename E, typename T>
requires(std::is_enum_v<E>)
typename Network::MessageContainerGroup<E, T>::ContainerType Network::MessageContainerGroup<E, T>::GetValue(int index) const
{
    NETWORK_CLASS_IS_VALID_CONST_3;

    return group.at(index);
}

template <typename E, typename T>
requires(std::is_enum_v<E>)
int Network::MessageContainerGroup<E, T>::GetSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_3;

    return boost::numeric_cast<int>(group.size());
}

template <typename E, typename T>
requires(std::is_enum_v<E>)
typename Network::MessageContainerGroup<E, T>::GroupConstIter Network::MessageContainerGroup<E, T>::begin() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_3;

    return group.begin();
}

template <typename E, typename T>
requires(std::is_enum_v<E>)
typename Network::MessageContainerGroup<E, T>::GroupConstIter Network::MessageContainerGroup<E, T>::end() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_3;

    return group.end();
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_GROUP_DETAIL_H