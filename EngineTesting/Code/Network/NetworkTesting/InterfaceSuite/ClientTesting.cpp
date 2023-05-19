///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/15 10:48)

#include "ClientTesting.h"
#include "SingletonTestingDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/Client.h"

Network::ClientTesting::ClientTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ClientTesting)

void Network::ClientTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}
void Network::ClientTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::NetworkTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
}

void Network::ClientTesting::ACETest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ACEConstructionTest);
}

void Network::ClientTesting::BoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostConstructionTest);
}

void Network::ClientTesting::NetworkTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkConstructionTest);
}

void Network::ClientTesting::NullTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullConstructionTest);
}

void Network::ClientTesting::ACEConstructionTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, GetBufferSize());
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, GetBufferSize());

    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, GetBufferSize());
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, GetBufferSize());

    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::Ace,
                                                       ConnectStrategy::Tcp,
                                                       ClientStrategy::OnlySending,
                                                       MessageStrategy::Iovec,
                                                       ParserStrategy::LittleEndian,
                                                       OpenSSLStrategy::Default,
                                                       EncryptedCompressionStrategy::Default,
                                                       configurationSubStrategy,
                                                       ConfigurationParameter::Create(),
                                                       SocketSendMessage::Default,
                                                       "127.0.0.1",
                                                       8010 };

    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    Client clientContainer{ configurationStrategy, messageEventManager };
}

void Network::ClientTesting::BoostConstructionTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, GetBufferSize());
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, GetBufferSize());

    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::Boost,
                                                       ConnectStrategy::Tcp,
                                                       ClientStrategy::Cache,
                                                       MessageStrategy::Iovec,
                                                       ParserStrategy::LittleEndian,
                                                       OpenSSLStrategy::Default,
                                                       EncryptedCompressionStrategy::Default,
                                                       configurationSubStrategy,
                                                       ConfigurationParameter::Create(),
                                                       SocketSendMessage::Default,
                                                       "127.0.0.1",
                                                       8010 };

    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    Client clientContainer{ configurationStrategy, messageEventManager };
}

void Network::ClientTesting::NetworkConstructionTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, GetBufferSize());
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, GetBufferSize());

    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::Network,
                                                       ConnectStrategy::Tcp,
                                                       ClientStrategy::OnlySending,
                                                       MessageStrategy::Iovec,
                                                       ParserStrategy::LittleEndian,
                                                       OpenSSLStrategy::Default,
                                                       EncryptedCompressionStrategy::Default,
                                                       configurationSubStrategy,
                                                       ConfigurationParameter::Create(),
                                                       SocketSendMessage::Default,
                                                       "127.0.0.1",
                                                       8010 };

    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    Client clientContainer{ configurationStrategy, messageEventManager };
}

void Network::ClientTesting::NullConstructionTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, GetBufferSize());
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, GetBufferSize());

    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null,
                                                       ConnectStrategy::Tcp,
                                                       ClientStrategy::Cache,
                                                       MessageStrategy::Iovec,
                                                       ParserStrategy::LittleEndian,
                                                       OpenSSLStrategy::Default,
                                                       EncryptedCompressionStrategy::Default,
                                                       configurationSubStrategy,
                                                       ConfigurationParameter::Create(),
                                                       SocketSendMessage::Default,
                                                       "127.0.0.1",
                                                       8010 };

    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    Client clientContainer{ configurationStrategy, messageEventManager };
}
