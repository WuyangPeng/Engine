//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 11:32)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_DETAIL_H

#include "MessageContainer.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename E, typename T>
Network::MessageContainer<E, T>::MessageContainer()
    : m_Message{}
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

template <typename E, typename T>
Network::MessageContainer<E, T>::MessageContainer(const MessageType& messageType)
    : m_Message{ messageType }
{
    if (System::EnumCastUnderlying<size_t>(E::Count) < m_Message.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数组长度不符合消息长度。"));
    }

    NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename E, typename T>
bool Network::MessageContainer<E, T>::IsValid() const noexcept
{
    if (m_Message.size() <= System::EnumCastUnderlying<size_t>(E::Count))
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename E, typename T>
void Network::MessageContainer<E, T>::Load(const MessageSourceSharedPtr& source)
{
    NETWORK_CLASS_IS_VALID_1;

    source->Read(m_Message);
}

template <typename E, typename T>
void Network::MessageContainer<E, T>::Save(const MessageTargetSharedPtr& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    target->Write(m_Message);
}

template <typename E, typename T>
int Network::MessageContainer<E, T>::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return CORE_TOOLS_STREAM_SIZE(m_Message);
}

template <typename E, typename T>
T Network::MessageContainer<E, T>::GetValue(E index) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    auto castIndex = System::EnumCastUnderlying(index);

    return m_Message.at(castIndex);
}

template <typename E, typename T>
int Network::MessageContainer<E, T>::GetSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(m_Message.size());
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_DETAIL_H