///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 14:19)

#include "ClientTesting.h"
#include "SingletonTestingDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/Client.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::make_shared;

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
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, 1048576);
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, 1048576);

    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, 1048576);
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, 1048576);

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Ace,
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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    ClientSharedPtr clientContainer{ make_shared<Client>(configurationStrategy, nullptr) };

#include STSTEM_WARNING_POP
}

void Network::ClientTesting::BoostConstructionTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, 1048576);
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, 1048576);

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Boost,
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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    ClientSharedPtr clientContainer{ make_shared<Client>(configurationStrategy, nullptr) };

#include STSTEM_WARNING_POP
}

void Network::ClientTesting::NetworkConstructionTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, 1048576);
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, 1048576);

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Network,
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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    ClientSharedPtr clientContainer{ make_shared<Client>(configurationStrategy, nullptr) };

#include STSTEM_WARNING_POP
}

void Network::ClientTesting::NullConstructionTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, 1048576);
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, 1048576);

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null,
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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    ClientSharedPtr clientContainer{ make_shared<Client>(configurationStrategy, nullptr) };

#include STSTEM_WARNING_POP
}
