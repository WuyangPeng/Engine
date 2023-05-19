///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 11:32)

#ifndef NETWORK_NETWORK_INTERFACE_SERVER_IMPL_H
#define NETWORK_NETWORK_INTERFACE_SERVER_IMPL_H

#include "Network/NetworkDll.h"

#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkMessage/MessageEventManager.h"
#include "Network/NetworkMessage/MessageInterface.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ServerImpl : public CoreTools::EventInterface
    {
    public:
        using ClassType = ServerImpl;
        using ParentType = EventInterface;
        using FactoryType = ServerFactory;

    public:
        ServerImpl(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConfigurationStrategy GetConfigurationStrategy() const noexcept;
        NODISCARD bool RunServer();

        virtual void Send(int64_t socketId, const MessageInterfaceSharedPtr& message) = 0;
        virtual void AsyncSend(int64_t socketId, const MessageInterfaceSharedPtr& message) = 0;

    protected:
        NODISCARD MessageEventManagerSharedPtr GetMessageEventManagerSharedPtr();

    private:
        NODISCARD virtual bool WaitForMultipleEvents() = 0;
        NODISCARD virtual bool HandleConnections() = 0;
        NODISCARD virtual bool HandleData(const MessageEventManagerSharedPtr& aMessageEventManager) = 0;
        NODISCARD virtual bool ImmediatelySend() = 0;
        NODISCARD virtual bool ImmediatelySend(int64_t socketId) = 0;
        virtual void ImmediatelyAsyncSend(int64_t socketId) = 0;

    private:
        using MessageEventManagerWeakPtr = std::weak_ptr<MessageEventManager>;

    private:
        ConfigurationStrategy configurationStrategy;
        MessageEventManagerWeakPtr messageEventManager;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SERVER_IMPL_H
