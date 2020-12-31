//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:13)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_IMPL_H
#define NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SockAcceptorImpl
    {
    public:
        using ClassType = SockAcceptorImpl;

    public:
        SockAcceptorImpl() noexcept;
        virtual ~SockAcceptorImpl() noexcept = default;
        SockAcceptorImpl(const SockAcceptorImpl&) = delete;
        virtual SockAcceptorImpl& operator=(const SockAcceptorImpl&) = delete;
        SockAcceptorImpl(SockAcceptorImpl&&) noexcept = delete;
        virtual SockAcceptorImpl& operator=(SockAcceptorImpl&&) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] virtual bool Accept(const SockStreamSharedPtr& sockStream) = 0;
        [[nodiscard]] virtual bool Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) = 0;

        virtual void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) = 0;
        virtual void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) = 0;

        [[nodiscard]] virtual bool EnableNonBlock() = 0;

        [[nodiscard]] virtual const std::string GetAddress() const = 0;
        [[nodiscard]] virtual int GetPort() const = 0;

        [[nodiscard]] virtual ACEHandleType GetACEHandle();
        [[nodiscard]] virtual BoostHandleType GetBoostHandle();
        [[nodiscard]] virtual WinSocketType GetWinSocket();
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_IMPL_H
