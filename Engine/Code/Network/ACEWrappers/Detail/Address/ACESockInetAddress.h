//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 14:32)

#ifndef NETWORK_ACE_WRAPPERS_ACE_SOCK_INET_ADDRESS_H
#define NETWORK_ACE_WRAPPERS_ACE_SOCK_INET_ADDRESS_H

#include "Network/NetworkDll.h"

#ifdef NETWORK_USE_ACE

    #include "Network/Interface/Detail/SockAddressImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ACESockInetAddress : public SockAddressImpl
    {
    public:
        using ClassType = ACESockInetAddress;
        using ParentType = SockAddressImpl;

    public:
        ACESockInetAddress() noexcept;
        explicit ACESockInetAddress(int port);
        ACESockInetAddress(const std::string& hostName, int port);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const ACEInetAddressType& GetACEInetAddress() const noexcept override;
        [[nodiscard]] ACEInetAddressType& GetACEInetAddress() override;

        [[nodiscard]] const SockAddressPtr Clone() const override;

        [[nodiscard]] const std::string GetAddress() const override;
        [[nodiscard]] int GetPort() const override;

    private:
        ACEInetAddress m_ACEInetAddress;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_ACE_WRAPPERS_ACE_SOCK_INET_ADDRESS_H
