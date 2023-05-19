///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 09:50)

#include "ACESockStreamTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockConnector.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/NullMessage.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketEvent.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

#include <CoreTools/Contract/Flags/DisableNotThrowFlags.h>

#include <array>
#include <thread>

Network::ACESockStreamTesting::ACESockStreamTesting(const OStreamShared& stream)
    : ParentType{ stream }, port{ 7540 + System::GetEngineeringOffsetValue() }, bufferSize{ 1048576 }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ACESockStreamTesting)

void Network::ACESockStreamTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::ACESockStreamTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::StreamTest);
}

void Network::ACESockStreamTesting::StreamTest()
{
    std::thread thread0{ &ClassType::ACEServerThread, this };
    auto configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, bufferSize);
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, bufferSize);

    ConfigurationStrategy clientConfigurationStrategy{ WrappersStrategy::Ace,
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
                                                       port };

    auto sockStream = std::make_shared<SockStream>(clientConfigurationStrategy);

    SockConnector sockConnector{ clientConfigurationStrategy };
    const auto sockAddress = make_shared<SockAddress>(clientConfigurationStrategy.GetHost(), clientConfigurationStrategy.GetPort(), clientConfigurationStrategy);

    if (sockConnector.Connect(sockStream, sockAddress))
    {
        MAYBE_UNUSED const auto nonBlock = sockStream->EnableNonBlock();

        const auto buffer = std::make_shared<MessageBuffer>(BuffBlockSize::Size256, 0, clientConfigurationStrategy.GetParserStrategy());
        buffer->AddCurrentWriteIndex(50);

        MAYBE_UNUSED const auto result0 = sockStream->Send(buffer);
        buffer->ClearCurrentWriteIndex();

        MAYBE_UNUSED const auto result1 = sockStream->Receive(buffer);
    }

    thread0.join();

    std::thread thread1{ &ClassType::ACEServerThread, this };

    sockStream = std::make_shared<SockStream>(clientConfigurationStrategy);

    if (sockConnector.Connect(sockStream, sockAddress))
    {
        MAYBE_UNUSED const auto nonBlock = sockStream->EnableNonBlock();

        const auto testSocketEvent = std::make_shared<TestSocketEvent>();

        const auto buffer = std::make_shared<MessageBuffer>(BuffBlockSize::Size256, 0, clientConfigurationStrategy.GetParserStrategy());
        buffer->AddCurrentWriteIndex(50);
        sockStream->AsyncSend(testSocketEvent, buffer);
        buffer->ClearCurrentWriteIndex();
        sockStream->AsyncReceive(testSocketEvent, buffer);
    }

    thread1.join();
}

void Network::ACESockStreamTesting::ACEServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoACEServerThread);
}

void Network::ACESockStreamTesting::DoACEServerThread()
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
                                                             port };

    constexpr auto messageId = 5;
    const auto configurationStrategy = serverConfigurationStrategy;
    const auto testMessageEvent = std::make_shared<Network::TestMessageEvent>(CoreTools::DisableNotThrow::Disable);
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    messageEventManager->Insert(messageId, testMessageEvent);
    messageEventManager->SetCallbackEvent(testSocketEvent);

    const auto server = make_shared<Server>(configurationStrategy, messageEventManager);

    testMessageEvent->SetServerWeakPtr(server);

    constexpr auto loopCount = 1;
    for (;;)
    {
        ASSERT_TRUE(server->RunServer());

        if (const auto volatile asyncAcceptorCount = testSocketEvent->GetAsyncAcceptorCount();
            asyncAcceptorCount == loopCount)
        {
            break;
        }
    }
}