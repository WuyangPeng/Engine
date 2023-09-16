///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 17:38)

#ifndef NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_INTERNET_ADDRESS_H
#define NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_INTERNET_ADDRESS_H

#include "Network/NetworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "Network/Interface/Detail/SockAddressImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NetworkSockInternetAddress final : public SockAddressImpl
    {
    public:
        using ClassType = NetworkSockInternetAddress;
        using ParentType = SockAddressImpl;

    public:
        explicit NetworkSockInternetAddress(CoreTools::DisableNotThrow disableNotThrow);
        explicit NetworkSockInternetAddress(int port);
        NetworkSockInternetAddress(const std::string& hostName, int port);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD const WinSockInternetAddressType& GetWinSockInternetAddress() const noexcept override;
        NODISCARD WinSockInternetAddressType& GetWinSockInternetAddress() override;

        NODISCARD SockAddressSharedPtr Clone() const override;

        NODISCARD std::string GetAddress() const override;
        NODISCARD int GetPort() const override;

    private:
        WinSockInternetAddressType internetAddress;
        std::string addressName;
    };
}

#endif  // NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_INTERNET_ADDRESS_H
