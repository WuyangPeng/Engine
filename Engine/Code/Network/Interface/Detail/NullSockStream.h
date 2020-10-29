//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:09)

#ifndef NETWORK_NETWORK_INTERFACE_NULL_SOCK_STREAM_H
#define NETWORK_NETWORK_INTERFACE_NULL_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "SockStreamImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NullSockStream final : public SockStreamImpl
    {
    public:
        using ClassType = NullSockStream;
        using ParentType = SockStreamImpl;

    public:
        NullSockStream() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] int Send(const MessageBufferSharedPtr& messageBuffer) noexcept final;
        [[nodiscard]] int Receive(const MessageBufferSharedPtr& messageBuffer) noexcept final;

        void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) final;
        void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) noexcept final;

        [[nodiscard]] bool CloseHandle() noexcept final;

        [[nodiscard]] bool EnableNonBlock() noexcept final;

        [[nodiscard]] const std::string GetRemoteAddress() const noexcept final;
        [[nodiscard]] int GetRemotePort() const noexcept final;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_SOCK_STREAM_H
