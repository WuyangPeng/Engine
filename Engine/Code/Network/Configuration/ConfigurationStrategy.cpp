/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:19)

#include "Network/NetworkExport.h"

#include "ConfigurationStrategy.h"
#include "Detail/ConfigurationStrategyFactory.h"
#include "Detail/ConfigurationStrategyImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::ConfigurationStrategy Network::ConfigurationStrategy::Create()
{
    return ConfigurationStrategy{ CoreTools::DisableNotThrow::Disable };
}

Network::ConfigurationStrategy::ConfigurationStrategy(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseFactory::Default }
{
    System::UnusedFunction(disableNotThrow);

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ConfigurationStrategy::ConfigurationStrategy(const std::string& host, int port)
    : impl{ CoreTools::ImplCreateUseFactory::Default,
            WrappersStrategy::Boost,
            ConnectStrategy::Tcp,
            ServerStrategy::Default,
            MessageStrategy::Default,
            ParserStrategy::LittleEndian,
            OpenSslStrategy::Default,
            EncryptedCompressionStrategy::Default,
            ConfigurationSubStrategy::Create(),
            ConfigurationParameter::Create(),
            SocketSendMessage::Default,
            host,
            port }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ConfigurationStrategy::ConfigurationStrategy(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ServerStrategy serverStrategy, MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSslStrategy openSslStrategy, EncryptedCompressionStrategy encryptedCompressionStrategy, const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter, SocketSendMessage socketSendMessage, const std::string& host, int port)
    : impl{ CoreTools::ImplCreateUseFactory::Default, wrappersStrategy, connectStrategy, serverStrategy, messageStrategy, parserStrategy, openSslStrategy, encryptedCompressionStrategy, subStrategy, configurationParameter, socketSendMessage, host, port }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ConfigurationStrategy::ConfigurationStrategy(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ClientStrategy clientStrategy, MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSslStrategy openSslStrategy, EncryptedCompressionStrategy encryptedCompressionStrategy, const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter, SocketSendMessage socketSendMessage, const std::string& host, int port)
    : impl{ CoreTools::ImplCreateUseFactory::Default, wrappersStrategy, connectStrategy, clientStrategy, messageStrategy, parserStrategy, openSslStrategy, encryptedCompressionStrategy, subStrategy, configurationParameter, socketSendMessage, host, port }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationStrategy)

Network::WrappersStrategy Network::ConfigurationStrategy::GetWrappersStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetWrappersStrategy();
}

Network::ServerStrategy Network::ConfigurationStrategy::GetServerStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetServerStrategy();
}

Network::MessageStrategy Network::ConfigurationStrategy::GetMessageStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetMessageStrategy();
}

Network::ClientStrategy Network::ConfigurationStrategy::GetClientStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetClientStrategy();
}

Network::ConnectStrategy Network::ConfigurationStrategy::GetConnectStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetConnectStrategy();
}

Network::ParserStrategy Network::ConfigurationStrategy::GetParserStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetParserStrategy();
}

Network::OpenSslStrategy Network::ConfigurationStrategy::GetOpenSslStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetOpenSslStrategy();
}

Network::SocketSendMessage Network::ConfigurationStrategy::GetSocketSendMessage() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetSocketSendMessage();
}

Network::EncryptedCompressionStrategy Network::ConfigurationStrategy::GetEncryptedCompressionStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetEncryptedCompressionStrategy();
}

Network::ConfigurationSubStrategy Network::ConfigurationStrategy::GetConfigurationSubStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetConfigurationSubStrategy();
}

bool Network::ConfigurationStrategy::IsExist(WrappersSubStrategy wrappersSubStrategy) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->IsExist(wrappersSubStrategy);
}

Network::ConfigurationParameter Network::ConfigurationStrategy::GetConfigurationParameter() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetConfigurationParameter();
}

std::string Network::ConfigurationStrategy::GetHost() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetHost();
}

int Network::ConfigurationStrategy::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetPort();
}

bool Network::ConfigurationStrategy::IsServer() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->IsServer();
}

bool Network::ConfigurationStrategy::IsClient() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->IsClient();
}
