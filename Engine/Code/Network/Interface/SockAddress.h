///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/09 08:59)

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

        // ACE ר�ã�����������׳��쳣��
        NODISCARD const ACEInternetAddressType& GetACEInternetAddress() const;
        NODISCARD ACEInternetAddressType& GetACEInternetAddress();

        // boost ר�ã�����������׳��쳣��
        NODISCARD const BoostInternetAddressType& GetBoostInternetAddress() const;
        NODISCARD BoostInternetAddressType& GetBoostInternetAddress();

        // Network ר�ã�����������׳��쳣��
        NODISCARD const WinSockInternetAddressType& GetWinSockInternetAddress() const;
        NODISCARD WinSockInternetAddressType& GetWinSockInternetAddress();

        NODISCARD std::string GetAddress() const;
        NODISCARD int GetPort() const;

    private:
        PackageType impl;
    };

    using SockAddressSharedPtr = std::shared_ptr<SockAddress>;
    using ConstSockAddressSharedPtr = std::shared_ptr<const SockAddress>;
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_H
