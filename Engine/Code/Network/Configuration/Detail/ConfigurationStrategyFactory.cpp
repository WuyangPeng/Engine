///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/17 13:50)

#include "Network/NetworkExport.h"

#include "ConfigurationStrategyFactory.h"
#include "ConfigurationStrategyImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::make_shared;
using std::string;

Network::ConfigurationStrategyFactory::ConfigurationStrategyFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationStrategyFactory)

// static
const Network::ConfigurationStrategyFactory::ImplTypePtr Network::ConfigurationStrategyFactory::Create()
{
    return make_shared<ImplType>();
}

const Network::ConfigurationStrategyFactory::ImplTypePtr Network::ConfigurationStrategyFactory::Create(WrappersStrategy wrappersStrategy,
                                                                                                       ConnectStrategy connectStrategy,
                                                                                                       ServerStrategy serverStrategy,
                                                                                                       MessageStrategy messageStrategy,
                                                                                                       ParserStrategy parserStrategy,
                                                                                                       OpenSSLStrategy openSSLStrategy,
                                                                                                       EncryptedCompressionStrategy encryptedCompressionStrategy,
                                                                                                       const ConfigurationSubStrategy& subStrategy,
                                                                                                       const ConfigurationParameter& configurationParameter,
                                                                                                       SocketSendMessage socketSendMessage,
                                                                                                       const string& ip,
                                                                                                       int port)
{
    return make_shared<ImplType>(wrappersStrategy, connectStrategy, serverStrategy, messageStrategy, parserStrategy, openSSLStrategy, encryptedCompressionStrategy, subStrategy, configurationParameter, socketSendMessage, ip, port);
}

const Network::ConfigurationStrategyFactory::ImplTypePtr Network::ConfigurationStrategyFactory::Create(WrappersStrategy wrappersStrategy,
                                                                                                       ConnectStrategy connectStrategy,
                                                                                                       ClientStrategy clientStrategy,
                                                                                                       MessageStrategy messageStrategy,
                                                                                                       ParserStrategy parserStrategy,
                                                                                                       OpenSSLStrategy openSSLStrategy,
                                                                                                       EncryptedCompressionStrategy encryptedCompressionStrategy,
                                                                                                       const ConfigurationSubStrategy& subStrategy,
                                                                                                       const ConfigurationParameter& configurationParameter,
                                                                                                       SocketSendMessage socketSendMessage,
                                                                                                       const string& ip,
                                                                                                       int port)
{
    return make_shared<ImplType>(wrappersStrategy, connectStrategy, clientStrategy, messageStrategy, parserStrategy, openSSLStrategy, encryptedCompressionStrategy, subStrategy, configurationParameter, socketSendMessage, ip, port);
}
