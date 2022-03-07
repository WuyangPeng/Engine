///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/22 19:05)

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

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD const BoostInetAddressType& GetBoostInetAddress() const noexcept override;
        NODISCARD BoostInetAddressType& GetBoostInetAddress() override;

        NODISCARD SockAddressSharedPtr Clone() const override;

        NODISCARD std::string GetAddress() const override;
        NODISCARD int GetPort() const noexcept override;

    private:
        BoostInetAddressType endpoint;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_INET_ADDRESS_H
