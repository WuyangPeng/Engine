///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/21 17:05)

#ifndef NETWORK_ACE_WRAPPERS_ACE_SOCK_ACCEPTOR_H
#define NETWORK_ACE_WRAPPERS_ACE_SOCK_ACCEPTOR_H

#include "Network/NetworkDll.h"

#include "System/Helper/PragmaWarning/ACE.h"
#include "Network/Interface/Detail/SockAcceptorImpl.h"

#ifdef NETWORK_USE_ACE

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

        NODISCARD bool Accept(SockStream& sockStream, SockAddress& sockAddress) override;
        NODISCARD bool Accept(SockStream& sockStream) override;

        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) override;
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

        NODISCARD bool EnableNonBlock() override;

        NODISCARD ACEHandle GetACEHandle() override;

        NODISCARD std::string GetAddress() const override;
        NODISCARD int GetPort() const override;

    private:
        ACE_SOCK_Acceptor aceSockAcceptor;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_ACE_WRAPPERS_ACE_SOCK_ACCEPTOR_H
