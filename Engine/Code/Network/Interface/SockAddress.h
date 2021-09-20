//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 20:25)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_H
#define NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_H

#include "Network/NetworkDll.h"

#include "NetworkInternalFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>
#include "CoreTools/Contract/ImplStaticAssertHelper.h"

template class NETWORK_DEFAULT_DECLARE std::weak_ptr<Network::SockAddress>;
template class NETWORK_DEFAULT_DECLARE std::enable_shared_from_this<Network::SockAddress>;

 
EXPORT_SHARED_PTR(Network, SockAddressImpl, NETWORK_DEFAULT_DECLARE);
namespace Network
{
    class NETWORK_DEFAULT_DECLARE SockAddress final : public std::enable_shared_from_this<SockAddress>
    {
    public:
        // ��᷵���ڲ����������ã������޷�ʹ���ӳٸ��ơ�
    public:
        void Swap(SockAddress& rhs) noexcept;

    public:
        TYPE_DECLARE(SockAddress);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~SockAddress() noexcept = default;
        SockAddress(const SockAddress& rhs);
        SockAddress& operator=(const SockAddress& rhs);
        SockAddress(SockAddress&& rhs) noexcept;
        SockAddress& operator=(SockAddress&& rhs) noexcept;

    public:
        explicit SockAddress(const ConfigurationStrategy& configurationStrategy);
        SockAddress(const std::string& hostName, int port, const ConfigurationStrategy& configurationStrategy);
        SockAddress(int port, const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

        // ACE ר�ã�����������׳��쳣��
        [[nodiscard]] const ACEInetAddressType& GetACEInetAddress() const;
        [[nodiscard]] ACEInetAddressType& GetACEInetAddress();

        // boost ר�ã�����������׳��쳣��
        [[nodiscard]] const BoostInetAddressType& GetBoostInetAddress() const;
        [[nodiscard]] BoostInetAddressType& GetBoostInetAddress();

        // Network ר�ã�����������׳��쳣��
        [[nodiscard]] const WinSockInetAddressType& GetWinSockInetAddress() const;
        [[nodiscard]] WinSockInetAddressType& GetWinSockInetAddress();

        [[nodiscard]] const std::string GetAddress() const;
        [[nodiscard]] int GetPort() const;

    private:
        using SockAddressImplPtr = std::shared_ptr<ImplType>;

    private:
        SockAddressImplPtr impl;
    };

    using SockAddressSharedPtr = std::shared_ptr<SockAddress>;
    using ConstSockAddressSharedPtr = std::shared_ptr<const SockAddress>;
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_H
