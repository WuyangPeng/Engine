/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 17:20)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_H

#include "Network/NetworkDll.h"

#include "ConfigurationFwd.h"
#include "ConfigurationSubStrategy.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

NETWORK_PERFORMANCE_UNSHARED_EXPORT_IMPL(ConfigurationStrategyImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE ConfigurationStrategy final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(ConfigurationStrategy);

    public:
        NODISCARD static ConfigurationStrategy Create();

    private:
        explicit ConfigurationStrategy(CoreTools::DisableNotThrow disableNotThrow);

    public:
        ConfigurationStrategy(const std::string& host, int port);
        ConfigurationStrategy(WrappersStrategy wrappersStrategy,
                              ConnectStrategy connectStrategy,
                              ServerStrategy serverStrategy,
                              MessageStrategy messageStrategy,
                              ParserStrategy parserStrategy,
                              OpenSslStrategy openSslStrategy,
                              EncryptedCompressionStrategy encryptedCompressionStrategy,
                              const ConfigurationSubStrategy& subStrategy,
                              const ConfigurationParameter& configurationParameter,
                              SocketSendMessage socketSendMessage,
                              const std::string& host,
                              int port);
        ConfigurationStrategy(WrappersStrategy wrappersStrategy,
                              ConnectStrategy connectStrategy,
                              ClientStrategy clientStrategy,
                              MessageStrategy messageStrategy,
                              ParserStrategy parserStrategy,
                              OpenSslStrategy openSslStrategy,
                              EncryptedCompressionStrategy encryptedCompressionStrategy,
                              const ConfigurationSubStrategy& subStrategy,
                              const ConfigurationParameter& configurationParameter,
                              SocketSendMessage socketSendMessage,
                              const std::string& host,
                              int port);

        CLASS_INVARIANT_DECLARE;

        NODISCARD WrappersStrategy GetWrappersStrategy() const noexcept;
        NODISCARD ServerStrategy GetServerStrategy() const noexcept;
        NODISCARD MessageStrategy GetMessageStrategy() const noexcept;
        NODISCARD ClientStrategy GetClientStrategy() const noexcept;
        NODISCARD ConnectStrategy GetConnectStrategy() const noexcept;
        NODISCARD ParserStrategy GetParserStrategy() const noexcept;
        NODISCARD OpenSslStrategy GetOpenSslStrategy() const noexcept;
        NODISCARD SocketSendMessage GetSocketSendMessage() const noexcept;
        NODISCARD EncryptedCompressionStrategy GetEncryptedCompressionStrategy() const noexcept;

        NODISCARD ConfigurationSubStrategy GetConfigurationSubStrategy() const noexcept;
        NODISCARD bool IsExist(WrappersSubStrategy wrappersSubStrategy) const;

        NODISCARD ConfigurationParameter GetConfigurationParameter() const noexcept;

        NODISCARD std::string GetHost() const;
        NODISCARD int GetPort() const noexcept;

        NODISCARD bool IsServer() const noexcept;
        NODISCARD bool IsClient() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_H
