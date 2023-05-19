///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 11:05)

#ifndef NETWORK_NETWORK_INTERFACE_ITERATIVE_SERVER_H
#define NETWORK_NETWORK_INTERFACE_ITERATIVE_SERVER_H

#include "Network/NetworkDll.h"

#include "ServerImpl.h"
#include "StreamContainer.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkMessage/BufferReceiveStream.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/NetworkMessageFwd.h"

#include <map>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE IterativeServer : public ServerImpl
    {
    public:
        using ClassType = IterativeServer;
        using ParentType = ServerImpl;

    public:
        IterativeServer(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Send(int64_t socketId, const MessageInterfaceSharedPtr& message) override;
        void AsyncSend(int64_t socketId, const MessageInterfaceSharedPtr& message) override;

        NODISCARD bool EventFunction(const CoreTools::CallbackParameters& callbackParameters) override;

    private:
        NODISCARD bool WaitForMultipleEvents() noexcept override;
        NODISCARD bool HandleConnections() override;
        NODISCARD bool HandleData(const MessageEventManagerSharedPtr& aMessageEventManager) override;
        NODISCARD bool ImmediatelySend(int64_t socketId) noexcept override;
        NODISCARD bool ImmediatelySend() noexcept override;
        void ImmediatelyAsyncSend(int64_t socketId) noexcept override;

    private:
        using BufferType = std::vector<char>;
        using Container = std::map<int64_t, StreamContainer>;

    private:
        SockAcceptor sockAcceptor;
        Container streamContainer;
        MessageBufferSharedPtr receiveBuffer;
        MessageBufferSharedPtr sendBuffer;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_ITERATIVE_SERVER_H
