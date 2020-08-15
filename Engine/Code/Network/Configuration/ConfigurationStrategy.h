// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 12:30)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_H

#include "Network/NetworkDll.h"

#include "ConfigurationFwd.h"
#include "ConfigurationSubStrategy.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

NETWORK_EXPORT_SHARED_PTR(ConfigurationStrategyImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE ConfigurationStrategy
    {
    public:
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(ConfigurationStrategy);

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

        WrappersStrategy GetWrappersStrategy() const noexcept;
        ServerStrategy GetPatternStrategy() const noexcept;
        MessageStrategy GetMessageStrategy() const noexcept;
        ClientStrategy GetClientStrategy() const noexcept;
        ConnectStrategy GetConnectStrategy() const noexcept;
        ParserStrategy GetParserStrategy() const noexcept;
        OpenSSLStrategy GetOpenSSLStrategy() const noexcept;
        SocketSendMessage GetSocketSendMessage() const noexcept;

        const ConfigurationSubStrategy GetConfigurationSubStrategy() const noexcept;
        bool IsExist(WrappersSubStrategy wrappersSubStrategy) const;

        const ConfigurationParameter GetConfigurationParameter() const noexcept;

        int GetBufferSize() const;

        std::string GetIP() const;
        int GetPort() const noexcept;

    private:
        IMPL_TYPE_DECLARE(ConfigurationStrategy);
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_H
