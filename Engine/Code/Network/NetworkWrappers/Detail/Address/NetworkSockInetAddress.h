///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/23 15:25)

#ifndef NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_INET_ADDRESS_H
#define NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_INET_ADDRESS_H

#include "Network/NetworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "Network/Interface/Detail/SockAddressImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NetworkSockInetAddress : public SockAddressImpl
    {
    public:
        using ClassType = NetworkSockInetAddress;
        using ParentType = SockAddressImpl;

    public:
        explicit NetworkSockInetAddress(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);
        explicit NetworkSockInetAddress(int port);
        NetworkSockInetAddress(const std::string& hostName, int port);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD const WinSockInetAddressType& GetWinSockInetAddress() const noexcept override;
        NODISCARD WinSockInetAddressType& GetWinSockInetAddress() override;

        NODISCARD SockAddressSharedPtr Clone() const override;

        NODISCARD std::string GetAddress() const override;
        NODISCARD int GetPort() const override;

    private:
        WinSockInetAddressType inetAddress;
        std::string addressName;
    };
}

#endif  // NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_INET_ADDRESS_H
