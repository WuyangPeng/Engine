///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 10:49)

#ifndef NETWORK_NETWORK_INTERFACE_CLIENT_IMPL_H
#define NETWORK_NETWORK_INTERFACE_CLIENT_IMPL_H

#include "Network/NetworkDll.h"

#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkMessage/MessageEventManager.h"
#include "Network/NetworkMessage/MessageInterface.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ClientImpl : public CoreTools::EventInterface
    {
    public:
        using ClassType = ClientImpl;
        using ParentType = EventInterface;
        using FactoryType = ClientFactory;

        using CallbackParameters = CoreTools::CallbackParameters;
        using EventInterfaceSharedPtr = CoreTools::EventInterfaceSharedPtr;

    public:
        ClientImpl(ConfigurationStrategy configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager) noexcept;
        ~ClientImpl() noexcept = default;
        ClientImpl(const ClientImpl& rhs) noexcept = delete;
        ClientImpl& operator=(const ClientImpl& rhs) noexcept = delete;
        ClientImpl(ClientImpl&& rhs) noexcept = delete;
        ClientImpl& operator=(ClientImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD virtual int64_t Connect() = 0;
        virtual void AsyncConnect() = 0;

        virtual void Send(int64_t socketId, const MessageInterfaceSharedPtr& message) = 0;
        virtual void AsyncSend(int64_t socketId, const MessageInterfaceSharedPtr& message) = 0;

        virtual void Receive() = 0;
        virtual void AsyncReceive() = 0;
        virtual void ImmediatelySend(int64_t socketId) = 0;
        virtual void ImmediatelyAsyncSend(int64_t socketID) = 0;

        NODISCARD ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        NODISCARD virtual int64_t GetSocketId() const noexcept;

    protected:
        NODISCARD MessageEventManagerSharedPtr GetMessageEventManagerSharedPtr();

    private:
        using MessageEventManagerWeakPtr = std::weak_ptr<MessageEventManager>;

    private:
        ConfigurationStrategy configurationStrategy;
        MessageEventManagerWeakPtr messageEventManager;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_CLIENT_IMPL_H
