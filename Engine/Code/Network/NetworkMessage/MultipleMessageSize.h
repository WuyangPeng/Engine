/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:17)

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
