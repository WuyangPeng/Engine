///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 14:18)

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
        IterativeServer(const MessageEventManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;
        void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;

        NODISCARD bool EventFunction(MAYBE_UNUSED const CoreTools::CallbackParameters& callbackParameters) noexcept override;

    private:
        NODISCARD bool WaitForMultipleEvents() noexcept override;
        NODISCARD bool HandleConnections(MessageEventManager& socketManager) override;
        NODISCARD bool HandleData(const MessageEventManagerSharedPtr& socketManager) override;
        NODISCARD bool ImmediatelySend(MAYBE_UNUSED uint64_t socketID) noexcept override;
        NODISCARD bool ImmediatelySend() noexcept override;
        void ImmediatelyAsyncSend(MAYBE_UNUSED uint64_t socketID) noexcept override;

    private:
        using BufferType = std::vector<char>;
        using Container = std::map<uint64_t, StreamContainer>;

    private:
        SockAcceptor sockAcceptor;
        Container streamContainer;
        MessageBufferSharedPtr receiveBuffer;
        MessageBufferSharedPtr sendBuffer;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_ITERATIVE_SERVER_H
