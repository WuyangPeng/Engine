/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:44)

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
        using FactoryType = SockStreamFactory;

    public:
        SockStreamImpl() noexcept = default;
        virtual ~SockStreamImpl() noexcept = default;
        SockStreamImpl(const SockStreamImpl& rhs) = default;
        SockStreamImpl& operator=(const SockStreamImpl& rhs) = default;
        SockStreamImpl(SockStreamImpl&& rhs) noexcept = default;
        SockStreamImpl& operator=(SockStreamImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int Send(const MessageBufferSharedPtr& messageBuffer) = 0;
        NODISCARD virtual int Receive(const MessageBufferSharedPtr& messageBuffer) = 0;

        virtual void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) = 0;
        virtual void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) = 0;

        NODISCARD virtual ACESockStreamNativeType& GetACESockStream();
        NODISCARD virtual BoostSockStreamType& GetBoostSockStream();
        NODISCARD virtual WinSocketStreamType& GetNetworkSockStream();

        NODISCARD virtual ACEHandleType GetACEHandle() const;

        virtual void SetACEHandle(ACEHandleType handle);
        virtual void SetNetworkHandle(WinSocketStreamType winSocket);

        NODISCARD virtual bool CloseHandle() = 0;

        NODISCARD virtual bool EnableNonBlock() = 0;

        NODISCARD virtual std::string GetRemoteAddress() const = 0;
        NODISCARD virtual int GetRemotePort() const = 0;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_STREAM_IMPL_H
