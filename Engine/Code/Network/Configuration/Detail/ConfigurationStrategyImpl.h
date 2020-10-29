//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 19:05)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_IMPL_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_IMPL_H

#include "Network/NetworkDll.h"

#include "ConfigurationIPPort.h"
#include "Network/Configuration/ConfigurationFwd.h"
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

    public:
        ConfigurationStrategyImpl() = default;
        ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ServerStrategy serverStrategy,
                                  MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSSLStrategy openSSLStrategy,
                                  const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter,
                                  SocketSendMessage socketSendMessage, const std::string& ip, int port);
        ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ClientStrategy clientStrategy,
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
        WrappersStrategy m_WrappersStrategyFlag{ WrappersStrategy::Boost };
        ServerStrategy m_PatternStrategyFlag{ ServerStrategy::Disable };
        ClientStrategy m_ClientStrategyFlag{ ClientStrategy::Disable };
        MessageStrategy m_MessageStrategyFlag{ MessageStrategy::Default };
        ConnectStrategy m_ConnectStrategyFlag{ ConnectStrategy::TCP };
        ParserStrategy m_ParserStrategyFlag{ ParserStrategy::LittleEndian };
        OpenSSLStrategy m_OpenSSLStrategyFlag{ OpenSSLStrategy::Default };
        ConfigurationSubStrategy m_SubStrategy{};
        SocketSendMessage m_SocketSendMessage{};
        ConfigurationIPPort m_ConfigurationIPPort{};
        ConfigurationParameter m_ConfigurationParameter{};
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_IMPL_H
