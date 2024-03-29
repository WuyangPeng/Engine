/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:19)

#include "Network/NetworkExport.h"

#include "ConfigurationStrategyFactory.h"
#include "ConfigurationStrategyImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::ConfigurationStrategyFactory::ConfigurationStrategyFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationStrategyFactory)

Network::ConfigurationStrategyFactory::ImplTypePtr Network::ConfigurationStrategyFactory::Create()
{
    return std::make_shared<ImplType>(CoreTools::DisableNotThrow::Disable);
}

Network::ConfigurationStrategyFactory::ImplTypePtr Network::ConfigurationStrategyFactory::Create(WrappersStrategy wrappersStrategy,
                                                                                                 ConnectStrategy connectStrategy,
                                                                                                 ServerStrategy serverStrategy,
                                                                                                 MessageStrategy messageStrategy,
                                                                                                 ParserStrategy parserStrategy,
                                                                                                 OpenSslStrategy openSslStrategy,
                                                                                                 EncryptedCompressionStrategy encryptedCompressionStrategy,
                                                                                                 const ConfigurationSubStrategy& subStrategy,
                                                                                                 const ConfigurationParameter& configurationParameter,
                                                                                                 SocketSendMessage socketSendMessage,
                                                                                                 const std::string& host,
                                                                                                 int port)
{
    return make_shared<ImplType>(wrappersStrategy, connectStrategy, serverStrategy, messageStrategy, parserStrategy, openSslStrategy, encryptedCompressionStrategy, subStrategy, configurationParameter, socketSendMessage, host, port);
}

Network::ConfigurationStrategyFactory::ImplTypePtr Network::ConfigurationStrategyFactory::Create(WrappersStrategy wrappersStrategy,
                                                                                                 ConnectStrategy connectStrategy,
                                                                                                 ClientStrategy clientStrategy,
                                                                                                 MessageStrategy messageStrategy,
                                                                                                 ParserStrategy parserStrategy,
                                                                                                 OpenSslStrategy openSslStrategy,
                                                                                                 EncryptedCompressionStrategy encryptedCompressionStrategy,
                                                                                                 const ConfigurationSubStrategy& subStrategy,
                                                                                                 const ConfigurationParameter& configurationParameter,
                                                                                                 SocketSendMessage socketSendMessage,
                                                                                                 const std::string& host,
                                                                                                 int port)
{
    return std::make_shared<ImplType>(wrappersStrategy, connectStrategy, clientStrategy, messageStrategy, parserStrategy, openSslStrategy, encryptedCompressionStrategy, subStrategy, configurationParameter, socketSendMessage, host, port);
}
