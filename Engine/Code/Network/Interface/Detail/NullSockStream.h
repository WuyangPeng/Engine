///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 15:07)

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

        NODISCARD int Send(const MessageBufferSharedPtr& messageBuffer) noexcept final;
        NODISCARD int Receive(const MessageBufferSharedPtr& messageBuffer) noexcept final;

        void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) final;
        void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) noexcept final;

        NODISCARD bool CloseHandle() noexcept final;

        NODISCARD bool EnableNonBlock() noexcept final;

        NODISCARD std::string GetRemoteAddress() const noexcept final;
        NODISCARD int GetRemotePort() const noexcept final;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_SOCK_STREAM_H
