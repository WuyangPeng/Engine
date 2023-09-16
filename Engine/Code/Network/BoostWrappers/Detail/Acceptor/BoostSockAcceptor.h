///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 17:12)

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
        // hostName默认为"0.0.0.0"。
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

        // 异步回调来自另一个线程，需要对事件管理进行加锁处理。
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
