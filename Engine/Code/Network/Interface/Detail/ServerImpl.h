///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 15:56)

#ifndef NETWORK_NETWORK_INTERFACE_SERVER_IMPL_H
#define NETWORK_NETWORK_INTERFACE_SERVER_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/NetworkMessage/SocketManager.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ServerImpl : public CoreTools::EventInterface
    {
    public:
        using ClassType = ServerImpl;
        using ParentType = EventInterface;
        using FactoryType = ServerFactory;

    public:
        ServerImpl(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConfigurationStrategy GetConfigurationStrategy() const noexcept;
        NODISCARD bool RunServer();

        virtual void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) = 0;
        virtual void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message) = 0;

    protected:
        NODISCARD SocketManagerSharedPtr GetSocketManagerSharedPtr();

    private:
        NODISCARD virtual bool WaitForMultipleEvents() = 0;
        NODISCARD virtual bool HandleConnections(SocketManager& socketManager) = 0;
        NODISCARD virtual bool HandleData(const SocketManagerSharedPtr& socketManager) = 0;
        NODISCARD virtual bool ImmediatelySend() = 0;
        NODISCARD virtual bool ImmediatelySend(uint64_t socketID) = 0;
        virtual void ImmediatelyAsyncSend(uint64_t socketID) = 0;

    private:
        ConfigurationStrategy configurationStrategy;
        SocketManagerWeakPtr m_SocketManager;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SERVER_IMPL_H
