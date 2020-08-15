// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 12:19)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_H

#include "Network/NetworkDll.h" 
#include "Network/Configuration/ConfigurationFwd.h"

#include <memory>
#include <string>

namespace Network
{
	class ConfigurationStrategyImpl;

	class NETWORK_HIDDEN_DECLARE ConfigurationStrategyFactory
	{
	public:
		using ClassType = ConfigurationStrategyFactory;
		using ImplType = ConfigurationStrategyImpl;
		using ImplTypePtr = std::shared_ptr<ImplType>;

	public:
		ConfigurationStrategyFactory() noexcept;

		CLASS_INVARIANT_DECLARE;

		static const ImplTypePtr Create();
		static const ImplTypePtr Create(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ServerStrategy serverStrategy,
										MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSSLStrategy openSSLStrategy,
										const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter,
										SocketSendMessage socketSendMessage, const std::string& ip, int port);
		static const ImplTypePtr Create(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ClientStrategy clientStrategy,
										MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSSLStrategy openSSLStrategy,
										const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter,
										SocketSendMessage socketSendMessage, const std::string& ip, int port);
	};
}

#endif // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_H
