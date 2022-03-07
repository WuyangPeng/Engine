///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/19 13:47)

#ifndef NETWORK_NETWORK_INTERFACE_ADDRESS_DATA_H
#define NETWORK_NETWORK_INTERFACE_ADDRESS_DATA_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

#include <string>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE AddressData final
    {
    public:
        using ClassType = AddressData;

    public:
        AddressData(const std::string& address, int port);
        explicit AddressData(const SockStream& sockStream);
        explicit AddressData(const BoostSockAcceptor& boostSockAcceptor);
        explicit AddressData(const BoostSockStream& boostSockStream);
        explicit AddressData(const SockAddress& sockAddress);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetAddress() const;
        NODISCARD int GetPort() const noexcept;

    private:
        std::string address;
        int port;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_ADDRESS_DATA_H
