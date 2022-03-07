// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 13:18)

#include "ReactiveServerTesting.h"
#include "SingletonTestingDetail.h"
#include "Detail/TestSocketManager.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"

#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
Network::ReactiveServerTesting ::ReactiveServerTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr }, m_Port{ 5358 }, m_ServerSendMessageID{ 9 }, m_ClientSendMessageID{ 7 }, m_Increase{ 1 }
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

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ReactiveServerTesting)
void Network::ReactiveServerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::ReactiveServerTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessage);
    ASSERT_NOT_THROW_EXCEPTION_0(ReactiveServerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessage);
}

void Network::ReactiveServerTesting ::CreateMessage()
{
    MESSAGE_MANAGER_SINGLETON.Insert(m_ClientSendMessageID, MessageTypeCondition::CreateNullCondition(), NullMessage::Factory);
}

void Network::ReactiveServerTesting ::ReactiveServerTest()
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();
    ConfigurationStrategy serverConfigurationStrategy{ WrappersStrategy::ACE, ConnectStrategy::TCP, ServerStrategy::Reactive,
                                                       MessageStrategy::Default, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                                       subStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default, "127.0.0.1", m_Port + m_Increase };
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(m_ClientSendMessageID) };
    ServerSharedPtr server{ make_shared<Server>(testSocketManager, serverConfigurationStrategy) };

    ConfigurationStrategy clientConfigurationStrategy{ WrappersStrategy::ACE, ConnectStrategy::TCP, ClientStrategy::Cache,
                                                       MessageStrategy::Iovec, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                                       subStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default, "127.0.0.1", m_Port + m_Increase };

    vector<ClientSharedPtr> clientContainer;
    boost::thread_group threadGroup;

    const auto loopCount = GetTestLoopCount();
    for (auto i = 0; i < loopCount; ++i)
    {
        clientContainer.push_back(make_shared<Client>(clientConfigurationStrategy, testSocketManager));
    }

    for (auto& client : clientContainer)
    {
        threadGroup.create_thread(boost::bind(&ClassType::ClientThread, this, boost::ref(*client)));
    }

    const auto runCount = loopCount * 10;
    for (int i = 0; i < runCount; ++i)
    {
        ASSERT_TRUE(server->RunServer());

        const auto callBackTime = loopCount * m_ClientSendMessageID;

        if (testSocketManager->GetCallBackTime() == callBackTime)
            break;
    }

    ASSERT_EQUAL(testSocketManager->GetCallBackTime(), loopCount * m_ClientSendMessageID);

    threadGroup.join_all();
}

void Network::ReactiveServerTesting ::ClientThread(Client& client)
{
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(m_ClientSendMessageID) };

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

    MessageInterfaceSharedPtr message{ make_shared<NullMessage>(m_ClientSendMessageID) };
    client.Send(socketID, message);

    client.ImmediatelySend(socketID);
}

void Network::ReactiveServerTesting ::DestroyMessage()
{
    MESSAGE_MANAGER_SINGLETON.Remove(m_ClientSendMessageID);
}