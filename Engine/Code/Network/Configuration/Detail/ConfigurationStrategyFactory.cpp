///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/04 15:44)

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
