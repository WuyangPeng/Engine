///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 17:07)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_H
#define NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_H

#include "Network/NetworkDll.h"

#include "NetworkInternalFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

template class NETWORK_DEFAULT_DECLARE std::weak_ptr<Network::SockAddress>;
template class NETWORK_DEFAULT_DECLARE std::enable_shared_from_this<Network::SockAddress>;

NETWORK_COPY_UNSHARED_EXPORT_IMPL(SockAddress, SockAddressImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE SockAddress final : public std::enable_shared_from_this<SockAddress>
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(SockAddress);

    public:
        explicit SockAddress(const ConfigurationStrategy& configurationStrategy);
        SockAddress(const std::string& hostName, int port, const ConfigurationStrategy& configurationStrategy);
        SockAddress(int port, const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

        // ACE 专用，其他类调用抛出异常。
        NODISCARD const ACEInetAddressType& GetACEInetAddress() const;
        NODISCARD ACEInetAddressType& GetACEInetAddress();

        // boost 专用，其他类调用抛出异常。
        NODISCARD const BoostInetAddressType& GetBoostInetAddress() const;
        NODISCARD BoostInetAddressType& GetBoostInetAddress();

        // Network 专用，其他类调用抛出异常。
        NODISCARD const WinSockInetAddressType& GetWinSockInetAddress() const;
        NODISCARD WinSockInetAddressType& GetWinSockInetAddress();

        NODISCARD std::string GetAddress() const;
        NODISCARD int GetPort() const;

    private:
        PackageType impl;
    };

    using SockAddressSharedPtr = std::shared_ptr<SockAddress>;
    using ConstSockAddressSharedPtr = std::shared_ptr<const SockAddress>;
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_H
