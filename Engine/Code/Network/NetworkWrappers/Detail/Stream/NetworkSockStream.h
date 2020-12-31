//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 18:55)

#ifndef NETWORK_NETWORK_INTERFACE_NETWORK_SOCK_STREAM_H
#define NETWORK_NETWORK_INTERFACE_NETWORK_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockStreamImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NetworkSockStream : public SockStreamImpl
    {
    public:
        using ClassType = NetworkSockStream;
        using ParentType = SockStreamImpl;

    public:
        NetworkSockStream() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] WinSocketStreamType& GetNetworkSockStream() noexcept override;

        [[nodiscard]] int Receive(const MessageBufferSharedPtr& messageBuffer) override;
        [[nodiscard]] int Send(const MessageBufferSharedPtr& messageBuffer) override;

        void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;
        void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;

        [[nodiscard]] bool CloseHandle() noexcept override;
        void SetNetworkHandle(WinSocketStreamType winSocket) noexcept override;

        [[nodiscard]] bool EnableNonBlock() noexcept override;

        [[nodiscard]] const std::string GetRemoteAddress() const noexcept override;
        [[nodiscard]] int GetRemotePort() const noexcept override;

    private:
        WinSocketStreamType m_WinSocket;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NETWORK_SOCK_STREAM_H
