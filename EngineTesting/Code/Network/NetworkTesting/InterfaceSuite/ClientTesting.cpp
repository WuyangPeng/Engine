// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 13:15)

#include "ClientTesting.h"
#include "SingletonTestingDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/Client.h"

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, ClientTesting)
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
void Network::ClientTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::NetworkTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
}

void Network::ClientTesting ::ACETest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ACEConstructionTest);
}

void Network::ClientTesting ::BoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostConstructionTest);
}

void Network::ClientTesting ::NetworkTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkConstructionTest);
}

void Network::ClientTesting ::NullTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullConstructionTest);
}

void Network::ClientTesting ::ACEConstructionTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::ACE, ConnectStrategy::TCP, ClientStrategy::OnlySending,
                                                 MessageStrategy::Iovec, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default,
                                                 "127.0.0.1", 8010 };

    ClientSharedPtr clientContainer{ make_shared<Client>(configurationStrategy, nullptr) };
}

void Network::ClientTesting ::BoostConstructionTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Boost, ConnectStrategy::TCP, ClientStrategy::Cache,
                                                 MessageStrategy::Iovec, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default,
                                                 "127.0.0.1", 8010 };

    ClientSharedPtr clientContainer{ make_shared<Client>(configurationStrategy, nullptr) };
}

void Network::ClientTesting ::NetworkConstructionTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Network, ConnectStrategy::TCP, ClientStrategy::OnlySending,
                                                 MessageStrategy::Iovec, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default,
                                                 "127.0.0.1", 8010 };

    ClientSharedPtr clientContainer{ make_shared<Client>(configurationStrategy, nullptr) };
}

void Network::ClientTesting ::NullConstructionTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null, ConnectStrategy::TCP, ClientStrategy::Cache,
                                                 MessageStrategy::Iovec, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default,
                                                 "127.0.0.1", 8010 };

    ClientSharedPtr clientContainer{ make_shared<Client>(configurationStrategy, nullptr) };
}
