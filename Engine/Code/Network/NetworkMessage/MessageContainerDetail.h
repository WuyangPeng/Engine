///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/18 18:27)

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
Network::MessageContainer<E, T>::MessageContainer() noexcept
    : message{}
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

template <typename E, typename T>
Network::MessageContainer<E, T>::MessageContainer(const MessageType& messageType)
    : message{ messageType }
{
    if (System::EnumCastUnderlying<size_t>(E::Count) < message.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���鳤�Ȳ�������Ϣ���ȡ�"s));
    }

    NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename E, typename T>
bool Network::MessageContainer<E, T>::IsValid() const noexcept
{
    if (message.size() <= System::EnumCastUnderlying<size_t>(E::Count))
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename E, typename T>
void Network::MessageContainer<E, T>::Load(MessageSource& source)
{
    NETWORK_CLASS_IS_VALID_1;

    source.Read(message);
}

template <typename E, typename T>
void Network::MessageContainer<E, T>::Save(MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    target.Write(message);
}

template <typename E, typename T>
int Network::MessageContainer<E, T>::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return CoreTools::GetStreamSize(message);
}

template <typename E, typename T>
T Network::MessageContainer<E, T>::GetValue(E index) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    const auto castIndex = System::EnumCastUnderlying(index);

    return message.at(castIndex);
}

template <typename E, typename T>
int Network::MessageContainer<E, T>::GetSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(message.size());
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_DETAIL_H