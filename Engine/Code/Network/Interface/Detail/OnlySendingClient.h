///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 11:17)

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
        OnlySendingClient(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int64_t Connect() override;
        void AsyncConnect() override;

        void Send(int64_t socketId, const MessageInterfaceSharedPtr& message) override;
        void AsyncSend(int64_t socketId, const MessageInterfaceSharedPtr& message) override;

        void Receive() noexcept override;
        void AsyncReceive() noexcept override;
        void ImmediatelySend(int64_t socketId) override;
        void ImmediatelyAsyncSend(int64_t socketId) override;

    private:
        using BufferType = std::vector<char>;

    private:
        NODISCARD bool EventFunction(const CoreTools::CallbackParameters& callbackParameters) override;

    private:
        SockConnector sockConnector;
        SockStreamSharedPtr sockStream;
        BufferSendStream bufferSendStream;
        MessageBufferSharedPtr buffer;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SENDING_A_TRIP_CLIENT_H
