///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/17 13:52)

#include "Network/NetworkExport.h"

#include "ConfigurationStrategyImpl.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"

using std::string;
using namespace std::literals;

Network::ConfigurationStrategyImpl::ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy,
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
    : wrappersStrategy{ wrappersStrategy },
      patternStrategy{ serverStrategy },
      messageStrategy{ messageStrategy },
      connectStrategy{ connectStrategy },
      m_ParserStrategyFlag{ parserStrategy },
      openSSLStrategy{ openSSLStrategy },
      encryptedCompressionStrategy{ encryptedCompressionStrategy },
      subStrategy{ subStrategy },
      socketSendMessage{ socketSendMessage },
      configurationIPPort{ ip, port },
      configurationParameter{ configurationParameter }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ConfigurationStrategyImpl::ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy,
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
    : wrappersStrategy{ wrappersStrategy },
      messageStrategy{ messageStrategy },
      clientStrategy{ clientStrategy },
      connectStrategy{ connectStrategy },
      m_ParserStrategyFlag{ parserStrategy },
      openSSLStrategy{ openSSLStrategy },
      encryptedCompressionStrategy{ encryptedCompressionStrategy },
      subStrategy{ subStrategy },
      socketSendMessage{ socketSendMessage },
      configurationIPPort{ ip, port },
      configurationParameter{ configurationParameter }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationStrategyImpl)

Network::WrappersStrategy Network::ConfigurationStrategyImpl::GetWrappersStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return wrappersStrategy;
}

Network::ServerStrategy Network::ConfigurationStrategyImpl::GetPatternStrategy() const noexcept
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

string Network::ConfigurationStrategyImpl::GetIP() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return configurationIPPort.GetIP();
}

int Network::ConfigurationStrategyImpl::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return configurationIPPort.GetPort();
}

Network::ConnectStrategy Network::ConfigurationStrategyImpl::GetConnectStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return connectStrategy;
}

Network::ParserStrategy Network::ConfigurationStrategyImpl::GetParserStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_ParserStrategyFlag;
}

Network::OpenSSLStrategy Network::ConfigurationStrategyImpl::GetOpenSSLStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return openSSLStrategy;
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

int Network::ConfigurationStrategyImpl::GetBufferSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    try
    {
        auto parameter = configurationParameter.GetParameter(SYSTEM_TEXT("BufferSize"s));

        if (!parameter.empty())
        {
            return boost::lexical_cast<int>(*parameter.begin());
        }
    }
    catch (...)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
            << SYSTEM_TEXT("BufferSize未配置。")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }

    constexpr auto defaultBufferSize = 1024;

    return defaultBufferSize;
}

Network::EncryptedCompressionStrategy Network::ConfigurationStrategyImpl::GetEncryptedCompressionStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return encryptedCompressionStrategy;
}
