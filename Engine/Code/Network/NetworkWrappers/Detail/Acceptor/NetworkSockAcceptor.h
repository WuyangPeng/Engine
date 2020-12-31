//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 18:54)

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

        [[nodiscard]] bool Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;
        [[nodiscard]] bool Accept(const SockStreamSharedPtr& sockStream) override;

        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) override;
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

        [[nodiscard]] bool EnableNonBlock() noexcept override;

        [[nodiscard]] WinSocketType GetWinSocket() noexcept override;

        [[nodiscard]] const std::string GetAddress() const noexcept override;
        [[nodiscard]] int GetPort() const noexcept override;

    private:
        WinSocketType m_SocketHandle;
    };
}

#endif  // NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_ACCEPTOR_H
