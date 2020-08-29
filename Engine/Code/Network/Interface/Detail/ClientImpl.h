// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:02)

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

    public:
        ClientImpl(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager) noexcept;
 

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        virtual uint64_t Connect();
        virtual void AsyncConnect();

        virtual void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message);
        virtual void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message);

        virtual void Receive();
        virtual void AsyncReceive();
        virtual void ImmediatelySend(uint64_t socketID);
        virtual void ImmediatelyAsyncSend(uint64_t socketID);

        ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        virtual uint64_t GetSocketID() const;

    protected:
        SocketManagerSharedPtr GetSocketManagerSharedPtr();

    private:
        bool EventFunction(const CoreTools::CallbackParameters& callbackParameters) override;

    private:
        ConfigurationStrategy m_ConfigurationStrategy;
        SocketManagerWeakPtr m_SocketManager;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_CLIENT_IMPL_H
