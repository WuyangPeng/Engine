//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 19:50)

#ifndef NETWORK_NETWORK_INTERFACE_CLIENT_IMPL_H
#define NETWORK_NETWORK_INTERFACE_CLIENT_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/NetworkMessage/SocketManager.h"

#include <boost/noncopyable.hpp>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ClientImpl : public CoreTools::EventInterface, private boost::noncopyable
    {
    public:
        using ClassType = ClientImpl;
        using ParentType = EventInterface;
        using EventInterfaceSharedPtr = CoreTools::EventInterfaceSharedPtr;
        using CallbackParameters = CoreTools::CallbackParameters;

    public:
        ClientImpl(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] virtual uint64_t Connect();
        virtual void AsyncConnect();

        virtual void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message);
        virtual void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message);

        virtual void Receive();
        virtual void AsyncReceive();
        virtual void ImmediatelySend(uint64_t socketID);
        virtual void ImmediatelyAsyncSend(uint64_t socketID);

        [[nodiscard]] ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        [[nodiscard]] virtual uint64_t GetSocketID() const;

    protected:
        [[nodiscard]] SocketManagerSharedPtr GetSocketManagerSharedPtr();

    private:
        [[nodiscard]] bool EventFunction(const CallbackParameters& callbackParameters) override;

    private:
        ConfigurationStrategy m_ConfigurationStrategy;
        SocketManagerWeakPtr m_SocketManager;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_CLIENT_IMPL_H
