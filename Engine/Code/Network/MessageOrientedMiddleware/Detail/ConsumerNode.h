/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:27)

#ifndef NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_CONSUMER_NODE_H
#define NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_CONSUMER_NODE_H

#include "Network/NetworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "Network/Configuration/ConfigurationFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ConsumerNode
    {
    public:
        using ClassType = ConsumerNode;

        using String = System::String;

    public:
        ConsumerNode(SocketType serverType, int serverId, const String& consumer);

        CLASS_INVARIANT_DECLARE;

        NODISCARD SocketType GetServerType() const noexcept;
        NODISCARD int GetServerId() const noexcept;
        NODISCARD String GetConsumer() const;

    private:
        SocketType serverType;
        int serverId;
        String consumer;
    };
}

#endif  // NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_CONSUMER_NODE_H
