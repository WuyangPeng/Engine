//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:09)

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

        [[nodiscard]] uint64_t Connect() override;
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
        [[nodiscard]] bool EventFunction(const CoreTools::CallbackParameters& callbackParameters) override;

    private:
        SockConnector m_SockConnector;
        SockStreamSharedPtr m_SockStream;
        BufferSendStream m_BufferSendStream;
        MessageBufferSharedPtr m_Buffer;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SENDING_A_TRIP_CLIENT_H
