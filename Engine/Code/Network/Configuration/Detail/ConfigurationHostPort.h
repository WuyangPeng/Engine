///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 15:38)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_IP_PORT_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_IP_PORT_H

#include "Network/NetworkDll.h"

#include <string>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ConfigurationHostPort final
    {
    public:
        using ClassType = ConfigurationHostPort;

    public:
        ConfigurationHostPort(std::string host, int port) noexcept;
        ConfigurationHostPort() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetHost() const;
        NODISCARD int GetPort() const noexcept;

    private:
        std::string host;
        int port;
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_IP_PORT_H
