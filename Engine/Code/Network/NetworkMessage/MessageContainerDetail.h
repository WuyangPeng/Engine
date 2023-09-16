///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:02)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_DETAIL_H

#include "MessageContainer.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename E, typename T>
requires(std::is_enum_v<E>)
Network::MessageContainer<E, T>::MessageContainer() noexcept
    : message{}
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

template <typename E, typename T>
requires(std::is_enum_v<E>)
Network::MessageContainer<E, T>::MessageContainer(const MessageType& messageType)
    : message{ messageType }
{
    if (System::EnumCastUnderlying<size_t>(E::Count) < message.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数组长度不符合消息长度。"s))
    }

    NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename E, typename T>
requires(std::is_enum_v<E>) bool Network::MessageContainer<E, T>::IsValid() const noexcept
{
    if (message.size() <= System::EnumCastUnderlying<size_t>(E::Count))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename E, typename T>
requires(std::is_enum_v<E>)
void Network::MessageContainer<E, T>::Load(MessageSource& source)
{
    NETWORK_CLASS_IS_VALID_1;

    source.Read(message);
}

template <typename E, typename T>
requires(std::is_enum_v<E>)
void Network::MessageContainer<E, T>::Save(MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    target.Write(message);
}

template <typename E, typename T>
requires(std::is_enum_v<E>)
int Network::MessageContainer<E, T>::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return CoreTools::GetStreamSize(message);
}

template <typename E, typename T>
requires(std::is_enum_v<E>)
T Network::MessageContainer<E, T>::GetValue(E index) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    const auto castIndex = System::EnumCastUnderlying(index);

    if (boost::numeric_cast<int>(message.size()) <= castIndex && castIndex < System::EnumCastUnderlying(E::Count))
    {
        return T{};
    }

    return message.at(castIndex);
}

template <typename E, typename T>
requires(std::is_enum_v<E>)
int Network::MessageContainer<E, T>::GetSize() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return System::EnumCastUnderlying(E::Count);
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_DETAIL_H