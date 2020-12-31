//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 16:22)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SOCK_ACCEPTOR_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SOCK_ACCEPTOR_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockAcceptorImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostSockAcceptor : public SockAcceptorImpl
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

        [[nodiscard]] bool Accept(const SockStreamSharedPtr& sockStream) override;
        [[nodiscard]] bool Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

        // �첽�ص�������һ���̣߳���Ҫ���¼�������м�������
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) override;
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

        [[nodiscard]] BoostHandleType GetBoostHandle() override;

        [[nodiscard]] bool EnableNonBlock() override;

        [[nodiscard]] const std::string GetAddress() const override;
        [[nodiscard]] int GetPort() const override;

    private:
        using AcceptorType = boost::asio::ip::tcp::acceptor;

    private:
        AcceptorType m_Acceptor;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_ACCEPTOR_H
