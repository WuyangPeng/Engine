///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/17 15:38)

#include "ReactiveServerTesting.h"
#include "SingletonTestingDetail.h"
#include "Detail/TestSocketEvent.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/ConfigurationSubStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/Client.h"
#include "Network/Interface/Server.h"
#include "Network/NetworkMessage/MessageEventManager.h"
#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/NullMessage.h"

#include <vector>

Network::ReactiveServerTesting::ReactiveServerTesting(const OStreamShared& stream)
    : ParentType{ stream }, port{ 5358 + System::GetEngineeringOffsetValue() }, serverSendMessageId{ 9 }, clientSendMessageId{ 7 }, increase{ 1 }, bufferSize{ 1048576 }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ReactiveServerTesting)

void Network::ReactiveServerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::ReactiveServerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessage);
    ASSERT_NOT_THROW_EXCEPTION_0(ReactiveServerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessage);
}

void Network::ReactiveServerTesting::CreateMessage()
{
    MESSAGE_MANAGER_SINGLETON.Insert(clientSendMessageId, MessageTypeCondition::CreateNullCondition(), NullMessage::Factory);
}

void Network::ReactiveServerTesting::ReactiveServerTest()
{
    auto subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, bufferSize);
    subStrategy.Insert(WrappersSubStrategy::SendBufferSize, bufferSize);

    const ConfigurationStrategy serverConfigurationStrategy{ WrappersStrategy::Ace,
                                                             ConnectStrategy::Tcp,
                                                             ServerStrategy::Reactive,
                                                             MessageStrategy::Default,
                                                             ParserStrategy::LittleEndian,
                                                             OpenSSLStrategy::Default,
                                                             EncryptedCompressionStrategy::Default,
                                                             subStrategy,
                                                             ConfigurationParameter::Create(),
                                                             SocketSendMessage::Default,
                                                             "127.0.0.1",
                                                             port + increase };

    const auto testMessageEvent = std::make_shared<TestMessageEvent>(CoreTools::DisableNotThrow::Disable);
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    messageEventManager->Insert(clientSendMessageId, testMessageEvent);
    messageEventManager->SetCallbackEvent(testSocketEvent);

    Server server{ serverConfigurationStrategy, messageEventManager };

    const ConfigurationStrategy clientConfigurationStrategy{ WrappersStrategy::Ace,
                                                             ConnectStrategy::Tcp,
                                                             ClientStrategy::Cache,
                                                             MessageStrategy::Iovec,
                                                             ParserStrategy::LittleEndian,
                                                             OpenSSLStrategy::Default,
                                                             EncryptedCompressionStrategy::Default,
                                                             subStrategy,
                                                             ConfigurationParameter::Create(),
                                                             SocketSendMessage::Default, "127.0.0.1",
                                                             port + increase };

    std::vector<ClientSharedPtr> clientContainer{};
    boost::thread_group threadGroup{};

    const auto loopCount = GetTestLoopCount();
    for (auto i = 0; i < loopCount; ++i)
    {
        clientContainer.emplace_back(make_shared<Client>(clientConfigurationStrategy, messageEventManager));
    }

    for (auto& client : clientContainer)
    {
        threadGroup.create_thread(boost::bind(&ClassType::ClientThread, this, boost::ref(*client)));
    }

    const auto callBackTime = loopCount * clientSendMessageId;
    const auto runCount = loopCount * 10;
    for (int i = 0; i < runCount; ++i)
    {
        ASSERT_TRUE(server.RunServer());

        if (testMessageEvent->GetCallBackTime() == callBackTime)
            break;
    }

    ASSERT_EQUAL(testMessageEvent->GetCallBackTime(), callBackTime);

    threadGroup.join_all();
}

void Network::ReactiveServerTesting::ClientThread(Client& client)
{
    constexpr auto connectTime = 100;
    auto socketId = 0LL;
    for (auto i = 0; i < connectTime; ++i)
    {
        socketId = client.Connect();
        if (socketId != 0)
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, connectTime);
    }

    const auto message = std::make_shared<NullMessage>(MessageHeadStrategy::Default, clientSendMessageId);
    client.Send(socketId, message);

    client.ImmediatelySend(socketId);
}

void Network::ReactiveServerTesting::DestroyMessage()
{
    MESSAGE_MANAGER_SINGLETON.Remove(clientSendMessageId);
}