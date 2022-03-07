///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/19 14:29)

#ifndef NETWORK_NETWORK_INTERFACE_CLIENT_IMPL_H
#define NETWORK_NETWORK_INTERFACE_CLIENT_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/NetworkMessage/SocketManager.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ClientImpl : public CoreTools::EventInterface
    {
    public:
        using ClassType = ClientImpl;
        using ParentType = EventInterface;
        using EventInterfaceSharedPtr = CoreTools::EventInterfaceSharedPtr;
        using CallbackParameters = CoreTools::CallbackParameters;
        using FactoryType = ClientFactory;

    public:
        ClientImpl(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager) noexcept;
        ~ClientImpl() noexcept = default;
        ClientImpl(const ClientImpl& rhs) noexcept = delete;
        ClientImpl& operator=(const ClientImpl& rhs) noexcept = delete;
        ClientImpl(ClientImpl&& rhs) noexcept = delete;
        ClientImpl& operator=(ClientImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD virtual uint64_t Connect() = 0;
        virtual void AsyncConnect() = 0;

        virtual void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) = 0;
        virtual void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message) = 0;

        virtual void Receive() = 0;
        virtual void AsyncReceive() = 0;
        virtual void ImmediatelySend(uint64_t socketID) = 0;
        virtual void ImmediatelyAsyncSend(uint64_t socketID) = 0;

        NODISCARD ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        NODISCARD virtual uint64_t GetSocketID() const noexcept;

    protected:
        NODISCARD SocketManagerSharedPtr GetSocketManagerSharedPtr();

    private:
        ConfigurationStrategy configurationStrategy;
        SocketManagerWeakPtr socketManager;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_CLIENT_IMPL_H
