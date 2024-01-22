/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 17:21)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_IMPL_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_IMPL_H

#include "Network/NetworkDll.h"

#include "ConfigurationHostPort.h"
#include "Network/Configuration/ConfigurationFwd.h"
#include "Network/Configuration/ConfigurationInternalFwd.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/ConfigurationSubStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

#include <string>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ConfigurationStrategyImpl final
    {
    public:
        using ClassType = ConfigurationStrategyImpl;
        using FactoryType = ConfigurationStrategyFactory;

    public:
        explicit ConfigurationStrategyImpl(CoreTools::DisableNotThrow disableNotThrow);
        ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy,
                                  ConnectStrategy connectStrategy,
                                  ServerStrategy serverStrategy,
                                  MessageStrategy messageStrategy,
                                  ParserStrategy parserStrategy,
                                  OpenSslStrategy openSslStrategy,
                                  EncryptedCompressionStrategy encryptedCompressionStrategy,
                                  ConfigurationSubStrategy subStrategy,
                                  ConfigurationParameter configurationParameter,
                                  SocketSendMessage socketSendMessage,
                                  const std::string& host,
                                  int port);
        ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy,
                                  ConnectStrategy connectStrategy,
                                  ClientStrategy clientStrategy,
                                  MessageStrategy messageStrategy,
                                  ParserStrategy parserStrategy,
                                  OpenSslStrategy openSslStrategy,
                                  EncryptedCompressionStrategy encryptedCompressionStrategy,
                                  ConfigurationSubStrategy subStrategy,
                                  ConfigurationParameter configurationParameter,
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
        WrappersStrategy wrappersStrategy{ WrappersStrategy::Boost };
        ServerStrategy patternStrategy{ ServerStrategy::Disable };
        ClientStrategy clientStrategy{ ClientStrategy::Disable };
        MessageStrategy messageStrategy{ MessageStrategy::Default };
        ConnectStrategy connectStrategy{ ConnectStrategy::Tcp };
        ParserStrategy parserStrategy{ ParserStrategy::LittleEndian };
        OpenSslStrategy openSslStrategy{ OpenSslStrategy::Default };
        EncryptedCompressionStrategy encryptedCompressionStrategy{ EncryptedCompressionStrategy::Default };
        ConfigurationSubStrategy subStrategy{ ConfigurationSubStrategy::Create() };
        SocketSendMessage socketSendMessage{};
        ConfigurationHostPort configurationIpPort{};
        ConfigurationParameter configurationParameter{ ConfigurationParameter::Create() };
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_IMPL_H
