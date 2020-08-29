// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:08)

#ifndef NETWORK_NETWORK_INTERFACE_SENDING_A_TRIP_CLIENT_H
#define NETWORK_NETWORK_INTERFACE_SENDING_A_TRIP_CLIENT_H

#include "Network/NetworkDll.h"

#include "ClientImpl.h"
#include "Network/Interface/SockConnector.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/MessageInterface.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE OnlySendingClient : public ClientImpl
    {
    public:
        using ClassType = OnlySendingClient;
        using ParentType = ClientImpl;

    public:
        OnlySendingClient(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        uint64_t Connect() override;
        void AsyncConnect() override;

        void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;
        void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;

        void Receive() noexcept override;
        void AsyncReceive() noexcept override;
        void ImmediatelySend(uint64_t socketID) override;
        void ImmediatelyAsyncSend(uint64_t socketID) override;

    private:
        using BufferType = std::vector<char>;

    private:
        bool EventFunction(const CoreTools::CallbackParameters& callbackParameters) override;

    private:
        SockConnector m_SockConnector;
        SockStreamSharedPtr m_SockStream;
        BufferSendStream m_BufferSendStream;
        MessageBufferSharedPtr m_Buffer;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SENDING_A_TRIP_CLIENT_H
