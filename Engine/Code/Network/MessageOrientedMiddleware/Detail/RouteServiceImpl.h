///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/10 09:21)

#ifndef NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_ROUTE_SERVICE_IMPL_H
#define NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_ROUTE_SERVICE_IMPL_H

#include "Network/NetworkDll.h"

#include "ConsumerNode.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/MessageOrientedMiddleware/Consumer.h"
#include "Network/MessageOrientedMiddleware/Producer.h"
#include "Network/NetworkMessage/MessageInterface.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE RouteServiceImpl final
    {
    public:
        using ClassType = RouteServiceImpl;
        using String = System::String;

    public:
        explicit RouteServiceImpl(ConfigurationStrategy configurationStrategy);

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetAddress() const;
        NODISCARD String GetFirstConsumer(SocketType serverType) const;

        void AddConsumer(SocketType serverType, int serverId, const System::String& aAddress);
        void RemoveConsumer(SocketType serverType, int serverId);

        void BroadcastMessage(SocketType serverType, const MessageInterfaceSharedPtr& message);
        void BroadcastMessage(const MessageInterfaceSharedPtr& message);
        void SendServerMessage(const String& aAddress, const MessageInterfaceSharedPtr& message);

        void Insert(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent);

    private:
        using Container = std::vector<ConsumerNode>;

        NODISCARD static String ComputeAddress(const ConfigurationStrategy& configurationStrategy);

    private:
        Container consumerNode;
        String address;
        Consumer consumer;
        Producer producer;
        ConfigurationStrategy configurationStrategy;
    };
}

#endif  // NETWORK_NETWORK_WRAPPERS_NNETWORK_MESSAGE_ORIENTED_MIDDLEWARE_ROUTE_SERVICE_IMPL_HETWORK_SOCK_ACCEPTOR_H
