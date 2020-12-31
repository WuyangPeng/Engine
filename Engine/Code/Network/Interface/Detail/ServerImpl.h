//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:12)

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

    public:
        ServerImpl(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] ConfigurationStrategy GetConfigurationStrategy() const noexcept;
        [[nodiscard]] bool RunServer();

        virtual void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message);
        virtual void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message);

        [[nodiscard]] bool EventFunction(const CoreTools::CallbackParameters& callbackParameters) override;

    protected:
        [[nodiscard]] SocketManagerSharedPtr GetSocketManagerSharedPtr();

    private:
        [[nodiscard]] virtual bool WaitForMultipleEvents();
        [[nodiscard]] virtual bool HandleConnections(const SocketManagerSharedPtr& socketManager);
        [[nodiscard]] virtual bool HandleData(const SocketManagerSharedPtr& socketManager);
        [[nodiscard]] virtual bool ImmediatelySend();
        [[nodiscard]] virtual bool ImmediatelySend(uint64_t socketID);
        virtual void ImmediatelyAsyncSend(uint64_t socketID);

    private:
        ConfigurationStrategy m_ConfigurationStrategy;
        SocketManagerWeakPtr m_SocketManager;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SERVER_IMPL_H
