/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:54)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_IMPL_H
#define NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SockAddressImpl
    {
    public:
        using ClassType = SockAddressImpl;
        using FactoryType = SockAddressFactory;

        using SockAddressSharedPtr = std::shared_ptr<ClassType>;

    public:
        SockAddressImpl() noexcept = default;
        virtual ~SockAddressImpl() noexcept = default;
        SockAddressImpl(const SockAddressImpl& rhs) = default;
        SockAddressImpl& operator=(const SockAddressImpl& rhs) = default;
        SockAddressImpl(SockAddressImpl&& rhs) noexcept = default;
        SockAddressImpl& operator=(SockAddressImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual const ACEInternetAddressType& GetACEInternetAddress() const;
        NODISCARD virtual const BoostInternetAddressType& GetBoostInternetAddress() const;
        NODISCARD virtual const WinSockInternetAddressType& GetWinSockInternetAddress() const;

        NODISCARD virtual ACEInternetAddressType& GetACEInternetAddress();
        NODISCARD virtual BoostInternetAddressType& GetBoostInternetAddress();
        NODISCARD virtual WinSockInternetAddressType& GetWinSockInternetAddress();

        NODISCARD virtual SockAddressSharedPtr Clone() const = 0;

        NODISCARD virtual std::string GetAddress() const = 0;
        NODISCARD virtual int GetPort() const = 0;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_IMPL_H
