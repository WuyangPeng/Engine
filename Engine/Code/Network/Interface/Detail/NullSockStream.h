/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:55)

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

        NODISCARD int Send(const MessageBufferSharedPtr& messageBuffer) noexcept override;
        NODISCARD int Receive(const MessageBufferSharedPtr& messageBuffer) noexcept override;

        void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;
        void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) noexcept override;

        NODISCARD bool CloseHandle() noexcept override;

        NODISCARD bool EnableNonBlock() noexcept override;

        NODISCARD std::string GetRemoteAddress() const noexcept override;
        NODISCARD int GetRemotePort() const noexcept override;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_SOCK_STREAM_H
