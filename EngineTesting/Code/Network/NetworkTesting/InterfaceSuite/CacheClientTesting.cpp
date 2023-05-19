///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/16 08:57)

#include "CacheClientTesting.h"
#include "SingletonTestingDetail.h"
#include "Detail/TestSocketEvent.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/Client.h"
#include "Network/Interface/Server.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/NullMessage.h"

#include <thread>
#include <vector>

Network::CacheClientTesting::CacheClientTesting(const OStreamShared& stream)
    : ParentType{ stream }, messageId{ 5 }, increase{ 163 }, boostStop{}
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, CacheClientTesting)

void Network::CacheClientTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessage);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessage);
}

void Network::CacheClientTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);

    increase += 1000;
    boostStop = 0;
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);

    increase += 1000;
    boostStop = 0;
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::AsyncBoostTest);

    increase += 1000;
    ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
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
    MESSAGE_MANAGER_SINGLETON.Insert(messageId, MessageTypeCondition::CreateNullCondition(), NullMessage::Factory);
}

void Network::CacheClientTesting::DestroyMessage()
{
    MESSAGE_MANAGER_SINGLETON.Remove(messageId);
}

void Network::CacheClientTesting::ACESendingClientTest()
{
    auto configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, GetBufferSize());
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, GetBufferSize());

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Ace,
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
                                                 GetShiftingPort(increase) };

    std::thread thread{ &ClassType::ACEServerThread, this };

    std::vector<ClientSharedPtr> clientContainer{};
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    const auto testMessageEvent = std::make_shared<TestMessageEvent>(CoreTools::DisableNotThrow::Disable);
    messageEventManager->Insert(messageId, testMessageEvent);

    const auto loopCount = GetTestLoopCount();
    for (auto i = 0; i < loopCount; ++i)
    {
        clientContainer.emplace_back(make_shared<Client>(configurationStrategy, messageEventManager));
    }

    for (auto& client : clientContainer)
    {
        constexpr auto connectTime = 10;

        for (auto i = 0; i < connectTime; ++i)
        {
            if (const auto socketId = client->Connect();
                socketId != 0)
            {
                break;
            }

            ASSERT_UNEQUAL(i + 1, connectTime);
        }

        const auto message = std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId);
        client->Send(client->GetSocketId(), message);

        client->ImmediatelySend(client->GetSocketId());

        client->Receive();

        client.reset();
    }

    ASSERT_EQUAL(testMessageEvent->GetCallBackTime(), loopCount * messageId);

    thread.join();
}

void Network::CacheClientTesting::ACEAsyncSendingClientTest()
{
    auto configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, GetBufferSize());
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, GetBufferSize());

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Ace,
                                                 ConnectStrategy::Tcp,
                                                 ClientStrategy::Cache,
                                                 MessageStrategy::Default,
                                                 ParserStrategy::LittleEndian,
                                                 OpenSSLStrategy::Default,
                                                 EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy,
                                                 ConfigurationParameter::Create(),
                                                 SocketSendMessage::Default,
                                                 "127.0.0.1",
                                                 GetShiftingPort(increase) };

    std::thread thread{ &ClassType::ACEServerThread, this };

    std::vector<ClientSharedPtr> clientContainer{};
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    const auto testMessageEvent = std::make_shared<TestMessageEvent>(CoreTools::DisableNotThrow::Disable);
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    messageEventManager->Insert(messageId, testMessageEvent);
    messageEventManager->SetCallbackEvent(testSocketEvent);

    const auto loopCount = GetTestLoopCount();
    for (auto i = 0; i < loopCount; ++i)
    {
        clientContainer.emplace_back(make_shared<Client>(configurationStrategy, messageEventManager));
    }

    auto connectNum = 1;

    for (auto& client : clientContainer)
    {
        constexpr auto connectTime = 10;
        for (auto i = 0; i < connectTime; ++i)
        {
            client->AsyncConnect();

            if (connectNum == testSocketEvent->GetAsyncConnectCount())
            {
                break;
            }

            ASSERT_UNEQUAL(i + 1, connectTime);
        }

        const auto message = std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId);
        client->AsyncSend(client->GetSocketId(), message);

        ++connectNum;

        client->ImmediatelyAsyncSend(client->GetSocketId());

        client->AsyncReceive();

        client.reset();
    }

    ASSERT_EQUAL(testMessageEvent->GetCallBackTime(), loopCount * messageId);

    thread.join();
}

void Network::CacheClientTesting::ACEServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoACEServerThread);
}

void Network::CacheClientTesting::DoACEServerThread()
{
    const auto configurationStrategy = GetACEServerConfigurationStrategy(increase);
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    const auto testMessageEvent = std::make_shared<TestMessageEvent>(CoreTools::DisableNotThrow::Disable);
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    messageEventManager->Insert(messageId, testMessageEvent);
    messageEventManager->SetCallbackEvent(testSocketEvent);

    const auto server = std::make_shared<Server>(configurationStrategy, messageEventManager);
    testMessageEvent->SetServerWeakPtr(server);

    const auto loopCount = GetTestLoopCount();
    for (;;)
    {
        ASSERT_TRUE(server->RunServer());

        if (const auto volatile asyncAcceptorCount = testSocketEvent->GetAsyncAcceptorCount();
            asyncAcceptorCount == loopCount)
        {
            break;
        }
    }

    ASSERT_EQUAL(testMessageEvent->GetCallBackTime(), loopCount * messageId);
}

void Network::CacheClientTesting::BoostSendingClientTest()
{
    auto configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, GetBufferSize());
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, GetBufferSize());

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Boost,
                                                 ConnectStrategy::Tcp,
                                                 ClientStrategy::Cache,
                                                 MessageStrategy::Default,
                                                 ParserStrategy::LittleEndian,
                                                 OpenSSLStrategy::Default,
                                                 EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy,
                                                 ConfigurationParameter::Create(),
                                                 SocketSendMessage::Default,
                                                 "127.0.0.1",
                                                 GetShiftingPort(increase) };

    std::vector<ClientSharedPtr> clientContainer{};
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    const auto testMessageEvent = std::make_shared<TestMessageEvent>(CoreTools::DisableNotThrow::Disable);
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    messageEventManager->Insert(messageId, testMessageEvent);
    messageEventManager->SetCallbackEvent(testSocketEvent);

    const auto loopCount = GetTestLoopCount();
    for (auto i = 0; i < loopCount; ++i)
    {
        clientContainer.emplace_back(make_shared<Client>(configurationStrategy, messageEventManager));
    }

    std::thread thread0{ &ClassType::BoostServerThread, this };
    std::thread thread1{ &ClassType::BoostRunServerThread, this };

    for (const auto& client : clientContainer)
    {
        constexpr auto connectTime = 10;

        for (auto i = 0; i < connectTime; ++i)
        {
            if (const auto socketId = client->Connect();
                socketId != 0)
            {
                break;
            }

            ASSERT_UNEQUAL(i + 1, connectTime);
        }

        const auto message = std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId);
        client->Send(client->GetSocketId(), message);

        client->ImmediatelySend(client->GetSocketId());

        client->Receive();
    }

    ++boostStop;

    if (2 <= boostStop)
    {
        BASE_MAIN_MANAGER_SINGLETON.StopContext();
    }

    ASSERT_EQUAL(testMessageEvent->GetCallBackTime(), loopCount * messageId);

    thread1.join();
    thread0.join();
}

void Network::CacheClientTesting::BoostAsyncSendingClientTest()
{
    auto configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, GetBufferSize());
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, GetBufferSize());

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Boost,
                                                 ConnectStrategy::Tcp,
                                                 ClientStrategy::Cache,
                                                 MessageStrategy::Default,
                                                 ParserStrategy::LittleEndian,
                                                 OpenSSLStrategy::Default,
                                                 EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy,
                                                 ConfigurationParameter::Create(),
                                                 SocketSendMessage::Default,
                                                 "127.0.0.1",
                                                 GetShiftingPort(increase) };

    std::thread thread0{ &ClassType::BoostServerThread, this };
    std::thread thread1{ &ClassType::BoostRunServerThread, this };

    std::vector<ClientSharedPtr> clientContainer{};
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    const auto testMessageEvent = std::make_shared<TestMessageEvent>(CoreTools::DisableNotThrow::Disable);
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    messageEventManager->Insert(messageId, testMessageEvent);
    messageEventManager->SetCallbackEvent(testSocketEvent);

    const auto loopCount = GetTestLoopCount();
    for (auto i = 0; i < loopCount; ++i)
    {
        clientContainer.emplace_back(make_shared<Client>(configurationStrategy, messageEventManager));
    }

    auto connectNum = 1;

    for (const auto& client : clientContainer)
    {
        client->AsyncConnect();

        for (;;)
        {
            if (const auto volatile asyncConnectCount = testSocketEvent->GetAsyncConnectCount();
                connectNum == asyncConnectCount)
            {
                break;
            }
        }

        const auto message = std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId);
        client->AsyncSend(client->GetSocketId(), message);

        ++connectNum;

        client->ImmediatelyAsyncSend(client->GetSocketId());
    }

    for (const auto& client : clientContainer)
    {
        client->AsyncReceive();
    }

    const auto result = loopCount * messageId;
    for (;;)
    {
        if (const auto volatile asyncReceiveCount = testSocketEvent->GetAsyncReceiveCount();
            loopCount == asyncReceiveCount)
        {
            break;
        }
    }

    ++boostStop;

    if (2 <= boostStop)
    {
        BASE_MAIN_MANAGER_SINGLETON.StopContext();
    }

    ASSERT_EQUAL(testMessageEvent->GetCallBackTime(), loopCount * messageId);

    thread1.join();
    thread0.join();
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
    const auto configurationStrategy = GetBoostServerConfigurationStrategy(increase);

    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    const auto testMessageEvent = std::make_shared<TestMessageEvent>(CoreTools::DisableNotThrow::Disable);
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    messageEventManager->Insert(messageId, testMessageEvent);
    messageEventManager->SetCallbackEvent(testSocketEvent);

    ASSERT_EQUAL(testMessageEvent->GetCallBackTime(), 0);

    const auto server = make_shared<Server>(configurationStrategy, messageEventManager);

    testMessageEvent->SetServerWeakPtr(server);

    const auto loopCount = GetTestLoopCount();
    const auto result = loopCount * messageId;

    for (;;)
    {
        ASSERT_TRUE(server->RunServer());

        if (result <= testMessageEvent->GetCallBackTime())
        {
            break;
        }
    }

    ASSERT_EQUAL(testSocketEvent->GetAsyncAcceptorCount(), loopCount);

    ++boostStop;

    if (2 <= boostStop)
    {
        BASE_MAIN_MANAGER_SINGLETON.StopContext();
    }

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
    auto configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, GetBufferSize());
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, GetBufferSize());

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null,
                                                 ConnectStrategy::Tcp,
                                                 ClientStrategy::Cache,
                                                 MessageStrategy::Default,
                                                 ParserStrategy::LittleEndian,
                                                 OpenSSLStrategy::Default,
                                                 EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy,
                                                 ConfigurationParameter::Create(),
                                                 SocketSendMessage::Default,
                                                 "127.0.0.1",
                                                 GetShiftingPort(increase) };

    std::vector<ClientSharedPtr> clientContainer{};
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    const auto testMessageEvent = std::make_shared<TestMessageEvent>(CoreTools::DisableNotThrow::Disable);
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    messageEventManager->Insert(messageId, testMessageEvent);
    messageEventManager->SetCallbackEvent(testSocketEvent);

    const auto loopCount = GetTestLoopCount();
    for (auto i = 0; i < loopCount; ++i)
    {
        clientContainer.emplace_back(make_shared<Client>(configurationStrategy, messageEventManager));
    }

    std::thread thread{ &ClassType::NullServerThread, this };

    for (const auto& client : clientContainer)
    {
        constexpr auto connectTime = 10;

        for (auto i = 0; i < connectTime; ++i)
        {
            if (const auto socketId = client->Connect();
                socketId != 0)
            {
                break;
            }

            ASSERT_UNEQUAL(i + 1, connectTime);
        }

        const auto message = std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId);
        client->Send(client->GetSocketId(), message);

        client->ImmediatelySend(client->GetSocketId());
    }

    for (const auto& client : clientContainer)
    {
        client->Receive();
    }

    ASSERT_EQUAL(testMessageEvent->GetCallBackTime(), 0);

    thread.join();
}

void Network::CacheClientTesting::NullAsyncSendingClientTest()
{
    auto configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, GetBufferSize());
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, GetBufferSize());

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null,
                                                 ConnectStrategy::Tcp,
                                                 ClientStrategy::Cache,
                                                 MessageStrategy::Default,
                                                 ParserStrategy::LittleEndian,
                                                 OpenSSLStrategy::Default,
                                                 EncryptedCompressionStrategy::Default,
                                                 configurationSubStrategy,
                                                 ConfigurationParameter::Create(),
                                                 SocketSendMessage::Default,
                                                 "127.0.0.1",
                                                 GetShiftingPort(increase) };

    std::thread thread{ &ClassType::NullServerThread, this };

    std::vector<ClientSharedPtr> clientContainer{};
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    const auto testMessageEvent = std::make_shared<TestMessageEvent>(CoreTools::DisableNotThrow::Disable);
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    messageEventManager->Insert(messageId, testMessageEvent);
    messageEventManager->SetCallbackEvent(testSocketEvent);

    const auto loopCount = GetTestLoopCount();
    for (auto i = 0; i < loopCount; ++i)
    {
        clientContainer.emplace_back(make_shared<Client>(configurationStrategy, messageEventManager));
    }

    auto connectNum = 1;

    for (const auto& client : clientContainer)
    {
        client->AsyncConnect();

        for (;;)
        {
            const auto volatile asyncConnectCount = testSocketEvent->GetAsyncConnectCount();
            if (connectNum == asyncConnectCount)
            {
                break;
            }
        }

        const auto message = std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId);
        client->AsyncSend(client->GetSocketId(), message);

        ++connectNum;

        client->ImmediatelyAsyncSend(client->GetSocketId());

        client->AsyncReceive();
    }

    ASSERT_EQUAL(testMessageEvent->GetCallBackTime(), 0);

    thread.join();
}

void Network::CacheClientTesting::NullServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoNullServerThread);
}

void Network::CacheClientTesting::DoNullServerThread() noexcept
{
}
