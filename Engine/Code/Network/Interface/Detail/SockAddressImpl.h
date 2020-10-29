//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:15)

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
        using SockAddressPtr = std::shared_ptr<ClassType>;

    public:
        SockAddressImpl() noexcept = default;
        virtual ~SockAddressImpl() noexcept = default;
        SockAddressImpl(const SockAddressImpl& rhs) = default;
        virtual SockAddressImpl& operator=(const SockAddressImpl& rhs) = default;
        SockAddressImpl(SockAddressImpl&& rhs) noexcept = default;
        virtual SockAddressImpl& operator=(SockAddressImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] virtual const ACEInetAddressType& GetACEInetAddress() const;
        [[nodiscard]] virtual const BoostInetAddressType& GetBoostInetAddress() const;
        [[nodiscard]] virtual const WinSockInetAddressType& GetWinSockInetAddress() const;

        [[nodiscard]] virtual ACEInetAddressType& GetACEInetAddress();
        [[nodiscard]] virtual BoostInetAddressType& GetBoostInetAddress();
        [[nodiscard]] virtual WinSockInetAddressType& GetWinSockInetAddress();

        [[nodiscard]] virtual const SockAddressPtr Clone() const = 0;

        [[nodiscard]] virtual const std::string GetAddress() const = 0;
        [[nodiscard]] virtual int GetPort() const = 0;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_IMPL_H
