///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 14:40)

#include "OnlySendingClientTesting.h"
#include "SingletonTestingDetail.h"
#include "Detail/TestSocketManager.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/ConfigurationSubStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/Client.h"
#include "Network/Interface/Server.h"
#include "Network/NetworkMessage/MessageEventManager.h"
#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/NullMessage.h"

#include <thread>
#include <vector>

using std::make_shared;
using std::ostream;
using std::thread;
using std::vector;

Network::OnlySendingClientTesting::OnlySendingClientTesting(const OStreamShared& stream)
    : ParentType{ stream }, mPort{ 8141 }, messageID{ 5 }, increase{ 10 }
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

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, OnlySendingClientTesting)

void Network::OnlySendingClientTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}
void Network::OnlySendingClientTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
    increase += 10;
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
    increase += 10;
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::AsyncBoostTest);
    increase += 10;
    ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessage);
}

void Network::OnlySendingClientTesting::CreateMessage()
{
    MESSAGE_MANAGER_SINGLETON.Insert(messageID, MessageTypeCondition::CreateNullCondition(), NullMessage::Factory);
}

void Network::OnlySendingClientTesting::DestroyMessage()
{
    MESSAGE_MANAGER_SINGLETON.Remove(messageID);
}

void Network::OnlySendingClientTesting::ACETest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ACEOnlySendingClientTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ACEAsyncOnlySendingClientTest);
}

void Network::OnlySendingClientTesting::BoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostOnlySendingClientTest);
}

void Network::OnlySendingClientTesting::AsyncBoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostAsyncOnlySendingClientTest);
}

void Network::OnlySendingClientTesting::NullTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullOnlySendingClientTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NullAsyncOnlySendingClientTest);
}

void Network::OnlySendingClientTesting::ACEOnlySendingClientTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::ACE,
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
                                                 mPort + increase };

    thread firstTread{ &ClassType::ACEServerThread, this };

    vector<ClientSharedPtr> clientContainer;
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(messageID) };
    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        clientContainer.push_back(make_shared<Client>(configurationStrategy, testSocketManager));
    }

    for (auto& client : clientContainer)
    {
        constexpr int connectTime{ 10 };
        uint64_t socketID{ 0 };
        for (auto i = 0; i < connectTime; ++i)
        {
            socketID = client->Connect();
            if (socketID != 0)
            {
                break;
            }

            ASSERT_UNEQUAL(i + 1, connectTime);
        }

        client->Send(socketID, make_shared<NullMessage>(messageID));

        client.reset();
    }

    firstTread.join();
}

void Network::OnlySendingClientTesting::ACEAsyncOnlySendingClientTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::ACE,
                                                 ConnectStrategy::TCP,
                                                 ClientStrategy::OnlySending,
                                                 MessageStrategy::Default,
                                                 ParserStrategy::LittleEndian,
                                                 OpenSSLStrategy::Default,
                                                 EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy,
                                                 ConfigurationParameter::Create(),
                                                 SocketSendMessage::Default,
                                                 "127.0.0.1",
                                                 mPort + increase };

    thread firstTread{ &ClassType::ACEServerThread, this };

    vector<ClientSharedPtr> clientContainer;
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(messageID) };
    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        clientContainer.push_back(make_shared<Client>(configurationStrategy, testSocketManager));
    }

    int connectNum{ 1 };

    for (auto& client : clientContainer)
    {
        constexpr int connectTime{ 10 };
        constexpr uint64_t socketID{ 0 };
        for (auto i = 0; i < connectTime; ++i)
        {
            client->AsyncConnect();

            const auto volatile asyncConnectCount = testSocketManager->GetAsyncConnectCount();
            if (connectNum == asyncConnectCount)
            {
                break;
            }

            ASSERT_UNEQUAL(i + 1, connectTime);
        }

        MessageInterfaceSharedPtr message{ make_shared<NullMessage>(messageID) };
        client->AsyncSend(socketID, message);

        ++connectNum;

        client.reset();
    }

    firstTread.join();
}

void Network::OnlySendingClientTesting::ACEServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoACEServerThread);
}

void Network::OnlySendingClientTesting::DoACEServerThread()
{
    ConfigurationStrategy configurationStrategy{ GetACEServerConfigurationStrategy(increase) };
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(messageID) };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    auto server = make_shared<Server>(testSocketManager, configurationStrategy);

#include STSTEM_WARNING_POP

    const auto loopCount = GetTestLoopCount();
    for (;;)
    {
        ASSERT_TRUE(server->RunServer());

        const auto volatile asyncAcceptorCount = testSocketManager->GetAsyncAcceptorCount();

        if (asyncAcceptorCount == loopCount)
        {
            break;
        }
    }

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), loopCount * messageID);
}

void Network::OnlySendingClientTesting::BoostOnlySendingClientTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Boost,
                                                 ConnectStrategy::TCP,
                                                 ClientStrategy::OnlySending,
                                                 MessageStrategy::Default,
                                                 ParserStrategy::LittleEndian,
                                                 OpenSSLStrategy::Default,
                                                 EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy,
                                                 ConfigurationParameter::Create(),
                                                 SocketSendMessage::Default,
                                                 "127.0.0.1",
                                                 mPort + increase };

    vector<ClientSharedPtr> clientContainer;
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(messageID) };
    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        clientContainer.push_back(make_shared<Client>(configurationStrategy, testSocketManager));
    }

    thread firstTread{ &ClassType::BoostServerThread, this };
    thread secondTread{ &ClassType::BoostRunServerThread, this };

    for (auto& client : clientContainer)
    {
        constexpr int connectTime{ 10 };
        uint64_t socketID{ 0 };
        for (auto i = 0; i < connectTime; ++i)
        {
            socketID = client->Connect();
            if (socketID != 0)
            {
                break;
            }

            ASSERT_UNEQUAL(i + 1, connectTime);
        }

        for (auto i = 0; i < connectTime; ++i)
        {
            try
            {
                MessageInterfaceSharedPtr message{ make_shared<NullMessage>(messageID) };
                client->Send(socketID, message);
                break;
            }
            catch (...)
            {
            }
        }
    }

    secondTread.join();
    firstTread.join();
}

void Network::OnlySendingClientTesting::BoostAsyncOnlySendingClientTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Boost,
                                                 ConnectStrategy::TCP,
                                                 ClientStrategy::OnlySending,
                                                 MessageStrategy::Default,
                                                 ParserStrategy::LittleEndian,
                                                 OpenSSLStrategy::Default,
                                                 EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy,
                                                 ConfigurationParameter::Create(),
                                                 SocketSendMessage::Default,
                                                 "127.0.0.1",
                                                 mPort + increase };

    thread firstTread{ &ClassType::BoostServerThread, this };
    thread secondTread{ &ClassType::BoostRunServerThread, this };
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(messageID) };
    vector<ClientSharedPtr> clientContainer;

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        clientContainer.push_back(make_shared<Client>(configurationStrategy, testSocketManager));
    }

    int connectNum{ 1 };

    for (auto& client : clientContainer)
    {
        client->AsyncConnect();
        constexpr uint64_t socketID{ 0 };
        for (;;)
        {
            const auto volatile asyncConnectCount = testSocketManager->GetAsyncConnectCount();
            if (connectNum == asyncConnectCount)
            {
                break;
            }
        }

        client->AsyncSend(socketID, make_shared<NullMessage>(messageID));

        ++connectNum;
    }

    secondTread.join();
    firstTread.join();
}

void Network::OnlySendingClientTesting::BoostServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoBoostServerThread);
}

void Network::OnlySendingClientTesting::DoBoostServerThread()
{
    ConfigurationStrategy configurationStrategy{ GetBoostServerConfigurationStrategy(increase) };

    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(messageID) };

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), 0);

    const auto loopCount = GetTestLoopCount();
    for (;;)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

        auto server = make_shared<Server>(testSocketManager, configurationStrategy);

#include STSTEM_WARNING_POP

        ASSERT_TRUE(server->RunServer());

        if (0 < testSocketManager->GetCallBackTime())
            break;
    }

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), loopCount * messageID);

    BASE_MAIN_MANAGER_SINGLETON.StopContext();
}

void Network::OnlySendingClientTesting::BoostRunServerThread()
{
    BASE_MAIN_MANAGER_SINGLETON.Run();
}

void Network::OnlySendingClientTesting::NullOnlySendingClientTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null,
                                                 ConnectStrategy::TCP,
                                                 ClientStrategy::OnlySending,
                                                 MessageStrategy::Default,
                                                 ParserStrategy::LittleEndian,
                                                 OpenSSLStrategy::Default,
                                                 EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy,
                                                 ConfigurationParameter::Create(),
                                                 SocketSendMessage::Default,
                                                 "127.0.0.1",
                                                 mPort + increase };

    vector<ClientSharedPtr> clientContainer;
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(messageID) };
    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        clientContainer.push_back(make_shared<Client>(configurationStrategy, testSocketManager));
    }

    thread firstTread{ &ClassType::NullServerThread, this };

    for (auto& client : clientContainer)
    {
        constexpr int connectTime{ 10 };
        uint64_t socketID{ 0 };
        for (auto i = 0; i < connectTime; ++i)
        {
            socketID = client->Connect();
            if (socketID != 0)
            {
                break;
            }

            ASSERT_UNEQUAL(i + 1, connectTime);
        }

        client->Send(socketID, make_shared<NullMessage>(messageID));
    }

    firstTread.join();
}

void Network::OnlySendingClientTesting::NullServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoNullServerThread);
}

void Network::OnlySendingClientTesting::NullAsyncOnlySendingClientTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null,
                                                 ConnectStrategy::TCP,
                                                 ClientStrategy::OnlySending,
                                                 MessageStrategy::Default,
                                                 ParserStrategy::LittleEndian,
                                                 OpenSSLStrategy::Default,
                                                 EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy,
                                                 ConfigurationParameter::Create(),
                                                 SocketSendMessage::Default,
                                                 "127.0.0.1",
                                                 mPort + increase };

    thread firstTread{ &ClassType::NullServerThread, this };

    vector<ClientSharedPtr> clientContainer;
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(messageID) };
    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        clientContainer.push_back(make_shared<Client>(configurationStrategy, testSocketManager));
    }

    int connectNum{ 1 };

    for (auto& client : clientContainer)
    {
        client->AsyncConnect();
        constexpr uint64_t socketID{ 0 };
        for (;;)
        {
            const auto volatile asyncConnectCount = testSocketManager->GetAsyncConnectCount();
            if (connectNum == asyncConnectCount)
            {
                break;
            }
        }

        client->AsyncSend(socketID, make_shared<NullMessage>(messageID));

        ++connectNum;
    }

    firstTread.join();
}

void Network::OnlySendingClientTesting::DoNullServerThread() noexcept
{
}
