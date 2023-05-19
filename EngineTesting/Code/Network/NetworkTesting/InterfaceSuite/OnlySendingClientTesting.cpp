///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/15 13:33)

#include "OnlySendingClientTesting.h"
#include "SingletonTestingDetail.h"
#include "Detail/TestSocketEvent.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/ConfigurationSubStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/Client.h"
#include "Network/Interface/Server.h"
#include "Network/NetworkMessage/MessageEventManager.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/NullMessage.h"

#include <thread>
#include <vector>

Network::OnlySendingClientTesting::OnlySendingClientTesting(const OStreamShared& stream)
    : ParentType{ stream }, messageId{ 5 }, increase{ 13 }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, OnlySendingClientTesting)

void Network::OnlySendingClientTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessage);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessage);
}

void Network::OnlySendingClientTesting::MainTest()
{
    increase += 1000;
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);

    increase += 1000;
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);

    increase += 1000;
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::AsyncBoostTest);

    increase += 1000;
    ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
}

void Network::OnlySendingClientTesting::CreateMessage()
{
    MESSAGE_MANAGER_SINGLETON.Insert(messageId, MessageTypeCondition::CreateNullCondition(), NullMessage::Factory);
}

void Network::OnlySendingClientTesting::DestroyMessage()
{
    MESSAGE_MANAGER_SINGLETON.Remove(messageId);
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
    auto configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, GetBufferSize());
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, GetBufferSize());

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
                                                 GetShiftingPort(increase) };

    std::thread thread{ &ClassType::ACEServerThread, this };

    std::vector<ClientSharedPtr> clientContainer{};
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        clientContainer.emplace_back(std::make_shared<Client>(configurationStrategy, messageEventManager));
    }

    for (auto& client : clientContainer)
    {
        constexpr auto connectTime = 10;

        auto socketId = 0LL;
        for (auto i = 0; i < connectTime; ++i)
        {
            socketId = client->Connect();
            if (socketId != 0)
            {
                break;
            }

            ASSERT_UNEQUAL(i + 1, connectTime);
        }

        client->Send(socketId, std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId));

        client.reset();
    }

    thread.join();
}

void Network::OnlySendingClientTesting::ACEAsyncOnlySendingClientTest()
{
    auto configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, GetBufferSize());
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, GetBufferSize());

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Ace,
                                                 ConnectStrategy::Tcp,
                                                 ClientStrategy::OnlySending,
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
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    messageEventManager->SetCallbackEvent(testSocketEvent);

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        clientContainer.emplace_back(make_shared<Client>(configurationStrategy, messageEventManager));
    }

    auto connectNum = 1;

    for (auto& client : clientContainer)
    {
        constexpr auto connectTime = 10;
        constexpr auto socketId = 0LL;

        for (auto i = 0; i < connectTime; ++i)
        {
            client->AsyncConnect();

            if (const auto volatile asyncConnectCount = testSocketEvent->GetAsyncConnectCount();
                connectNum == asyncConnectCount)
            {
                break;
            }

            ASSERT_UNEQUAL(i + 1, connectTime);
        }

        auto message = std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId);

        client->AsyncSend(socketId, message);

        ++connectNum;

        client.reset();
    }

    thread.join();
}

void Network::OnlySendingClientTesting::ACEServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoACEServerThread);
}

void Network::OnlySendingClientTesting::DoACEServerThread()
{
    const auto configurationStrategy = GetACEServerConfigurationStrategy(increase);
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    const auto testMessageEvent = std::make_shared<TestMessageEvent>(CoreTools::DisableNotThrow::Disable);

    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    messageEventManager->SetCallbackEvent(testSocketEvent);
    messageEventManager->Insert(messageId, testMessageEvent);

    Server server{ configurationStrategy, messageEventManager };

    const auto loopCount = GetTestLoopCount();
    for (;;)
    {
        ASSERT_TRUE(server.RunServer());

        if (const auto volatile asyncAcceptorCount = testSocketEvent->GetAsyncAcceptorCount();
            asyncAcceptorCount == loopCount)
        {
            break;
        }
    }

    ASSERT_EQUAL(testMessageEvent->GetCallBackTime(), loopCount * messageId);
}

void Network::OnlySendingClientTesting::BoostOnlySendingClientTest()
{
    auto configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, GetBufferSize());
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, GetBufferSize());

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Boost,
                                                 ConnectStrategy::Tcp,
                                                 ClientStrategy::OnlySending,
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

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        clientContainer.emplace_back(make_shared<Client>(configurationStrategy, messageEventManager));
    }

    std::thread thread0{ &ClassType::BoostServerThread, this };
    std::thread thread1{ &ClassType::BoostRunServerThread, this };

    for (const auto& client : clientContainer)
    {
        constexpr int connectTime{ 10 };
        auto socketId = 0LL;
        for (auto i = 0; i < connectTime; ++i)
        {
            socketId = client->Connect();
            if (socketId != 0)
            {
                break;
            }

            ASSERT_UNEQUAL(i + 1, connectTime);
        }

        const auto message = std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId);
        client->Send(socketId, message);
    }

    thread1.join();
    thread0.join();
}

void Network::OnlySendingClientTesting::BoostAsyncOnlySendingClientTest()
{
    auto configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, GetBufferSize());
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, GetBufferSize());

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Boost,
                                                 ConnectStrategy::Tcp,
                                                 ClientStrategy::OnlySending,
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
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    messageEventManager->SetCallbackEvent(testSocketEvent);

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        clientContainer.emplace_back(make_shared<Client>(configurationStrategy, messageEventManager));
    }

    auto connectNum = 1;

    for (const auto& client : clientContainer)
    {
        client->AsyncConnect();
        constexpr auto socketId = 0LL;
        for (;;)
        {
            if (const auto volatile asyncConnectCount = testSocketEvent->GetAsyncConnectCount();
                connectNum == asyncConnectCount)
            {
                break;
            }
        }

        client->AsyncSend(socketId, std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId));

        ++connectNum;
    }

    thread1.join();
    thread0.join();
}

void Network::OnlySendingClientTesting::BoostServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoBoostServerThread);
}

void Network::OnlySendingClientTesting::DoBoostServerThread()
{
    const auto configurationStrategy = GetBoostServerConfigurationStrategy(increase);

    const auto testMessageEvent = std::make_shared<TestMessageEvent>(CoreTools::DisableNotThrow::Disable);
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();

    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    messageEventManager->Insert(messageId, testMessageEvent);
    messageEventManager->SetCallbackEvent(testSocketEvent);

    ASSERT_EQUAL(testMessageEvent->GetCallBackTime(), 0);

    const auto loopCount = GetTestLoopCount();
    const auto result = loopCount * messageId;

    Server server{ configurationStrategy, messageEventManager };

    for (;;)
    {
        ASSERT_TRUE(server.RunServer());

        if (result <= testMessageEvent->GetCallBackTime())
        {
            break;
        }
    }

    ASSERT_EQUAL(testSocketEvent->GetAsyncAcceptorCount(), loopCount);

    ASSERT_EQUAL(testMessageEvent->GetCallBackTime(), result);

    BASE_MAIN_MANAGER_SINGLETON.StopContext();
}

void Network::OnlySendingClientTesting::BoostRunServerThread()
{
    BASE_MAIN_MANAGER_SINGLETON.Run();
}

void Network::OnlySendingClientTesting::NullOnlySendingClientTest()
{
    auto configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, GetBufferSize());
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, GetBufferSize());

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null,
                                                 ConnectStrategy::Tcp,
                                                 ClientStrategy::OnlySending,
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
    const auto testMessageEvent = std::make_shared<TestMessageEvent>(CoreTools::DisableNotThrow::Disable);
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();

    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    messageEventManager->Insert(messageId, testMessageEvent);
    messageEventManager->SetCallbackEvent(testSocketEvent);

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        clientContainer.emplace_back(make_shared<Client>(configurationStrategy, messageEventManager));
    }

    std::thread thread{ &ClassType::NullServerThread, this };

    for (const auto& client : clientContainer)
    {
        constexpr auto connectTime = 10;
        auto socketId = 0LL;

        for (auto i = 0; i < connectTime; ++i)
        {
            socketId = client->Connect();
            if (socketId != 0)
            {
                break;
            }

            ASSERT_UNEQUAL(i + 1, connectTime);
        }

        client->Send(socketId, std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId));
    }

    thread.join();
}

void Network::OnlySendingClientTesting::NullServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoNullServerThread);
}

void Network::OnlySendingClientTesting::NullAsyncOnlySendingClientTest()
{
    auto configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, GetBufferSize());
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, GetBufferSize());

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null,
                                                 ConnectStrategy::Tcp,
                                                 ClientStrategy::OnlySending,
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
    const auto testMessageEvent = std::make_shared<TestMessageEvent>(CoreTools::DisableNotThrow::Disable);
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();

    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    messageEventManager->Insert(messageId, testMessageEvent);
    messageEventManager->SetCallbackEvent(testSocketEvent);

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        clientContainer.emplace_back(make_shared<Client>(configurationStrategy, messageEventManager));
    }

    auto connectNum = 1;

    for (const auto& client : clientContainer)
    {
        client->AsyncConnect();
        constexpr auto socketId = 0LL;
        for (;;)
        {
            if (const auto volatile asyncConnectCount = testSocketEvent->GetAsyncConnectCount();
                connectNum == asyncConnectCount)
            {
                break;
            }
        }

        client->AsyncSend(socketId, std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId));

        ++connectNum;
    }

    thread.join();
}

void Network::OnlySendingClientTesting::DoNullServerThread() noexcept
{
}
