//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 14:15)

#ifndef NETWORK_ACE_WRAPPERS_ACE_SOCK_ACCEPTOR_H
#define NETWORK_ACE_WRAPPERS_ACE_SOCK_ACCEPTOR_H

#include "Network/NetworkDll.h"

#ifdef NETWORK_USE_ACE

    #include "System/Helper/PragmaWarning/ACE.h"
    #include "Network/Interface/Detail/SockAcceptorImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ACESockAcceptor : public SockAcceptorImpl
    {
    public:
        using ClassType = ACESockAcceptor;
        using ParentType = SockAcceptorImpl;

    public:
        explicit ACESockAcceptor(int port);
        ACESockAcceptor(const std::string& hostName, int port);
        ~ACESockAcceptor() noexcept;
        ACESockAcceptor(const ACESockAcceptor& rhs) = delete;
        ACESockAcceptor& operator=(const ACESockAcceptor& rhs) = delete;
        ACESockAcceptor(ACESockAcceptor&& rhs) noexcept = delete;
        ACESockAcceptor& operator=(ACESockAcceptor&& rhs) noexcept = delete;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] bool Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;
        [[nodiscard]] bool Accept(const SockStreamSharedPtr& sockStream) override;

        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) override;
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

        [[nodiscard]] bool EnableNonBlock() override;

        [[nodiscard]] ACEHandle GetACEHandle() override;

        [[nodiscard]] const std::string GetAddress() const override;
        [[nodiscard]] int GetPort() const override;

    private:
        ACE_SOCK_Acceptor m_ACESockAcceptor;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_ACE_WRAPPERS_ACE_SOCK_ACCEPTOR_H
