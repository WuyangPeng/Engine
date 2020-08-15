// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.4 (2020/03/11 10:08)

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
        ~ReactiveServer();
        ReactiveServer(const ReactiveServer&) noexcept = default;
        ReactiveServer& operator=(const ReactiveServer&) noexcept = default;
        ReactiveServer(ReactiveServer&&) noexcept = default;
        ReactiveServer& operator=(ReactiveServer&&) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

        void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;

    private:
        using BufferType = std::vector<char>;

    private:
        void Init();

        bool WaitForMultipleEvents() override;
        bool HandleConnections(const SocketManagerSharedPtr& socketManager) override;
        bool HandleData(const SocketManagerSharedPtr& socketManager) override;
        bool ImmediatelySend(uint64_t socketID) override;
        bool ImmediatelySend() override;

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
