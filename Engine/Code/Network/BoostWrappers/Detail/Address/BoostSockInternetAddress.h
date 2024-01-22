/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:23)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SOCK_INTERNET_ADDRESS_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SOCK_INTERNET_ADDRESS_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockAddressImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostSockInternetAddress final : public SockAddressImpl
    {
    public:
        using ClassType = BoostSockInternetAddress;
        using ParentType = SockAddressImpl;

    public:
        BoostSockInternetAddress() noexcept;
        explicit BoostSockInternetAddress(int port);
        BoostSockInternetAddress(const std::string& hostName, int port);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD const BoostInternetAddressType& GetBoostInternetAddress() const noexcept override;
        NODISCARD BoostInternetAddressType& GetBoostInternetAddress() override;

        NODISCARD SockAddressSharedPtr Clone() const override;

        NODISCARD std::string GetAddress() const override;
        NODISCARD int GetPort() const noexcept override;

    private:
        BoostInternetAddressType endpoint;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_INTERNET_ADDRESS_H
