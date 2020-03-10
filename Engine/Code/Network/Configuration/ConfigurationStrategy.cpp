// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 12:38)

#include "Network/NetworkExport.h" 

#include "ConfigurationStrategy.h"
#include "Detail/ConfigurationStrategyFactory.h"
#include "Detail/ConfigurationStrategyImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::string;

Network::ConfigurationStrategy
	::ConfigurationStrategy()
	:m_Impl{ ConfigurationStrategyFactory::Create() }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::ConfigurationStrategy
	::ConfigurationStrategy(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ServerStrategy serverStrategy, MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSSLStrategy openSSLStrategy, const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter, SocketSendMessage socketSendMessage, const string& ip, int port)
	:m_Impl{ ConfigurationStrategyFactory::Create(wrappersStrategy, connectStrategy,serverStrategy,messageStrategy,parserStrategy,openSSLStrategy,subStrategy,configurationParameter, socketSendMessage,ip,port) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::ConfigurationStrategy
	::ConfigurationStrategy(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ClientStrategy clientStrategy, MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSSLStrategy openSSLStrategy, const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter, SocketSendMessage socketSendMessage, const string& ip, int port)
	:m_Impl{ ConfigurationStrategyFactory::Create(wrappersStrategy, connectStrategy, clientStrategy, messageStrategy, parserStrategy, openSSLStrategy, subStrategy, configurationParameter, socketSendMessage, ip, port) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

PERFORMANCE_COPY_CONSTRUCTION_DEFINE(Network, ConfigurationStrategy)
IMPL_MOVE_OPERATOR_COMPLETE_DEFINE(Network, ConfigurationStrategy)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ConfigurationStrategy, GetWrappersStrategy, Network::WrappersStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ConfigurationStrategy, GetPatternStrategy, Network::ServerStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ConfigurationStrategy, GetMessageStrategy, Network::MessageStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ConfigurationStrategy, GetClientStrategy, Network::ClientStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ConfigurationStrategy, GetConnectStrategy, Network::ConnectStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ConfigurationStrategy, GetParserStrategy, Network::ParserStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ConfigurationStrategy, GetOpenSSLStrategy, Network::OpenSSLStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ConfigurationStrategy, GetSocketSendMessage, Network::SocketSendMessage)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ConfigurationStrategy, GetConfigurationSubStrategy, const Network::ConfigurationSubStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, ConfigurationStrategy, IsExist, WrappersSubStrategy, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ConfigurationStrategy, GetBufferSize, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ConfigurationStrategy, GetIP, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ConfigurationStrategy, GetPort, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ConfigurationStrategy, GetConfigurationParameter, const Network::ConfigurationParameter)




