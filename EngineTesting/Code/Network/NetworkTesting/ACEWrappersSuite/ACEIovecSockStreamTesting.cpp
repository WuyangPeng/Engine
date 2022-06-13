///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 14:17)

#include "ACEIovecSockStreamTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockConnector.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/NullMessage.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

#include <array>
#include <thread>

using std::array;
using std::make_shared;
using std::ostream;
using std::thread;

Network::ACEIovecSockStreamTesting::ACEIovecSockStreamTesting(const OStreamShared& stream)
    : ParentType{ stream }, mPort{ 7550 }
{
#ifdef _DEBUG

    mPort += 4;

#endif  // _DEBUG

#ifdef BUILDING_NETWORK_STATIC

    mPort += 2;

#endif  // BUILDING_NETWORK_STATIC

#ifdef _WIN64

    mPort += 1;

#endif  // _WIN64

    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ACEIovecSockStreamTesting)

void Network::ACEIovecSockStreamTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

namespace Network
{
    using TestingType = SockStream;
}

void Network::ACEIovecSockStreamTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::StreamTest);
}

void Network::ACEIovecSockStreamTesting::StreamTest()
{
    thread firstTread{ &ClassType::ACEServerThread, this };
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy clientConfigurationStrategy{ WrappersStrategy::ACE,
                                                       ConnectStrategy::TCP,
                                                       ClientStrategy::OnlySending,
                                                       MessageStrategy::Iovec,
                                                       ParserStrategy::LittleEndian,
                                                       OpenSSLStrategy::Default,
                                                       EncryptedCompressionStrategy::Default,
                                                       configurationSubStrategy,
                                                       ConfigurationParameter::Create(),
                                                       SocketSendMessage::Default,
                                                       "127.0.0.1",
                                                       mPort };

    SockStreamSharedPtr sockStream{ make_shared<TestingType>(clientConfigurationStrategy) };

    SockConnector sockConnector{ clientConfigurationStrategy };
    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(clientConfigurationStrategy.GetIP(), clientConfigurationStrategy.GetPort(), clientConfigurationStrategy) };

    if (sockConnector.Connect(sockStream, sockAddress))
    {
        MAYBE_UNUSED const auto value0 = sockStream->EnableNonBlock();

        MessageBufferSharedPtr buffer{ std::make_shared<MessageBuffer>(BuffBlockSize::Size512, 0, clientConfigurationStrategy.GetParserStrategy()) };
        buffer->AddCurrentWriteIndex(50);

        MAYBE_UNUSED const auto value1 = sockStream->Send(buffer);
        buffer->ClearCurrentWriteIndex();

        MAYBE_UNUSED const auto value2 = sockStream->Receive(buffer);
    }

    firstTread.join();

    thread seconTread{ &ClassType::ACEServerThread, this };

    sockStream = make_shared<TestingType>(clientConfigurationStrategy);

    if (sockConnector.Connect(sockStream, sockAddress))
    {
        MAYBE_UNUSED const auto value = sockStream->EnableNonBlock();

        MessageBufferSharedPtr buffer{ std::make_shared<MessageBuffer>(BuffBlockSize::Size512, 0, clientConfigurationStrategy.GetParserStrategy()) };

        TestSocketManagerSharedPtr socketManager{ make_shared<TestSocketManager>(5) };
        buffer->AddCurrentWriteIndex(50);
        sockStream->AsyncSend(socketManager, buffer);
        buffer->ClearCurrentWriteIndex();
        sockStream->AsyncReceive(socketManager, buffer);
    }

    seconTread.join();
}

void Network::ACEIovecSockStreamTesting::ACEServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoACEServerThread);
}

void Network::ACEIovecSockStreamTesting::DoACEServerThread()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();
    ConfigurationStrategy serverConfigurationStrategy{ WrappersStrategy::ACE,
                                                       ConnectStrategy::TCP,
                                                       ServerStrategy::Iterative,
                                                       MessageStrategy::Default,
                                                       ParserStrategy::LittleEndian,
                                                       OpenSSLStrategy::Default,
                                                       EncryptedCompressionStrategy::Default,
                                                       configurationSubStrategy,
                                                       ConfigurationParameter::Create(),
                                                       SocketSendMessage::Default,
                                                       "127.0.0.1",
                                                       mPort };

    constexpr auto messageID = 5;
    ConfigurationStrategy configurationStrategy{ serverConfigurationStrategy };
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(messageID) };

    ServerSharedPtr server{ make_shared<Server>(testSocketManager, configurationStrategy) };

    testSocketManager->SetServerWeakPtr(server);

    constexpr auto loopCount = 1;
    for (;;)
    {
        ASSERT_TRUE(server->RunServer());

        const auto volatile asyncAcceptorCount = testSocketManager->GetAsyncAcceptorCount();

        if (asyncAcceptorCount == loopCount)
        {
            break;
        }
    }
}