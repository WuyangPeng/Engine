// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:06)

#ifndef NETWORK_NETWORK_INTERFACE_NULL_SOCK_ACCEPTOR_H
#define NETWORK_NETWORK_INTERFACE_NULL_SOCK_ACCEPTOR_H

#include "Network/NetworkDll.h"

#include "SockAcceptorImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NullSockAcceptor : public SockAcceptorImpl
    {
    public:
        using ClassType = NullSockAcceptor;
        using ParentType = SockAcceptorImpl;

    public:
        NullSockAcceptor() noexcept;

        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

    public:
        bool Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) noexcept override;
        bool Accept(const SockStreamSharedPtr& sockStream) noexcept override;
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) noexcept override;
        void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) noexcept override;

        bool EnableNonBlock() noexcept override;

        const std::string GetAddress() const noexcept override;
        int GetPort() const noexcept override;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_SOCK_ACCEPTOR_H
