///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.7 (2023/04/28 09:48)

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
