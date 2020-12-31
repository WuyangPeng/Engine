//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 16:24)

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
        ~BoostSockInetAddress() noexcept = default;

        BoostSockInetAddress(const BoostSockInetAddress& rhs) noexcept;
        BoostSockInetAddress& operator=(const BoostSockInetAddress& rhs) noexcept;
        BoostSockInetAddress(BoostSockInetAddress&& rhs) noexcept;
        BoostSockInetAddress& operator=(BoostSockInetAddress&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const BoostInetAddressType& GetBoostInetAddress() const noexcept override;
        [[nodiscard]] BoostInetAddressType& GetBoostInetAddress() override;

        [[nodiscard]] const SockAddressPtr Clone() const override;

        [[nodiscard]] const std::string GetAddress() const override;
        [[nodiscard]] int GetPort() const noexcept override;

    private:
        BoostInetAddressType m_Endpoint;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_INET_ADDRESS_H
