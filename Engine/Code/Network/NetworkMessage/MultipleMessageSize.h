//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 10:11)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_SIZE_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_SIZE_H

#include "Network/NetworkDll.h"

#include "NetworkMessageInternalFwd.h"

namespace Network
{
    template <typename MultipleType>
    struct MultipleMessageSize;

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    struct MultipleMessageSize<MultipleMessageContainer<E, ByteType, Types...>> : std::integral_constant<size_t, sizeof...(Types) + 1>
    {
        using ClassType = MultipleMessageSize<MultipleMessageContainer<E, ByteType, Types...>>;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_SIZE_H
