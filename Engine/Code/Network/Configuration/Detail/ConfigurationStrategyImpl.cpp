// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 12:35)

#include "Network/NetworkExport.h" 

#include "ConfigurationStrategyImpl.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::string;

Network::ConfigurationStrategyImpl
	::ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ServerStrategy serverStrategy,
								MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSSLStrategy openSSLStrategy,
								const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter,
								SocketSendMessage socketSendMessage, const string& ip, int port)
	:m_WrappersStrategyFlag{ wrappersStrategy }, m_PatternStrategyFlag{ serverStrategy }, m_MessageStrategyFlag{ messageStrategy },
	 m_ConnectStrategyFlag{ connectStrategy }, m_ParserStrategyFlag{ parserStrategy }, m_OpenSSLStrategyFlag{ openSSLStrategy },
	 m_SubStrategy{ subStrategy }, m_SocketSendMessage{ socketSendMessage },
	 m_ConfigurationIPPort{ ip ,port }, m_ConfigurationParameter{ configurationParameter }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ConfigurationStrategyImpl
	::ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ClientStrategy clientStrategy,
								MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSSLStrategy openSSLStrategy,
								const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter,
								SocketSendMessage socketSendMessage, const string& ip, int port)
	:m_WrappersStrategyFlag{ wrappersStrategy }, m_MessageStrategyFlag{ messageStrategy }, m_ClientStrategyFlag{ clientStrategy },
	 m_ConnectStrategyFlag{ connectStrategy }, m_ParserStrategyFlag{ parserStrategy }, m_OpenSSLStrategyFlag{ openSSLStrategy },
	 m_SubStrategy{ subStrategy }, m_SocketSendMessage{ socketSendMessage },
	 m_ConfigurationIPPort{ ip ,port }, m_ConfigurationParameter{ configurationParameter }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationStrategyImpl)

Network::WrappersStrategy Network::ConfigurationStrategyImpl
	::GetWrappersStrategy() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_WrappersStrategyFlag;
}

Network::ServerStrategy Network::ConfigurationStrategyImpl
	::GetPatternStrategy() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_PatternStrategyFlag;
}

Network::MessageStrategy Network::ConfigurationStrategyImpl
	::GetMessageStrategy() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_MessageStrategyFlag;
}

Network::ClientStrategy Network::ConfigurationStrategyImpl
	::GetClientStrategy() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_ClientStrategyFlag;
}

const Network::ConfigurationSubStrategy Network::ConfigurationStrategyImpl
	::GetConfigurationSubStrategy() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_SubStrategy;
}

bool Network::ConfigurationStrategyImpl
	::IsExist(WrappersSubStrategy wrappersSubStrategy) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_SubStrategy.IsExist(wrappersSubStrategy);
}

string Network::ConfigurationStrategyImpl
	::GetIP() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_ConfigurationIPPort.GetIP();
}

int Network::ConfigurationStrategyImpl
	::GetPort() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_ConfigurationIPPort.GetPort();
}

Network::ConnectStrategy Network::ConfigurationStrategyImpl
	::GetConnectStrategy() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_ConnectStrategyFlag;
}

Network::ParserStrategy Network::ConfigurationStrategyImpl
	::GetParserStrategy() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_ParserStrategyFlag;
}

Network::OpenSSLStrategy Network::ConfigurationStrategyImpl
	::GetOpenSSLStrategy() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_OpenSSLStrategyFlag;
}

const Network::ConfigurationParameter Network::ConfigurationStrategyImpl
	::GetConfigurationParameter() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_ConfigurationParameter;
}

Network::SocketSendMessage Network::ConfigurationStrategyImpl
	::GetSocketSendMessage() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_SocketSendMessage;
}

int Network::ConfigurationStrategyImpl
	::GetBufferSize() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	try
	{
		auto parameter = m_ConfigurationParameter.GetParameter(SYSTEM_TEXT("BufferSize"));

		if (!parameter.empty())
		{
			return boost::lexical_cast<int>(*parameter.begin());
		}

	}
	catch (...)
	{
		LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
			<< SYSTEM_TEXT("BufferSizeŒ¥≈‰÷√°£")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}

	constexpr auto defaultBufferSize = 1024;

	return defaultBufferSize;
}

