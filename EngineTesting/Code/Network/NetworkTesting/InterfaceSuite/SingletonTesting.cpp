// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 13:19)

#include "SingletonTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/BaseMainManager.h"

using std::ostream;

Network::SingletonTesting ::SingletonTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr }, m_Port{ 8141 }, m_HostName{ "127.0.0.1" }
{
    m_Port += System::GetEngineeringOffsetValue();

    NETWORK_SELF_CLASS_IS_VALID_0;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SingletonTesting)

const Network::ConfigurationStrategy Network::SingletonTesting ::GetACEServerConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();

    return ConfigurationStrategy{ WrappersStrategy::ACE, ConnectStrategy::TCP, ServerStrategy::Iterative,
                                  MessageStrategy::Default, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                  subStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default, m_HostName, m_Port + increase };
}

const Network::ConfigurationStrategy Network::SingletonTesting ::GetBoostServerConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();

    return ConfigurationStrategy{ WrappersStrategy::Boost, ConnectStrategy::TCP, ServerStrategy::Iterative,
                                  MessageStrategy::Default, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                  subStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default, m_HostName, m_Port + increase };
}

const Network::ConfigurationStrategy Network::SingletonTesting ::GetBoostFixedServerConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();

    return ConfigurationStrategy{ WrappersStrategy::Boost, ConnectStrategy::TCP, ServerStrategy::Iterative,
                                  MessageStrategy::Fixed, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                  subStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default, m_HostName, m_Port + increase };
}

const Network::ConfigurationStrategy Network::SingletonTesting ::GetBoostClientConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();

    return ConfigurationStrategy{ WrappersStrategy::Boost, ConnectStrategy::TCP, ClientStrategy::Cache,
                                  MessageStrategy::Iovec, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                  subStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default, m_HostName, m_Port + increase };
}

const Network::ConfigurationStrategy Network::SingletonTesting ::GetBoostFixedClientConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();

    return ConfigurationStrategy{ WrappersStrategy::Boost, ConnectStrategy::TCP, ClientStrategy::Cache,
                                  MessageStrategy::Fixed, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                  subStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default, m_HostName, m_Port + increase };
}

const Network::ConfigurationStrategy Network::SingletonTesting ::GetThreadsBoostServerConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::Threads, 3);

    return ConfigurationStrategy{ WrappersStrategy::Boost, ConnectStrategy::TCP, ServerStrategy::Iterative,
                                  MessageStrategy::Default, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                  subStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default, m_HostName, m_Port + increase };
}

const Network::ConfigurationStrategy Network::SingletonTesting ::GetMultiContextBoostServerConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::MultiContext, 3);

    return ConfigurationStrategy{ WrappersStrategy::Boost, ConnectStrategy::TCP, ServerStrategy::Iterative,
                                  MessageStrategy::Default, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                  subStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default, m_HostName, m_Port + increase };
}

const Network::ConfigurationStrategy Network::SingletonTesting ::GetNetworkServerConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();

    return ConfigurationStrategy{ WrappersStrategy::Network, ConnectStrategy::TCP, ServerStrategy::Iterative,
                                  MessageStrategy::Default, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                  subStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default, m_HostName, m_Port + increase };
}

const Network::ConfigurationStrategy Network::SingletonTesting ::GetNullServerConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();

    return ConfigurationStrategy{ WrappersStrategy::Null, ConnectStrategy::TCP, ServerStrategy::Iterative,
                                  MessageStrategy::Default, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                  subStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default, m_HostName, m_Port + increase };
}

const Network::ConfigurationStrategy Network::SingletonTesting ::GetSocketServerConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();

    return ConfigurationStrategy{ WrappersStrategy::Socket, ConnectStrategy::TCP, ServerStrategy::Iterative,
                                  MessageStrategy::Default, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                  subStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default, m_HostName, m_Port + increase };
}

int Network::SingletonTesting ::GetPort() const noexcept
{
    return m_Port;
}

const std::string Network::SingletonTesting ::GetHostName() const
{
    return m_HostName;
}
