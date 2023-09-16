///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 17:12)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SOCK_ACCEPTOR_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SOCK_ACCEPTOR_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockAcceptorImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostSockAcceptor final : public SockAcceptorImpl
    {
    public:
        using ClassType = BoostSockAcceptor;
        using ParentType = SockAcceptorImpl;

    public:
        // hostNameĬ��Ϊ"0.0.0.0"��
        explicit BoostSockAcceptor(int port);
        BoostSockAcceptor(const std::string& hostName, int port);
        ~BoostSockAcceptor() noexcept = default;

        BoostSockAcceptor(const BoostSockAcceptor& rhs) = delete;
        BoostSockAcceptor& operator=(const BoostSockAcceptor& rhs) = delete;
        BoostSockAcceptor(BoostSockAcceptor&& rhs) noexcept;
        BoostSockAcceptor& operator=(BoostSockAcceptor&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Accept(SockStream& sockStream) override;
        NODISCARD bool Accept(SockStream& sockStream, SockAddress& sockAddress) override;

        // �첽�ص�������һ���̣߳���Ҫ���¼�������м�������
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) override;
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

        NODISCARD BoostHandleType GetBoostHandle() override;

        NODISCARD bool EnableNonBlock() override;

        NODISCARD std::string GetAddress() const override;
        NODISCARD int GetPort() const override;

    private:
        using AcceptorType = boost::asio::ip::tcp::acceptor;

    private:
        AcceptorType acceptor;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_ACCEPTOR_H
