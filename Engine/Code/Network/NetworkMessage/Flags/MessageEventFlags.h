///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/04 13:32)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_FLAGS_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Network
{
    enum class MessageEventPriority
    {
        Highest = 0,
        High = 1,
        Middle = 2,
        Low = 3,
        Lowest = 4,
        Count = 5,
    };

    enum class SocketManagerEvent
    {
        None = 0,

        AsyncConnect = 1,
        AsyncSend,
        AsyncAcceptor,
        AsyncReceive,
    };

    enum class SocketManagerPosition
    {
        Event = 0,  // 类型int
        WrappersStrategy = 1,  // 类型int
        Error = 2,  // 类型int
        Port = 3,  // 类型int
        Address = 4,  // 类型string
        Async = 5,  // 类型int
        BytesTransferred = 6,  // 类型int

        Count,
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_FLAGS_H
