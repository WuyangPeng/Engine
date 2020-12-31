//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 18:54)

#ifndef NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_INET_ADDRESS_H
#define NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_INET_ADDRESS_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockAddressImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NetworkSockInetAddress : public SockAddressImpl
    {
    public:
        using ClassType = NetworkSockInetAddress;
        using ParentType = SockAddressImpl;

    public:
        NetworkSockInetAddress();
        explicit NetworkSockInetAddress(int port);
        NetworkSockInetAddress(const std::string& hostName, int port);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const WinSockInetAddressType& GetWinSockInetAddress() const noexcept override;
        [[nodiscard]] WinSockInetAddressType& GetWinSockInetAddress() override;

        [[nodiscard]] const SockAddressPtr Clone() const override;

        [[nodiscard]] const std::string GetAddress() const override;
        [[nodiscard]] int GetPort() const override;

    private:
        WinSockInetAddressType m_InetAddress;
        std::string m_AddressName;
    };
}

#endif  // NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_INET_ADDRESS_H
