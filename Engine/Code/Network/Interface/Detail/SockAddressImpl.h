///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/09 08:57)

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
        using SockAddressSharedPtr = std::shared_ptr<ClassType>;
        using FactoryType = SockAddressFactory;

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
