///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/15 09:31)

#include "SingletonTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/BaseMainManager.h"

Network::SingletonTesting::SingletonTesting(const OStreamShared& stream)
    : ParentType{ stream }, port{ 8141 + System::GetEngineeringOffsetValue() }, hostName{ "127.0.0.1" }, bufferSize{ 1048576 }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SingletonTesting)

Network::ConfigurationStrategy Network::SingletonTesting::GetACEServerConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, bufferSize);
    subStrategy.Insert(WrappersSubStrategy::SendBufferSize, bufferSize);

    return ConfigurationStrategy{ WrappersStrategy::Ace,
                                  ConnectStrategy::Tcp,
                                  ServerStrategy::Iterative,
                                  MessageStrategy::Default,
                                  ParserStrategy::LittleEndian,
                                  OpenSSLStrategy::Default,
                                  EncryptedCompressionStrategy::Default,
                                  subStrategy,
                                  ConfigurationParameter::Create(),
                                  SocketSendMessage::Default,
                                  hostName,
                                  GetShiftingPort(increase) };
}

Network::ConfigurationStrategy Network::SingletonTesting::GetBoostServerConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, bufferSize);
    subStrategy.Insert(WrappersSubStrategy::SendBufferSize, bufferSize);

    return ConfigurationStrategy{ WrappersStrategy::Boost,
                                  ConnectStrategy::Tcp,
                                  ServerStrategy::Iterative,
                                  MessageStrategy::Default,
                                  ParserStrategy::LittleEndian,
                                  OpenSSLStrategy::Default,
                                  EncryptedCompressionStrategy::Default,
                                  subStrategy,
                                  ConfigurationParameter::Create(),
                                  SocketSendMessage::Default,
                                  hostName,
                                  GetShiftingPort(increase) };
}

Network::ConfigurationStrategy Network::SingletonTesting::GetBoostFixedServerConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, bufferSize);
    subStrategy.Insert(WrappersSubStrategy::SendBufferSize, bufferSize);

    return ConfigurationStrategy{ WrappersStrategy::Boost,
                                  ConnectStrategy::Tcp,
                                  ServerStrategy::Iterative,
                                  MessageStrategy::Fixed,
                                  ParserStrategy::LittleEndian,
                                  OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                  subStrategy,
                                  ConfigurationParameter::Create(),
                                  SocketSendMessage::Default,
                                  hostName,
                                  GetShiftingPort(increase) };
}

Network::ConfigurationStrategy Network::SingletonTesting::GetBoostClientConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, bufferSize);
    subStrategy.Insert(WrappersSubStrategy::SendBufferSize, bufferSize);

    return ConfigurationStrategy{ WrappersStrategy::Boost,
                                  ConnectStrategy::Tcp,
                                  ClientStrategy::Cache,
                                  MessageStrategy::Iovec,
                                  ParserStrategy::LittleEndian,
                                  OpenSSLStrategy::Default,
                                  EncryptedCompressionStrategy::Default,
                                  subStrategy,
                                  ConfigurationParameter::Create(),
                                  SocketSendMessage::Default,
                                  hostName,
                                  GetShiftingPort(increase) };
}

Network::ConfigurationStrategy Network::SingletonTesting::GetBoostFixedClientConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, bufferSize);
    subStrategy.Insert(WrappersSubStrategy::SendBufferSize, bufferSize);

    return ConfigurationStrategy{ WrappersStrategy::Boost,
                                  ConnectStrategy::Tcp,
                                  ClientStrategy::Cache,
                                  MessageStrategy::Fixed,
                                  ParserStrategy::LittleEndian,
                                  OpenSSLStrategy::Default,
                                  EncryptedCompressionStrategy::Default,
                                  subStrategy,
                                  ConfigurationParameter::Create(),
                                  SocketSendMessage::Default,
                                  hostName,
                                  GetShiftingPort(increase) };
}

Network::ConfigurationStrategy Network::SingletonTesting::GetThreadsBoostServerConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, bufferSize);
    subStrategy.Insert(WrappersSubStrategy::SendBufferSize, bufferSize);
    subStrategy.Insert(WrappersSubStrategy::Threads, 3);

    return ConfigurationStrategy{ WrappersStrategy::Boost,
                                  ConnectStrategy::Tcp,
                                  ServerStrategy::Iterative,
                                  MessageStrategy::Default,
                                  ParserStrategy::LittleEndian,
                                  OpenSSLStrategy::Default,
                                  EncryptedCompressionStrategy::Default,
                                  subStrategy,
                                  ConfigurationParameter::Create(),
                                  SocketSendMessage::Default,
                                  hostName,
                                  GetShiftingPort(increase) };
}

Network::ConfigurationStrategy Network::SingletonTesting::GetMultiContextBoostServerConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, bufferSize);
    subStrategy.Insert(WrappersSubStrategy::SendBufferSize, bufferSize);
    subStrategy.Insert(WrappersSubStrategy::MultiContext, 3);

    return ConfigurationStrategy{ WrappersStrategy::Boost,
                                  ConnectStrategy::Tcp,
                                  ServerStrategy::Iterative,
                                  MessageStrategy::Default,
                                  ParserStrategy::LittleEndian,
                                  OpenSSLStrategy::Default,
                                  EncryptedCompressionStrategy::Default,
                                  subStrategy,
                                  ConfigurationParameter::Create(),
                                  SocketSendMessage::Default,
                                  hostName,
                                  GetShiftingPort(increase) };
}

Network::ConfigurationStrategy Network::SingletonTesting::GetNetworkServerConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, bufferSize);
    subStrategy.Insert(WrappersSubStrategy::SendBufferSize, bufferSize);

    return ConfigurationStrategy{ WrappersStrategy::Network,
                                  ConnectStrategy::Tcp,
                                  ServerStrategy::Iterative,
                                  MessageStrategy::Default,
                                  ParserStrategy::LittleEndian,
                                  OpenSSLStrategy::Default,
                                  EncryptedCompressionStrategy::Default,
                                  subStrategy,
                                  ConfigurationParameter::Create(),
                                  SocketSendMessage::Default,
                                  hostName,
                                  GetShiftingPort(increase) };
}

Network::ConfigurationStrategy Network::SingletonTesting::GetNullServerConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, bufferSize);
    subStrategy.Insert(WrappersSubStrategy::SendBufferSize, bufferSize);

    return ConfigurationStrategy{ WrappersStrategy::Null,
                                  ConnectStrategy::Tcp,
                                  ServerStrategy::Iterative,
                                  MessageStrategy::Default,
                                  ParserStrategy::LittleEndian,
                                  OpenSSLStrategy::Default,
                                  EncryptedCompressionStrategy::Default,
                                  subStrategy,
                                  ConfigurationParameter::Create(),
                                  SocketSendMessage::Default,
                                  hostName,
                                  GetShiftingPort(increase) };
}

Network::ConfigurationStrategy Network::SingletonTesting::GetSocketServerConfigurationStrategy(int increase) const
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, bufferSize);
    subStrategy.Insert(WrappersSubStrategy::SendBufferSize, bufferSize);

    return ConfigurationStrategy{ WrappersStrategy::Beast,
                                  ConnectStrategy::Tcp,
                                  ServerStrategy::Iterative,
                                  MessageStrategy::Default,
                                  ParserStrategy::LittleEndian,
                                  OpenSSLStrategy::Default,
                                  EncryptedCompressionStrategy::Default,
                                  subStrategy,
                                  ConfigurationParameter::Create(),
                                  SocketSendMessage::Default,
                                  hostName,
                                  GetShiftingPort(increase) };
}

int Network::SingletonTesting::GetPort() const noexcept
{
    return port;
}

int Network::SingletonTesting::GetShiftingPort(int shifting) const noexcept
{
    return port + shifting;
}

std::string Network::SingletonTesting::GetHostName() const
{
    return hostName;
}

int Network::SingletonTesting::GetBufferSize() const noexcept
{
    return bufferSize;
}
