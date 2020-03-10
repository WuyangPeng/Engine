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

		IMPL_MOVE_AND_COPY_OPERATOR_COMPLETE_DECLARE(ConfigurationStrategy);

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
		IMPL_TYPE_DECLARE(ConfigurationStrategy);
	};
}

#endif // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_H
