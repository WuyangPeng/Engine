///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/20 15:12)

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
        OnlySendingClient(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& socketManager);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD uint64_t Connect() override;
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
        NODISCARD bool EventFunction(const CoreTools::CallbackParameters& callbackParameters) override;

    private:
        SockConnector sockConnector;
        SockStreamSharedPtr sockStream;
        BufferSendStream bufferSendStream;
        MessageBufferSharedPtr buffer;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SENDING_A_TRIP_CLIENT_H
