///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 18:15)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_ELEMENT_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_ELEMENT_H

#include "Network/NetworkDll.h"

#include "NetworkMessageInternalFwd.h"

namespace Network
{
    template <int Index, typename MultipleType>
    struct MultipleMessageElement;

    template <int Index, typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    struct MultipleMessageElement<Index, MultipleMessageContainer<E, ByteType, Types...>> : public MultipleMessageElement<Index - 1, MultipleMessageContainer<E, Types...>>
    {
        using ClassType = MultipleMessageElement<Index, MultipleMessageContainer<E, ByteType, Types...>>;
        using ParentType = MultipleMessageElement<Index - 1, MultipleMessageContainer<E, Types...>>;
    };

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    struct MultipleMessageElement<0, MultipleMessageContainer<E, ByteType, Types...>>
    {
        using ClassType = MultipleMessageElement<0, MultipleMessageContainer<E, ByteType, Types...>>;

        static constexpr MultipleMessageByteType byteType = ByteType;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_ELEMENT_H
