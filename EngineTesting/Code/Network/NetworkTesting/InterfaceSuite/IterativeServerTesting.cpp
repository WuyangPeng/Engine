///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/17 14:51)

#include "IterativeServerTesting.h"
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

Network::IterativeServerTesting::IterativeServerTesting(const OStreamShared& stream)
    : ParentType{ stream }, port{ 5926 + System::GetEngineeringOffsetValue() }, messageId{ 5 }, increase{ 0 }, bufferSize{ 1048576 }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, IterativeServerTesting)

void Network::IterativeServerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessage);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessage);
}

void Network::IterativeServerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IterativeServerTest);
}

void Network::IterativeServerTesting::CreateMessage()
{
    MESSAGE_MANAGER_SINGLETON.Insert(messageId, MessageTypeCondition::CreateNullCondition(), NullMessage::Factory);
}

void Network::IterativeServerTesting::DestroyMessage()
{
    MESSAGE_MANAGER_SINGLETON.Remove(messageId);
}

void Network::IterativeServerTesting::IterativeServerTest()
{
    auto configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, bufferSize);
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, bufferSize);

    const ConfigurationStrategy serverConfigurationStrategy{ WrappersStrategy::Ace,
                                                             ConnectStrategy::Tcp,
                                                             ServerStrategy::Iterative,
                                                             MessageStrategy::Default,
                                                             ParserStrategy::LittleEndian,
                                                             OpenSSLStrategy::Default,
                                                             EncryptedCompressionStrategy::Default,
                                                             configurationSubStrategy,
                                                             ConfigurationParameter::Create(),
                                                             SocketSendMessage::Default,
                                                             "127.0.0.1",
                                                             port + increase };

    const auto testMessageEvent = std::make_shared<TestMessageEvent>(CoreTools::DisableNotThrow::Disable);
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    messageEventManager->Insert(messageId, testMessageEvent);
    messageEventManager->SetCallbackEvent(testSocketEvent);

    Server server{ serverConfigurationStrategy, messageEventManager };

    ConfigurationStrategy clientConfigurationStrategy{ WrappersStrategy::Ace,
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
                                                       port + increase };

    std::vector<ClientSharedPtr> clientContainer{};
    boost::thread_group threadGroup{};

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        clientContainer.emplace_back(make_shared<Client>(clientConfigurationStrategy, messageEventManager));
    }

    for (auto& client : clientContainer)
    {
        threadGroup.create_thread(boost::bind(&ClassType::ClientThread, this, boost::ref(*client), boost::ref(*testSocketEvent)));
    }

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

    ASSERT_GREATER_EQUAL(testMessageEvent->GetCallBackTime(), loopCount * messageId);

    threadGroup.join_all();
}

void Network::IterativeServerTesting::ClientThread(Client& client, const TestSocketEvent& testSocketManager)
{
    auto socketId = 0LL;
    for (;;)
    {
        socketId = client.Connect();
        if (socketId != 0)
        {
            break;
        }
    }

    for (;;)
    {
        const auto message = std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId);
        client.Send(socketId, message);

        const auto volatile asyncAcceptorCount = testSocketManager.GetAsyncAcceptorCount();

        if (const auto loopCount = GetTestLoopCount();
            asyncAcceptorCount == loopCount)
        {
            break;
        }
    }
}
