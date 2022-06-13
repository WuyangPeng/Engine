///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 14:16)

#include "CacheClientTesting.h"
#include "SingletonTestingDetail.h"
#include "Detail/TestSocketManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/Client.h"
#include "Network/Interface/Server.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/NullMessage.h"

#include <thread>
#include <vector>

using std::make_shared;
using std::ostream;
using std::thread;
using std::vector;

Network::CacheClientTesting::CacheClientTesting(const OStreamShared& stream)
    : ParentType{ stream }, mPort{ 8141 }, messageID{ 5 }, increase{ 160 }
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
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, CacheClientTesting)

void Network::CacheClientTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::CacheClientTesting::MainTest()
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

void Network::CacheClientTesting::ACETest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ACESendingClientTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ACEAsyncSendingClientTest);
}

void Network::CacheClientTesting::BoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostSendingClientTest);
}

void Network::CacheClientTesting::AsyncBoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostAsyncSendingClientTest);
}

void Network::CacheClientTesting::NullTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullSendingClientTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NullAsyncSendingClientTest);
}

void Network::CacheClientTesting::CreateMessage()
{
    MESSAGE_MANAGER_SINGLETON.Insert(messageID, MessageTypeCondition::CreateNullCondition(), NullMessage::Factory);
}

void Network::CacheClientTesting::DestroyMessage()
{
    MESSAGE_MANAGER_SINGLETON.Remove(messageID);
}

void Network::CacheClientTesting::ACESendingClientTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::ACE,
                                                 ConnectStrategy::TCP,
                                                 ClientStrategy::Cache,
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
    const auto loopCount = GetTestLoopCount();
    for (auto i = 0; i < loopCount; ++i)
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

        MessageInterfaceSharedPtr message{ make_shared<NullMessage>(messageID) };
        client->Send(client->GetSocketID(), message);

        client->ImmediatelySend(client->GetSocketID());

        client->Receive();

        client.reset();
    }

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), loopCount * messageID);

    firstTread.join();
}

void Network::CacheClientTesting::ACEAsyncSendingClientTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::ACE,
                                                 ConnectStrategy::TCP,
                                                 ClientStrategy::Cache,
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
    const auto loopCount = GetTestLoopCount();
    for (auto i = 0; i < loopCount; ++i)
    {
        clientContainer.push_back(make_shared<Client>(configurationStrategy, testSocketManager));
    }

    int connectNum{ 1 };

    for (auto& client : clientContainer)
    {
        constexpr int connectTime{ 10 };
        for (auto i = 0; i < connectTime; ++i)
        {
            client->AsyncConnect();

            if (connectNum == testSocketManager->GetAsyncConnectCount())
            {
                break;
            }

            ASSERT_UNEQUAL(i + 1, connectTime);
        }

        MessageInterfaceSharedPtr message{ make_shared<NullMessage>(messageID) };
        client->AsyncSend(client->GetSocketID(), message);

        ++connectNum;

        client->ImmediatelyAsyncSend(client->GetSocketID());

        client->AsyncReceive();

        client.reset();
    }

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), loopCount * messageID);

    firstTread.join();
}

void Network::CacheClientTesting::ACEServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoACEServerThread);
}

void Network::CacheClientTesting::DoACEServerThread()
{
    ConfigurationStrategy configurationStrategy{ GetACEServerConfigurationStrategy(increase) };
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(messageID) };

    ServerSharedPtr server{ make_shared<Server>(testSocketManager, configurationStrategy) };

    testSocketManager->SetServerWeakPtr(server);

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

void Network::CacheClientTesting::BoostSendingClientTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Boost,
                                                 ConnectStrategy::TCP,
                                                 ClientStrategy::Cache,
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
    const auto loopCount = GetTestLoopCount();
    for (auto i = 0; i < loopCount; ++i)
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

        MessageInterfaceSharedPtr message{ make_shared<NullMessage>(messageID) };
        client->Send(client->GetSocketID(), message);

        client->ImmediatelySend(client->GetSocketID());

        client->Receive();
    }

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), loopCount * messageID);

    secondTread.join();
    firstTread.join();
}

void Network::CacheClientTesting::BoostAsyncSendingClientTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Boost,
                                                 ConnectStrategy::TCP,
                                                 ClientStrategy::Cache,
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

    vector<ClientSharedPtr> clientContainer;
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(messageID) };
    const auto loopCount = GetTestLoopCount();
    for (auto i = 0; i < loopCount; ++i)
    {
        clientContainer.push_back(make_shared<Client>(configurationStrategy, testSocketManager));
    }

    int connectNum{ 1 };

    for (auto& client : clientContainer)
    {
        client->AsyncConnect();

        for (;;)
        {
            const auto volatile asyncConnectCount = testSocketManager->GetAsyncConnectCount();
            if (connectNum == asyncConnectCount)
            {
                break;
            }
        }

        MessageInterfaceSharedPtr message{ make_shared<NullMessage>(messageID) };
        client->AsyncSend(client->GetSocketID(), message);

        ++connectNum;

        client->ImmediatelyAsyncSend(client->GetSocketID());
    }

    for (auto& client : clientContainer)
    {
        client->AsyncReceive();
    }

    for (;;)
    {
        const auto volatile asyncReceiveCount = testSocketManager->GetAsyncReceiveCount();
        if (loopCount == asyncReceiveCount)
        {
            break;
        }
    }

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), loopCount * messageID);

    secondTread.join();
    firstTread.join();
}

void Network::CacheClientTesting::BoostServerThread()
{
    BASE_MAIN_MANAGER_SINGLETON.Run();
}

void Network::CacheClientTesting::BoostRunServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoBoostServerThread);
}

void Network::CacheClientTesting::DoBoostServerThread()
{
    ConfigurationStrategy configurationStrategy{ GetBoostServerConfigurationStrategy(increase) };

    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(messageID) };

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), 0);

    ServerSharedPtr server{ make_shared<Server>(testSocketManager, configurationStrategy) };

    const auto loopCount = GetTestLoopCount();
    for (;;)
    {
        testSocketManager->SetServerWeakPtr(server);

        ASSERT_TRUE(server->RunServer());

        if (0 < testSocketManager->GetCallBackTime())
        {
            BASE_MAIN_MANAGER_SINGLETON.StopContext();
            break;
        }
    }

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), loopCount * messageID);
    BASE_MAIN_MANAGER_SINGLETON.StopContext();

    for (;;)
    {
        if (BASE_MAIN_MANAGER_SINGLETON.IsContextStop())
        {
            break;
        }
    }
}

void Network::CacheClientTesting::NullSendingClientTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null,
                                                 ConnectStrategy::TCP,
                                                 ClientStrategy::Cache,
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
    const auto loopCount = GetTestLoopCount();
    for (auto i = 0; i < loopCount; ++i)
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

        MessageInterfaceSharedPtr message{ make_shared<NullMessage>(messageID) };
        client->Send(client->GetSocketID(), message);

        client->ImmediatelySend(client->GetSocketID());
    }

    for (auto& client : clientContainer)
    {
        client->Receive();
    }

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), 0);

    firstTread.join();
}

void Network::CacheClientTesting::NullAsyncSendingClientTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null,
                                                 ConnectStrategy::TCP,
                                                 ClientStrategy::Cache,
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
    const auto loopCount = GetTestLoopCount();
    for (auto i = 0; i < loopCount; ++i)
    {
        clientContainer.push_back(make_shared<Client>(configurationStrategy, testSocketManager));
    }

    int connectNum{ 1 };

    for (auto& client : clientContainer)
    {
        client->AsyncConnect();

        for (;;)
        {
            const auto volatile asyncConnectCount = testSocketManager->GetAsyncConnectCount();
            if (connectNum == asyncConnectCount)
            {
                break;
            }
        }

        MessageInterfaceSharedPtr message{ make_shared<NullMessage>(messageID) };
        client->AsyncSend(client->GetSocketID(), message);

        ++connectNum;

        client->ImmediatelyAsyncSend(client->GetSocketID());

        client->AsyncReceive();
    }

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), 0);

    firstTread.join();
}

void Network::CacheClientTesting::NullServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoNullServerThread);
}

void Network::CacheClientTesting::DoNullServerThread() noexcept
{
}
