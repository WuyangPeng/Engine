///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 15:36)

#ifndef NETWORK_ACE_WRAPPERS_ACE_SOCK_ACCEPTOR_H
#define NETWORK_ACE_WRAPPERS_ACE_SOCK_ACCEPTOR_H

#include "Network/NetworkDll.h"

#include "System/Helper/PragmaWarning/ACE.h"
#include "Network/Interface/Detail/SockAcceptorImpl.h"

#ifdef NETWORK_USE_ACE

namespace Network
{
    class NETWORK_HIDDEN_DECLARE AceSockAcceptor final : public SockAcceptorImpl
    {
    public:
        using ClassType = AceSockAcceptor;
        using ParentType = SockAcceptorImpl;

    public:
        explicit AceSockAcceptor(int port);
        AceSockAcceptor(const std::string& hostName, int port);
        ~AceSockAcceptor() noexcept;
        AceSockAcceptor(const AceSockAcceptor& rhs) = delete;
        AceSockAcceptor& operator=(const AceSockAcceptor& rhs) = delete;
        AceSockAcceptor(AceSockAcceptor&& rhs) noexcept = delete;
        AceSockAcceptor& operator=(AceSockAcceptor&& rhs) noexcept = delete;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Accept(SockStream& sockStream, SockAddress& sockAddress) override;
        NODISCARD bool Accept(SockStream& sockStream) override;

        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) override;
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) override;

        NODISCARD bool EnableNonBlock() override;

        NODISCARD ACEHandleType GetACEHandle() override;

        NODISCARD std::string GetAddress() const override;
        NODISCARD int GetPort() const override;

    private:
        ACE_SOCK_Acceptor aceSockAcceptor;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_ACE_WRAPPERS_ACE_SOCK_ACCEPTOR_H
