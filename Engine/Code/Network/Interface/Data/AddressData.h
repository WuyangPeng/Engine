//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 15:30)

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

        [[nodiscard]] std::string GetAddress() const;
        [[nodiscard]] int GetPort() const noexcept;

    private:
        std::string m_Address;
        int m_Port;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_ADDRESS_DATA_H
