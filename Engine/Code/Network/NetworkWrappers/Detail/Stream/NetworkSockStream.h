///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 17:41)

#ifndef NETWORK_NETWORK_INTERFACE_NETWORK_SOCK_STREAM_H
#define NETWORK_NETWORK_INTERFACE_NETWORK_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockStreamImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NetworkSockStream final : public SockStreamImpl
    {
    public:
        using ClassType = NetworkSockStream;
        using ParentType = SockStreamImpl;

    public:
        NetworkSockStream() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD WinSocketStreamType& GetNetworkSockStream() noexcept override;

        NODISCARD int Receive(const MessageBufferSharedPtr& messageBuffer) override;
        NODISCARD int Send(const MessageBufferSharedPtr& messageBuffer) override;

        void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;
        void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;

        NODISCARD bool CloseHandle() noexcept override;
        void SetNetworkHandle(WinSocketStreamType newWinSocket) noexcept override;

        NODISCARD bool EnableNonBlock() noexcept override;

        NODISCARD std::string GetRemoteAddress() const noexcept override;
        NODISCARD int GetRemotePort() const noexcept override;

    private:
        WinSocketStreamType winSocket;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NETWORK_SOCK_STREAM_H
