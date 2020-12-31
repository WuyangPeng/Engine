//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:07)

#ifndef NETWORK_NETWORK_INTERFACE_NULL_SOCK_ACCEPTOR_H
#define NETWORK_NETWORK_INTERFACE_NULL_SOCK_ACCEPTOR_H

#include "Network/NetworkDll.h"

#include "SockAcceptorImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NullSockAcceptor final : public SockAcceptorImpl
    {
    public:
        using ClassType = NullSockAcceptor;
        using ParentType = SockAcceptorImpl;

    public:
        NullSockAcceptor() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

    public:
        [[nodiscard]] bool Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) noexcept final;
        [[nodiscard]] bool Accept(const SockStreamSharedPtr& sockStream) noexcept final;
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) noexcept final;
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) noexcept final;

        [[nodiscard]] bool EnableNonBlock() noexcept final;

        [[nodiscard]] const std::string GetAddress() const noexcept final;
        [[nodiscard]] int GetPort() const noexcept final;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_SOCK_ACCEPTOR_H
