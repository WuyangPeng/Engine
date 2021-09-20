//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 19:06)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_H

#include "Network/NetworkDll.h"

#include "ConfigurationFwd.h"
#include "ConfigurationSubStrategy.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <string>

NETWORK_PERFORMANCE_UNSHARED_EXPORT_IMPL(ConfigurationStrategyImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE ConfigurationStrategy final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(ConfigurationStrategy);

    public:
        ConfigurationStrategy();
        ConfigurationStrategy(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ServerStrategy serverStrategy,
                              MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSSLStrategy openSSLStrategy,
                              const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter,
                              SocketSendMessage socketSendMessage, const std::string& ip, int port);
        ConfigurationStrategy(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ClientStrategy clientStrategy,
                              MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSSLStrategy openSSLStrategy,
                              const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter,
                              SocketSendMessage socketSendMessage, const std::string& ip, int port);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] WrappersStrategy GetWrappersStrategy() const noexcept;
        [[nodiscard]] ServerStrategy GetPatternStrategy() const noexcept;
        [[nodiscard]] MessageStrategy GetMessageStrategy() const noexcept;
        [[nodiscard]] ClientStrategy GetClientStrategy() const noexcept;
        [[nodiscard]] ConnectStrategy GetConnectStrategy() const noexcept;
        [[nodiscard]] ParserStrategy GetParserStrategy() const noexcept;
        [[nodiscard]] OpenSSLStrategy GetOpenSSLStrategy() const noexcept;
        [[nodiscard]] SocketSendMessage GetSocketSendMessage() const noexcept;

        [[nodiscard]] const ConfigurationSubStrategy GetConfigurationSubStrategy() const noexcept;
        [[nodiscard]] bool IsExist(WrappersSubStrategy wrappersSubStrategy) const;

        [[nodiscard]] const ConfigurationParameter GetConfigurationParameter() const noexcept;

        [[nodiscard]] int GetBufferSize() const;

        [[nodiscard]] std::string GetIP() const;
        [[nodiscard]] int GetPort() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_H
