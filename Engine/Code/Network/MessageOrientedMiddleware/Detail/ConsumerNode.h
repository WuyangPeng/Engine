///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/09 17:01)

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