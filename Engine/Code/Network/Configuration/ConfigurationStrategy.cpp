//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 19:16)

#include "Network/NetworkExport.h"

#include "ConfigurationStrategy.h"
#include "Detail/ConfigurationStrategyFactory.h"
#include "Detail/ConfigurationStrategyImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)

Network::ConfigurationStrategy::ConfigurationStrategy()
    : m_Impl{ ConfigurationStrategyFactory::Create() }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_POP

Network::ConfigurationStrategy::ConfigurationStrategy(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ServerStrategy serverStrategy, MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSSLStrategy openSSLStrategy, const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter, SocketSendMessage socketSendMessage, const string& ip, int port)
    : m_Impl{ ConfigurationStrategyFactory::Create(wrappersStrategy, connectStrategy, serverStrategy, messageStrategy, parserStrategy, openSSLStrategy, subStrategy, configurationParameter, socketSendMessage, ip, port) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::ConfigurationStrategy::ConfigurationStrategy(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ClientStrategy clientStrategy, MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSSLStrategy openSSLStrategy, const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter, SocketSendMessage socketSendMessage, const string& ip, int port)
    : m_Impl{ ConfigurationStrategyFactory::Create(wrappersStrategy, connectStrategy, clientStrategy, messageStrategy, parserStrategy, openSSLStrategy, subStrategy, configurationParameter, socketSendMessage, ip, port) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, ConfigurationStrategy)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetWrappersStrategy, Network::WrappersStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetPatternStrategy, Network::ServerStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetMessageStrategy, Network::MessageStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetClientStrategy, Network::ClientStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetConnectStrategy, Network::ConnectStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetParserStrategy, Network::ParserStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetOpenSSLStrategy, Network::OpenSSLStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetSocketSendMessage, Network::SocketSendMessage)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetConfigurationSubStrategy, const Network::ConfigurationSubStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, ConfigurationStrategy, IsExist, WrappersSubStrategy, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ConfigurationStrategy, GetBufferSize, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ConfigurationStrategy, GetIP, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetPort, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetConfigurationParameter, const Network::ConfigurationParameter)
