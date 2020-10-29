//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:18)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_STREAM_IMPL_H
#define NETWORK_NETWORK_INTERFACE_SOCK_STREAM_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SockStreamImpl
    {
    public:
        using ClassType = SockStreamImpl;

    public:
        SockStreamImpl() noexcept = default;
        virtual ~SockStreamImpl() noexcept = default;
        SockStreamImpl(const SockStreamImpl& rhs) = default;
        SockStreamImpl& operator=(const SockStreamImpl& rhs) = default;
        SockStreamImpl(SockStreamImpl&& rhs) noexcept = default;
        SockStreamImpl& operator=(SockStreamImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] virtual int Send(const MessageBufferSharedPtr& messageBuffer) = 0;
        [[nodiscard]] virtual int Receive(const MessageBufferSharedPtr& messageBuffer) = 0;

        virtual void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) = 0;
        virtual void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) = 0;

        [[nodiscard]] virtual ACESockStreamNativeType& GetACESockStream();
        [[nodiscard]] virtual BoostSockStreamType& GetBoostSockStream();
        [[nodiscard]] virtual WinSocketStreamType& GetNetworkSockStream();

        [[nodiscard]] virtual ACEHandleType GetACEHandle() const;

        virtual void SetACEHandle(ACEHandleType handle);
        virtual void SetNetworkHandle(WinSocketStreamType winSocket);

        [[nodiscard]] virtual bool CloseHandle() = 0;

        [[nodiscard]] virtual bool EnableNonBlock() = 0;

        [[nodiscard]] virtual const std::string GetRemoteAddress() const = 0;
        [[nodiscard]] virtual int GetRemotePort() const = 0;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_STREAM_IMPL_H
