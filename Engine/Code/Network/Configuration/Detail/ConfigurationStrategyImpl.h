// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 12:20)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_IMPL_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_IMPL_H

#include "Network/NetworkDll.h"

#include "ConfigurationIPPort.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/ConfigurationSubStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

#include <string>

namespace Network
{
	class ConfigurationParameter;

	class NETWORK_HIDDEN_DECLARE ConfigurationStrategyImpl
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

		WrappersStrategy GetWrappersStrategy() const;
		ServerStrategy GetPatternStrategy() const;
		MessageStrategy GetMessageStrategy() const;
		ClientStrategy GetClientStrategy() const;
		ConnectStrategy GetConnectStrategy() const;
		ParserStrategy GetParserStrategy() const;
		OpenSSLStrategy GetOpenSSLStrategy() const;
		SocketSendMessage GetSocketSendMessage() const;

		const ConfigurationSubStrategy GetConfigurationSubStrategy() const;
		bool IsExist(WrappersSubStrategy wrappersSubStrategy) const;

		const ConfigurationParameter GetConfigurationParameter() const;

		int GetBufferSize() const;

		std::string GetIP() const;
		int GetPort() const;

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

#endif // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_IMPL_H
