///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 15:22)

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
        explicit ReactiveServer(const MessageEventManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy);
        ~ReactiveServer() noexcept;
        ReactiveServer(const ReactiveServer& rhs) noexcept = default;
        ReactiveServer& operator=(const ReactiveServer& rhs) noexcept = default;
        ReactiveServer(ReactiveServer&& rhs) noexcept = default;
        ReactiveServer& operator=(ReactiveServer&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;
        void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;

        NODISCARD bool EventFunction(MAYBE_UNUSED const CoreTools::CallbackParameters& callbackParameters) noexcept override;

    private:
        using BufferType = std::vector<char>;

    private:
        void Init();

        NODISCARD bool WaitForMultipleEvents() override;
        NODISCARD bool HandleConnections(MessageEventManager& socketManager) override;
        NODISCARD bool HandleData(const MessageEventManagerSharedPtr& socketManager) override;
        NODISCARD bool ImmediatelySend(uint64_t socketID) override;
        NODISCARD bool ImmediatelySend() override;
        void ImmediatelyAsyncSend(MAYBE_UNUSED uint64_t socketID) noexcept override;

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
