// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:07)

#ifndef NETWORK_NETWORK_INTERFACE_NULL_SOCK_STREAM_H
#define NETWORK_NETWORK_INTERFACE_NULL_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "SockStreamImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NullSockStream : public SockStreamImpl
    {
    public:
        using ClassType = NullSockStream;
        using ParentType = SockStreamImpl;

    public:
        NullSockStream() noexcept;

        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

        int Send(const MessageBufferSharedPtr& messageBuffer) noexcept override;
        int Receive(const MessageBufferSharedPtr& messageBuffer) noexcept override;

        void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;
        void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) noexcept override;

        bool CloseHandle() noexcept override;

        bool EnableNonBlock() noexcept override;

        const std::string GetRemoteAddress() const override;
        int GetRemotePort() const noexcept override;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_SOCK_STREAM_H
