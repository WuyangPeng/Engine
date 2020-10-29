//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 19:03)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_IMPL_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_IMPL_H

#include "Network/NetworkDll.h"

#include <string>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ConfigurationIPPort final
    {
    public:
        using ClassType = ConfigurationIPPort;

    public:
        ConfigurationIPPort(const std::string& ip, int port);
        ConfigurationIPPort() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] std::string GetIP() const;
        [[nodiscard]] int GetPort() const noexcept;

    private:
        std::string m_IP;
        int m_Port;
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_IMPL_H
