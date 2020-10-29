//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 19:13)

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

const Network::ConfigurationStrategyFactory::ImplTypePtr Network::ConfigurationStrategyFactory::Create(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ServerStrategy serverStrategy, MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSSLStrategy openSSLStrategy,
                                                                                                       const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter, SocketSendMessage socketSendMessage, const string& ip, int port)
{
    return make_shared<ImplType>(wrappersStrategy, connectStrategy, serverStrategy, messageStrategy, parserStrategy, openSSLStrategy, subStrategy, configurationParameter, socketSendMessage, ip, port);
}

const Network::ConfigurationStrategyFactory::ImplTypePtr Network::ConfigurationStrategyFactory::Create(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ClientStrategy clientStrategy, MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSSLStrategy openSSLStrategy,
                                                                                                       const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter, SocketSendMessage socketSendMessage, const string& ip, int port)
{
    return make_shared<ImplType>(wrappersStrategy, connectStrategy, clientStrategy, messageStrategy, parserStrategy, openSSLStrategy, subStrategy, configurationParameter, socketSendMessage, ip, port);
}
