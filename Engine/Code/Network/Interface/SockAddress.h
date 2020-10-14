// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.4 (2020/03/11 09:58)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_H
#define NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_H

#include "Network/NetworkDll.h"

#include "NetworkInternalFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

template class NETWORK_DEFAULT_DECLARE std::weak_ptr<Network::SockAddress>;
template class NETWORK_DEFAULT_DECLARE std::enable_shared_from_this<Network::SockAddress>;

NETWORK_EXPORT_SHARED_PTR(SockAddressImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE SockAddress : public std::enable_shared_from_this<SockAddress>
    {
    public:
        // 类会返回内部变量的引用，所以无法使用延迟复制。
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(SockAddress, = default);

    public:
        explicit SockAddress(const ConfigurationStrategy& configurationStrategy);
        SockAddress(const std::string& hostName, int port, const ConfigurationStrategy& configurationStrategy);
        SockAddress(int port, const ConfigurationStrategy& configurationStrategy);
        

       CLASS_INVARIANT_DECLARE;

        // ACE 专用，其他类调用抛出异常。
        const ACEInetAddressType& GetACEInetAddress() const;
        ACEInetAddressType& GetACEInetAddress();

        // boost 专用，其他类调用抛出异常。
        const BoostInetAddressType& GetBoostInetAddress() const;
        BoostInetAddressType& GetBoostInetAddress();

        // Network 专用，其他类调用抛出异常。
        const WinSockInetAddressType& GetWinSockInetAddress() const;
        WinSockInetAddressType& GetWinSockInetAddress();

        const std::string GetAddress() const;
        int GetPort() const;

    private:
        IMPL_TYPE_DECLARE(SockAddress);
    };

    using SockAddressSharedPtr = std::shared_ptr<SockAddress>;
    using ConstSockAddressSharedPtr = std::shared_ptr<const SockAddress>;
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_H
