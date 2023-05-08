///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 14:48)

#include "ReactiveServerTesting.h"
#include "SingletonTestingDetail.h"
#include "Detail/TestSocketManager.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "CoreTools/Base/Version.h"
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

using std::make_shared;
using std::ostream;
using std::vector;

Network::ReactiveServerTesting::ReactiveServerTesting(const OStreamShared& stream)
    : ParentType{ stream }, mPort{ 5358 }, serverSendMessageID{ 9 }, clientSendMessageID{ 7 }, increase{ 1 }
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
    MESSAGE_MANAGER_SINGLETON.Insert(clientSendMessageID, MessageTypeCondition::CreateNullCondition(), NullMessage::Factory);
}

void Network::ReactiveServerTesting::ReactiveServerTest()
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, 1048576);
    subStrategy.Insert(WrappersSubStrategy::SendBufferSize, 1048576);
    ConfigurationStrategy serverConfigurationStrategy{ WrappersStrategy::Ace,
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
                                                       mPort + increase };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(clientSendMessageID) };

    ServerSharedPtr server{ make_shared<Server>(std::make_shared<MessageEventManager>(MessageEventManager::Create()), serverConfigurationStrategy) };

#include STSTEM_WARNING_POP

    ConfigurationStrategy clientConfigurationStrategy{ WrappersStrategy::Ace,
                                                       ConnectStrategy::Tcp,
                                                       ClientStrategy::Cache,
                                                       MessageStrategy::Iovec,
                                                       ParserStrategy::LittleEndian,
                                                       OpenSSLStrategy::Default,
                                                       EncryptedCompressionStrategy::Default,
                                                       subStrategy,
                                                       ConfigurationParameter::Create(),
                                                       SocketSendMessage::Default, "127.0.0.1",
                                                       mPort + increase };

    vector<ClientSharedPtr> clientContainer;
    boost::thread_group threadGroup;

    const auto loopCount = GetTestLoopCount();
    for (auto i = 0; i < loopCount; ++i)
    {
        clientContainer.push_back(make_shared<Client>(clientConfigurationStrategy, std::make_shared<MessageEventManager>(MessageEventManager::Create())));
    }

    for (auto& client : clientContainer)
    {
        threadGroup.create_thread(boost::bind(&ClassType::ClientThread, this, boost::ref(*client)));
    }

    const auto runCount = loopCount * 10;
    for (int i = 0; i < runCount; ++i)
    {
        ASSERT_TRUE(server->RunServer());

        const auto callBackTime = loopCount * clientSendMessageID;

        if (testSocketManager->GetCallBackTime() == callBackTime)
            break;
    }

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), loopCount * clientSendMessageID);

    threadGroup.join_all();
}

void Network::ReactiveServerTesting::ClientThread(Client& client)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(clientSendMessageID) };

#include STSTEM_WARNING_POP

    constexpr auto connectTime = 100;
    uint64_t socketID{ 0 };
    for (auto i = 0; i < connectTime; ++i)
    {
        socketID = client.Connect();
        if (socketID != 0)
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, connectTime);
    }

    MessageInterfaceSharedPtr message{ make_shared<NullMessage>(MessageHeadStrategy::Default, clientSendMessageID) };
    client.Send(socketID, message);

    client.ImmediatelySend(socketID);
}

void Network::ReactiveServerTesting::DestroyMessage()
{
    MESSAGE_MANAGER_SINGLETON.Remove(clientSendMessageID);
}