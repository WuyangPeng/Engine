///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 09:17)

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
        NODISCARD bool Accept(SockStream& sockStream, SockAddress& sockAddress) noexcept override;
        NODISCARD bool Accept(SockStream& sockStream) noexcept override;
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) noexcept override;
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) noexcept override;

        NODISCARD bool EnableNonBlock() noexcept override;

        NODISCARD std::string GetAddress() const noexcept override;
        NODISCARD int GetPort() const noexcept override;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_SOCK_ACCEPTOR_H
