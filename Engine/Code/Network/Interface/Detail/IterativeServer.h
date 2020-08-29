// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:05)

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

namespace Network
{
    class NETWORK_HIDDEN_DECLARE IterativeServer : public ServerImpl
    {
    public:
        using ClassType = IterativeServer;
        using ParentType = ServerImpl;

    public:
        IterativeServer(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;
        void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message) override;

    private:
        bool HandleConnections(const SocketManagerSharedPtr& socketManager) override;
        bool HandleData(const SocketManagerSharedPtr& socketManager) override;
        bool ImmediatelySend() noexcept override;

    private:
        using BufferType = std::vector<char>;
        using Container = std::map<uint64_t, StreamContainer>;

    private:
        SockAcceptor m_SockAcceptor;
        Container m_StreamContainer;
        MessageBufferSharedPtr m_ReceiveBuffer;
        MessageBufferSharedPtr m_SendBuffer;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_ITERATIVE_SERVER_H
