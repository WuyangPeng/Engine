///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 15:37)

#ifndef NETWORK_ACE_WRAPPERS_ACE_SOCK_INTERNET_ADDRESS_H
#define NETWORK_ACE_WRAPPERS_ACE_SOCK_INTERNET_ADDRESS_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockAddressImpl.h"

#ifdef NETWORK_USE_ACE

namespace Network
{
    class NETWORK_HIDDEN_DECLARE AceSockInternetAddress final : public SockAddressImpl
    {
    public:
        using ClassType = AceSockInternetAddress;
        using ParentType = SockAddressImpl;

    public:
        AceSockInternetAddress() noexcept;
        explicit AceSockInternetAddress(int port);
        AceSockInternetAddress(const std::string& hostName, int port);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD const ACEInternetAddressType& GetACEInternetAddress() const noexcept override;
        NODISCARD ACEInternetAddressType& GetACEInternetAddress() override;

        NODISCARD SockAddressSharedPtr Clone() const override;

        NODISCARD std::string GetAddress() const override;
        NODISCARD int GetPort() const override;

    private:
        ACEInternetAddress aceInternetAddress;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_ACE_WRAPPERS_ACE_SOCK_INTERNET_ADDRESS_H
