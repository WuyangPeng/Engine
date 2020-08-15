// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:12)

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
        ~ServerImpl();
        ServerImpl(const ServerImpl&) noexcept = default;
        ServerImpl& operator=(const ServerImpl&) noexcept = default;
        ServerImpl(ServerImpl&&) noexcept = default;
        ServerImpl& operator=(ServerImpl&&) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

        ConfigurationStrategy GetConfigurationStrategy() const noexcept;
        bool RunServer();

        virtual void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message);
        virtual void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message);

        bool EventFunction(const CoreTools::CallbackParameters& callbackParameters) override;

    protected:
        SocketManagerSharedPtr GetSocketManagerSharedPtr();

    private:
        virtual bool WaitForMultipleEvents();
        virtual bool HandleConnections(const SocketManagerSharedPtr& socketManager);
        virtual bool HandleData(const SocketManagerSharedPtr& socketManager);
        virtual bool ImmediatelySend();
        virtual bool ImmediatelySend(uint64_t socketID);
        virtual void ImmediatelyAsyncSend(uint64_t socketID);

    private:
        ConfigurationStrategy m_ConfigurationStrategy;
        SocketManagerWeakPtr m_SocketManagerWeakPtr;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SERVER_IMPL_H
