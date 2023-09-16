///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/04 16:23)

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
        Event = 0,  // ����int
        WrappersStrategy = 1,  // ����int
        Error = 2,  // ����int
        Port = 3,  // ����int
        Address = 4,  // ����string
        Async = 5,  // ����int
        BytesTransferred = 6,  // ����int

        Count,
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_FLAGS_H
