///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/20 16:22)

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

        NODISCARD virtual const ACEInetAddressType& GetACEInetAddress() const;
        NODISCARD virtual const BoostInetAddressType& GetBoostInetAddress() const;
        NODISCARD virtual const WinSockInetAddressType& GetWinSockInetAddress() const;

        NODISCARD virtual ACEInetAddressType& GetACEInetAddress();
        NODISCARD virtual BoostInetAddressType& GetBoostInetAddress();
        NODISCARD virtual WinSockInetAddressType& GetWinSockInetAddress();

        NODISCARD virtual SockAddressSharedPtr Clone() const = 0;

        NODISCARD virtual std::string GetAddress() const = 0;
        NODISCARD virtual int GetPort() const = 0;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_IMPL_H
