///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 17:37)

#ifndef NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_ACCEPTOR_H
#define NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_ACCEPTOR_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockAcceptorImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NetworkSockAcceptor : public SockAcceptorImpl
    {
    public:
        using ClassType = NetworkSockAcceptor;
        using ParentType = SockAcceptorImpl;

    public:
        explicit NetworkSockAcceptor(int port);
        NetworkSockAcceptor(const std::string& hostName, int port);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Accept(SockStream& sockStream, SockAddress& sockAddress) override;
        NODISCARD bool Accept(SockStream& sockStream) override;

        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) override;
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

        NODISCARD bool EnableNonBlock() noexcept override;

        NODISCARD WinSocketType GetWinSocket() noexcept override;

        NODISCARD std::string GetAddress() const noexcept override;
        NODISCARD int GetPort() const noexcept override;

    private:
        WinSocketType socketHandle;
    };
}

#endif  // NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_ACCEPTOR_H
