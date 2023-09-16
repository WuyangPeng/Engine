///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 15:44)

#include "Network/NetworkExport.h"

#include "ConfigurationStrategyImpl.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"

using namespace std::literals;

Network::ConfigurationStrategyImpl::ConfigurationStrategyImpl(CoreTools::DisableNotThrow disableNotThrow)
{
    System::UnusedFunction(disableNotThrow);

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ConfigurationStrategyImpl::ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy,
                                                              ConnectStrategy connectStrategy,
                                                              ServerStrategy serverStrategy,
                                                              MessageStrategy messageStrategy,
                                                              ParserStrategy parserStrategy,
                                                              OpenSslStrategy openSslStrategy,
                                                              EncryptedCompressionStrategy encryptedCompressionStrategy,
                                                              ConfigurationSubStrategy subStrategy,
                                                              ConfigurationParameter configurationParameter,
                                                              SocketSendMessage socketSendMessage,
                                                              const std::string& host,
                                                              int port)
    : wrappersStrategy{ wrappersStrategy },
      patternStrategy{ serverStrategy },
      messageStrategy{ messageStrategy },
      connectStrategy{ connectStrategy },
      parserStrategy{ parserStrategy },
      openSslStrategy{ openSslStrategy },
      encryptedCompressionStrategy{ encryptedCompressionStrategy },
      subStrategy{ std::move(subStrategy) },
      socketSendMessage{ socketSendMessage },
      configurationIpPort{ host, port },
      configurationParameter{ std::move(configurationParameter) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ConfigurationStrategyImpl::ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy,
                                                              ConnectStrategy connectStrategy,
                                                              ClientStrategy clientStrategy,
                                                              MessageStrategy messageStrategy,
                                                              ParserStrategy parserStrategy,
                                                              OpenSslStrategy openSslStrategy,
                                                              EncryptedCompressionStrategy encryptedCompressionStrategy,
                                                              ConfigurationSubStrategy subStrategy,
                                                              ConfigurationParameter configurationParameter,
                                                              SocketSendMessage socketSendMessage,
                                                              const std::string& host,
                                                              int port)
    : wrappersStrategy{ wrappersStrategy },
      clientStrategy{ clientStrategy },
      messageStrategy{ messageStrategy },
      connectStrategy{ connectStrategy },
      parserStrategy{ parserStrategy },
      openSslStrategy{ openSslStrategy },
      encryptedCompressionStrategy{ encryptedCompressionStrategy },
      subStrategy{ std::move(subStrategy) },
      socketSendMessage{ socketSendMessage },
      configurationIpPort{ host, port },
      configurationParameter{ std::move(configurationParameter) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationStrategyImpl)

Network::WrappersStrategy Network::ConfigurationStrategyImpl::GetWrappersStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return wrappersStrategy;
}

Network::ServerStrategy Network::ConfigurationStrategyImpl::GetServerStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return patternStrategy;
}

Network::MessageStrategy Network::ConfigurationStrategyImpl::GetMessageStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return messageStrategy;
}

Network::ClientStrategy Network::ConfigurationStrategyImpl::GetClientStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return clientStrategy;
}

Network::ConfigurationSubStrategy Network::ConfigurationStrategyImpl::GetConfigurationSubStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return subStrategy;
}

bool Network::ConfigurationStrategyImpl::IsExist(WrappersSubStrategy wrappersSubStrategy) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return subStrategy.IsExist(wrappersSubStrategy);
}

std::string Network::ConfigurationStrategyImpl::GetHost() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return configurationIpPort.GetHost();
}

int Network::ConfigurationStrategyImpl::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return configurationIpPort.GetPort();
}

bool Network::ConfigurationStrategyImpl::IsServer() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return patternStrategy != ServerStrategy::Disable;
}

bool Network::ConfigurationStrategyImpl::IsClient() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return clientStrategy != ClientStrategy::Disable;
}

Network::ConnectStrategy Network::ConfigurationStrategyImpl::GetConnectStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return connectStrategy;
}

Network::ParserStrategy Network::ConfigurationStrategyImpl::GetParserStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return parserStrategy;
}

Network::OpenSslStrategy Network::ConfigurationStrategyImpl::GetOpenSslStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return openSslStrategy;
}

Network::ConfigurationParameter Network::ConfigurationStrategyImpl::GetConfigurationParameter() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return configurationParameter;
}

Network::SocketSendMessage Network::ConfigurationStrategyImpl::GetSocketSendMessage() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return socketSendMessage;
}

Network::EncryptedCompressionStrategy Network::ConfigurationStrategyImpl::GetEncryptedCompressionStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return encryptedCompressionStrategy;
}
