///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/17 13:57)

#include "Network/NetworkExport.h"

#include "ConfigurationStrategy.h"
#include "Detail/ConfigurationStrategyFactory.h"
#include "Detail/ConfigurationStrategyImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

Network::ConfigurationStrategy Network::ConfigurationStrategy::Create()
{
    return ConfigurationStrategy{ CoreTools::DisableNotThrow::Disable };
}

Network::ConfigurationStrategy::ConfigurationStrategy(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseFactory::Default }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::ConfigurationStrategy::ConfigurationStrategy(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ServerStrategy serverStrategy, MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSSLStrategy openSSLStrategy, EncryptedCompressionStrategy encryptedCompressionStrategy, const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter, SocketSendMessage socketSendMessage, const string& ip, int port)
    : impl{ CoreTools::ImplCreateUseFactory::Default, wrappersStrategy, connectStrategy, serverStrategy, messageStrategy, parserStrategy, openSSLStrategy, encryptedCompressionStrategy, subStrategy, configurationParameter, socketSendMessage, ip, port }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::ConfigurationStrategy::ConfigurationStrategy(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ClientStrategy clientStrategy, MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSSLStrategy openSSLStrategy, EncryptedCompressionStrategy encryptedCompressionStrategy, const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter, SocketSendMessage socketSendMessage, const string& ip, int port)
    : impl{ CoreTools::ImplCreateUseFactory::Default, wrappersStrategy, connectStrategy, clientStrategy, messageStrategy, parserStrategy, openSSLStrategy, encryptedCompressionStrategy, subStrategy, configurationParameter, socketSendMessage, ip, port }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationStrategy)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetWrappersStrategy, Network::WrappersStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetPatternStrategy, Network::ServerStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetMessageStrategy, Network::MessageStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetClientStrategy, Network::ClientStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetConnectStrategy, Network::ConnectStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetParserStrategy, Network::ParserStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetOpenSSLStrategy, Network::OpenSSLStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetEncryptedCompressionStrategy, Network::EncryptedCompressionStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetSocketSendMessage, Network::SocketSendMessage)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetConfigurationSubStrategy, Network::ConfigurationSubStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, ConfigurationStrategy, IsExist, WrappersSubStrategy, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ConfigurationStrategy, GetBufferSize, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, ConfigurationStrategy, GetIP, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetPort, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, ConfigurationStrategy, GetConfigurationParameter, Network::ConfigurationParameter)
