///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/22 13:47)

#ifndef NETWORK_ACE_WRAPPERS_ACE_SOCK_INET_ADDRESS_H
#define NETWORK_ACE_WRAPPERS_ACE_SOCK_INET_ADDRESS_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockAddressImpl.h"

#ifdef NETWORK_USE_ACE

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

        NODISCARD const ACEInetAddressType& GetACEInetAddress() const noexcept override;
        NODISCARD ACEInetAddressType& GetACEInetAddress() override;

        NODISCARD SockAddressSharedPtr Clone() const override;

        NODISCARD std::string GetAddress() const override;
        NODISCARD int GetPort() const override;

    private:
        ACEInetAddress aceInetAddress;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_ACE_WRAPPERS_ACE_SOCK_INET_ADDRESS_H
