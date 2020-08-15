// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 15:45)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SOCK_INET_ADDRESS_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SOCK_INET_ADDRESS_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockAddressImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostSockInetAddress : public SockAddressImpl
    {
    public:
        using ClassType = BoostSockInetAddress;
        using ParentType = SockAddressImpl;

    public:
        BoostSockInetAddress() noexcept;
        explicit BoostSockInetAddress(int port);
        BoostSockInetAddress(const std::string& hostName, int port);
        ~BoostSockInetAddress();

        BoostSockInetAddress(const BoostSockInetAddress& rhs) noexcept;
        BoostSockInetAddress& operator=(const BoostSockInetAddress& rhs) noexcept;
        BoostSockInetAddress(BoostSockInetAddress&& rhs) noexcept;
        BoostSockInetAddress& operator=(BoostSockInetAddress&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

        const BoostInetAddressType& GetBoostInetAddress() const noexcept override;
        BoostInetAddressType& GetBoostInetAddress() override;

        const SockAddressPtr Clone() const override;

        const std::string GetAddress() const override;
        int GetPort() const noexcept override;

    private:
        BoostInetAddressType m_Endpoint;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_INET_ADDRESS_H
