///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 14:24)

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
        NODISCARD bool Accept(SockStream& sockStream, SockAddress& sockAddress) noexcept final;
        NODISCARD bool Accept(SockStream& sockStream) noexcept final;
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) noexcept final;
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) noexcept final;

        NODISCARD bool EnableNonBlock() noexcept final;

        NODISCARD std::string GetAddress() const noexcept final;
        NODISCARD int GetPort() const noexcept final;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_SOCK_ACCEPTOR_H
