/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:55)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_IMPL_H
#define NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SockAcceptorImpl
    {
    public:
        using ClassType = SockAcceptorImpl;
        using FactoryType = SockAcceptorFactory;

        using EventInterface = CoreTools::EventInterface;

    public:
        SockAcceptorImpl() noexcept;
        virtual ~SockAcceptorImpl() noexcept = default;
        SockAcceptorImpl(const SockAcceptorImpl& rhs) = delete;
        SockAcceptorImpl& operator=(const SockAcceptorImpl& rhs) = delete;
        SockAcceptorImpl(SockAcceptorImpl&& rhs) noexcept = delete;
        SockAcceptorImpl& operator=(SockAcceptorImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual bool Accept(SockStream& sockStream) = 0;
        NODISCARD virtual bool Accept(SockStream& sockStream, SockAddress& sockAddress) = 0;

        virtual void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) = 0;
        virtual void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) = 0;

        NODISCARD virtual bool EnableNonBlock() = 0;

        NODISCARD virtual std::string GetAddress() const = 0;
        NODISCARD virtual int GetPort() const = 0;

        NODISCARD virtual ACEHandleType GetACEHandle();
        NODISCARD virtual BoostHandleType GetBoostHandle();
        NODISCARD virtual WinSocketType GetWinSocket();
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_IMPL_H
