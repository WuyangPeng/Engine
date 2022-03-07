// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 13:17)

#include "IterativeServerTesting.h"
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
Network::IterativeServerTesting ::IterativeServerTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr }, m_Port{ 5926 }, m_MessageID{ 5 }, m_Increase{ 0 }
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

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, IterativeServerTesting)
void Network::IterativeServerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::IterativeServerTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessage);
    ASSERT_NOT_THROW_EXCEPTION_0(IterativeServerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessage);
}

void Network::IterativeServerTesting ::CreateMessage()
{
    MESSAGE_MANAGER_SINGLETON.Insert(m_MessageID, MessageTypeCondition::CreateNullCondition(), NullMessage::Factory);
}

void Network::IterativeServerTesting ::IterativeServerTest()
{
    ConfigurationSubStrategy configurationSubStrategy = ConfigurationSubStrategy::Create();

    ConfigurationStrategy serverConfigurationStrategy{ WrappersStrategy::ACE, ConnectStrategy::TCP, ServerStrategy::Iterative,
                                                       MessageStrategy::Default, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                                       configurationSubStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default, "127.0.0.1", m_Port + m_Increase };
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(m_MessageID) };
    ServerSharedPtr server{ make_shared<Server>(testSocketManager, serverConfigurationStrategy) };

    ConfigurationStrategy clientConfigurationStrategy{ WrappersStrategy::ACE, ConnectStrategy::TCP, ClientStrategy::OnlySending,
                                                       MessageStrategy::Iovec, ParserStrategy::LittleEndian, OpenSSLStrategy::Default, EncryptedCompressionStrategy::Default,
                                                       configurationSubStrategy, ConfigurationParameter::Create(), SocketSendMessage::Default, "127.0.0.1", m_Port + m_Increase };

    vector<ClientSharedPtr> clientContainer;
    boost::thread_group threadGroup;

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        clientContainer.push_back(make_shared<Client>(clientConfigurationStrategy, testSocketManager));
    }

    for (auto& client : clientContainer)
    {
        threadGroup.create_thread(boost::bind(&ClassType::ClientThread, this, client, testSocketManager));
    }

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

    ASSERT_GREATER_EQUAL(testSocketManager->GetCallBackTime(), loopCount * m_MessageID);

    threadGroup.join_all();
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
void Network::IterativeServerTesting ::ClientThread(ClientSharedPtr client, TestSocketManagerSharedPtr testSocketManagerSharedPtr)
{
    uint64_t socketID{ 0 };
    for (;;)
    {
        socketID = client->Connect();
        if (socketID != 0)
        {
            break;
        }
    }

    for (;;)
    {
        MessageInterfaceSharedPtr message{ make_shared<NullMessage>(m_MessageID) };
        client->Send(socketID, message);

        const auto volatile asyncAcceptorCount = testSocketManagerSharedPtr->GetAsyncAcceptorCount();

        const auto loopCount = GetTestLoopCount();
        if (asyncAcceptorCount == loopCount)
        {
            break;
        }
    }
}

void Network::IterativeServerTesting ::DestroyMessage()
{
    MESSAGE_MANAGER_SINGLETON.Remove(m_MessageID);
}
