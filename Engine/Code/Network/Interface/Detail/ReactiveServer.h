///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 11:23)

#ifndef NETWORK_NETWORK_INTERFACE_REACTIVE_SERVER_H
#define NETWORK_NETWORK_INTERFACE_REACTIVE_SERVER_H

#include "Network/NetworkDll.h"

#include "HandleSetContainer.h"
#include "IterativeServer.h"
#include "Network/Interface/Data/BufferSendStreamMultiIndexContainer.h"
#include "Network/Interface/HandleSet.h"
#include "Network/NetworkMessage/NetworkMessageFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ReactiveServer : public ServerImpl
    {
    public:
        using ClassType = ReactiveServer;
        using ParentType = ServerImpl;

    public:
        explicit ReactiveServer(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager);
        ~ReactiveServer() noexcept;
        ReactiveServer(const ReactiveServer& rhs) noexcept = delete;
        ReactiveServer& operator=(const ReactiveServer& rhs) noexcept = delete;
        ReactiveServer(ReactiveServer&& rhs) noexcept = delete;
        ReactiveServer& operator=(ReactiveServer&& rhs) noexcept = delete;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Send(int64_t socketId, const MessageInterfaceSharedPtr& message) override;
        void AsyncSend(int64_t socketId, const MessageInterfaceSharedPtr& message) override;

        NODISCARD bool EventFunction(const CoreTools::CallbackParameters& callbackParameters) noexcept override;

    private:
        using BufferType = std::vector<char>;

    private:
        void Init();

        NODISCARD bool WaitForMultipleEvents() override;
        NODISCARD bool HandleConnections() override;
        NODISCARD bool HandleData(const MessageEventManagerSharedPtr& aMessageEventManager) override;
        NODISCARD bool ImmediatelySend(int64_t socketId) override;
        NODISCARD bool ImmediatelySend() override;
        void ImmediatelyAsyncSend(int64_t socketId) noexcept override;

    private:
        SockAcceptor sockAcceptor;
        SockStreamSharedPtr sockStream;
        BufferSendStreamMultiIndexContainer bufferSendStream;
        HandleSetContainer masterHandleSet;
        HandleSet activeHandles;
        MessageBufferSharedPtr buffer;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_REACTIVE_SERVER_H
