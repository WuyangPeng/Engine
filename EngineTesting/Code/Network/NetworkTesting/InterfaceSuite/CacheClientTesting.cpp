// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 13:14)

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

Network::CacheClientTesting ::CacheClientTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr }, m_Port{ 8141 }, m_MessageID{ 5 }, m_Increase{ 160 }
{
#ifdef _DEBUG
    m_Port += 4;
#endif  // _DEBUG

#ifdef BUILDING_NETWORK_STATIC
    m_Port += 2;
#endif  // BUILDING_NETWORK_STATIC

#ifdef _WIN64
    m_Port += 1;
#endif  // _WIN64

    NETWORK_SELF_CLASS_IS_VALID_1;
}
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, CacheClientTesting)
void Network::CacheClientTesting ::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::CacheClientTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
    m_Increase += 10;
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
    m_Increase += 10;
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::AsyncBoostTest);
    m_Increase += 10;
    ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessage);
}

void Network::CacheClientTesting ::ACETest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ACESendingClientTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ACEAsyncSendingClientTest);
}

void Network::CacheClientTesting ::BoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostSendingClientTest);
}

void Network::CacheClientTesting ::AsyncBoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostAsyncSendingClientTest);
}

void Network::CacheClientTesting ::NullTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullSendingClientTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NullAsyncSendingClientTest);
}

void Network::CacheClientTesting ::CreateMessage()
{
    MESSAGE_MANAGER_SINGLETON.Insert(m_MessageID, MessageTypeCondition::CreateNullCondition(), NullMessage::Factory);
}

void Network::CacheClientTesting ::DestroyMessage()
{
    MESSAGE_MANAGER_SINGLETON.Remove(m_MessageID);
}

void Network::CacheClientTesting ::ACESendingClientTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::ACE, ConnectStrategy::TCP, ClientStrategy::Cache,
                                                 MessageStrategy::Iovec, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default,
                                                 "127.0.0.1", m_Port + m_Increase };

    thread firstTread{ &ClassType::ACEServerThread, this };

    vector<ClientSharedPtr> clientContainer;
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(m_MessageID) };
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

        MessageInterfaceSharedPtr message{ make_shared<NullMessage>(m_MessageID) };
        client->Send(client->GetSocketID(), message);

        client->ImmediatelySend(client->GetSocketID());

        client->Receive();

        client.reset();
    }

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), loopCount * m_MessageID);

    firstTread.join();
}

void Network::CacheClientTesting ::ACEAsyncSendingClientTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::ACE, ConnectStrategy::TCP, ClientStrategy::Cache,
                                                 MessageStrategy::Default, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default,
                                                 "127.0.0.1", m_Port + m_Increase };

    thread firstTread{ &ClassType::ACEServerThread, this };

    vector<ClientSharedPtr> clientContainer;
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(m_MessageID) };
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

        MessageInterfaceSharedPtr message{ make_shared<NullMessage>(m_MessageID) };
        client->AsyncSend(client->GetSocketID(), message);

        ++connectNum;

        client->ImmediatelyAsyncSend(client->GetSocketID());

        client->AsyncReceive();

        client.reset();
    }

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), loopCount * m_MessageID);

    firstTread.join();
}

void Network::CacheClientTesting ::ACEServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoACEServerThread);
}

void Network::CacheClientTesting ::DoACEServerThread()
{
    ConfigurationStrategy configurationStrategy{ GetACEServerConfigurationStrategy(m_Increase) };
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(m_MessageID) };

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

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), loopCount * m_MessageID);
}

void Network::CacheClientTesting ::BoostSendingClientTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Boost, ConnectStrategy::TCP, ClientStrategy::Cache,
                                                 MessageStrategy::Default, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default,
                                                 "127.0.0.1", m_Port + m_Increase };

    vector<ClientSharedPtr> clientContainer;
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(m_MessageID) };
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

        MessageInterfaceSharedPtr message{ make_shared<NullMessage>(m_MessageID) };
        client->Send(client->GetSocketID(), message);

        client->ImmediatelySend(client->GetSocketID());

        client->Receive();
    }

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), loopCount * m_MessageID);

    secondTread.join();
    firstTread.join();
}

void Network::CacheClientTesting ::BoostAsyncSendingClientTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Boost, ConnectStrategy::TCP, ClientStrategy::Cache,
                                                 MessageStrategy::Default, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default,
                                                 "127.0.0.1", m_Port + m_Increase };

    thread firstTread{ &ClassType::BoostServerThread, this };
    thread secondTread{ &ClassType::BoostRunServerThread, this };

    vector<ClientSharedPtr> clientContainer;
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(m_MessageID) };
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

        MessageInterfaceSharedPtr message{ make_shared<NullMessage>(m_MessageID) };
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

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), loopCount * m_MessageID);

    secondTread.join();
    firstTread.join();
}

void Network::CacheClientTesting ::BoostServerThread()
{
    BASE_MAIN_MANAGER_SINGLETON.Run();
}

void Network::CacheClientTesting ::BoostRunServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoBoostServerThread);
}

void Network::CacheClientTesting ::DoBoostServerThread()
{
    ConfigurationStrategy configurationStrategy{ GetBoostServerConfigurationStrategy(m_Increase) };

    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(m_MessageID) };

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

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), loopCount * m_MessageID);
    BASE_MAIN_MANAGER_SINGLETON.StopContext();

    for (;;)
    {
        if (BASE_MAIN_MANAGER_SINGLETON.IsContextStop())
        {
            break;
        }
    }
}

void Network::CacheClientTesting ::NullSendingClientTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null, ConnectStrategy::TCP, ClientStrategy::Cache,
                                                 MessageStrategy::Default, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default,
                                                 "127.0.0.1", m_Port + m_Increase };

    vector<ClientSharedPtr> clientContainer;
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(m_MessageID) };
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

        MessageInterfaceSharedPtr message{ make_shared<NullMessage>(m_MessageID) };
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

void Network::CacheClientTesting ::NullAsyncSendingClientTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null, ConnectStrategy::TCP, ClientStrategy::Cache,
                                                 MessageStrategy::Default, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default,
                                                 "127.0.0.1", m_Port + m_Increase };

    thread firstTread{ &ClassType::NullServerThread, this };

    vector<ClientSharedPtr> clientContainer;
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(m_MessageID) };
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

        MessageInterfaceSharedPtr message{ make_shared<NullMessage>(m_MessageID) };
        client->AsyncSend(client->GetSocketID(), message);

        ++connectNum;

        client->ImmediatelyAsyncSend(client->GetSocketID());

        client->AsyncReceive();
    }

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), 0);

    firstTread.join();
}

void Network::CacheClientTesting ::NullServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoNullServerThread);
}

void Network::CacheClientTesting ::DoNullServerThread() noexcept
{
}
