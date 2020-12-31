//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:10)

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
        explicit ReactiveServer(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy);
        ~ReactiveServer() noexcept;
        ReactiveServer(const ReactiveServer& rhs) noexcept = default;
        ReactiveServer& operator=(const ReactiveServer& rhs) noexcept = default;
        ReactiveServer(ReactiveServer&& rhs) noexcept = default;
        ReactiveServer& operator=(ReactiveServer&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;

    private:
        using BufferType = std::vector<char>;

    private:
        void Init();

        [[nodiscard]] bool WaitForMultipleEvents() override;
        [[nodiscard]] bool HandleConnections(const SocketManagerSharedPtr& socketManager) override;
        [[nodiscard]] bool HandleData(const SocketManagerSharedPtr& socketManager) override;
        [[nodiscard]] bool ImmediatelySend(uint64_t socketID) override;
        [[nodiscard]] bool ImmediatelySend() override;

    private:
        SockAcceptor m_SockAcceptor;
        SockStreamSharedPtr m_SockStream;
        BufferSendStreamMultiIndexContainer m_BufferSendStream;
        HandleSetContainer m_MasterHandleSet;
        HandleSet m_ActiveHandles;
        MessageBufferSharedPtr m_Buffer;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_REACTIVE_SERVER_H
