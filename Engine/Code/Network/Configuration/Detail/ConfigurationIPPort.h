///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/17 11:40)

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
        ConfigurationIPPort(std::string ip, int port) noexcept;
        ConfigurationIPPort() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetIP() const;
        NODISCARD int GetPort() const noexcept;

    private:
        std::string ip;
        int port;
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_IMPL_H
