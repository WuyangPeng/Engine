//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:07)

#ifndef NETWORK_NETWORK_INTERFACE_NULL_SOCK_ADDRESS_H
#define NETWORK_NETWORK_INTERFACE_NULL_SOCK_ADDRESS_H

#include "Network/NetworkDll.h"

#include "SockAddressImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NullSockAddress final : public SockAddressImpl
    {
    public:
        using ClassType = NullSockAddress;
        using ParentType = SockAddressImpl;

    public:
        NullSockAddress(const std::string& address, int ip);

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] const SockAddressPtr Clone() const final;

        [[nodiscard]] const std::string GetAddress() const final;
        [[nodiscard]] int GetPort() const noexcept final;

    private:
        std::string m_Address;
        int m_IP;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_SOCK_ADDRESS_H
