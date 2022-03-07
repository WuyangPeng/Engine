// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.4 (2020/03/13 16:31)

#include "BoostFixedSockStreamNonBlockingTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockConnector.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/NetworkMessage/NullMessage.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

#include <thread>

using std::make_shared;
using std::thread;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, BoostFixedSockStreamNonBlockingTesting)
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26414)
void Network::BoostFixedSockStreamNonBlockingTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessage);
  //  ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessage);
}

void Network::BoostFixedSockStreamNonBlockingTesting ::StreamTest()
{
    thread serverThread{ &ClassType::BoostServerThread, this };

    const auto loopCount = GetTestLoopCount();
    for (auto loop = 0; loop < loopCount; ++loop)
    {
        ASSERT_NOT_THROW_EXCEPTION_0(NonBlockingStreamTest);
        ASSERT_NOT_THROW_EXCEPTION_0(ClearOffset);
    }

    BASE_MAIN_MANAGER_SINGLETON.StopContext();

    serverThread.join();
}

void Network::BoostFixedSockStreamNonBlockingTesting ::NonBlockingStreamTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ClientTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ServerTest);
}

void Network::BoostFixedSockStreamNonBlockingTesting ::ClientTest()
{
    thread serverThread{ &ClassType::ServerThread, this };

    auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());
    TestingTypeSharedPtr sockStream{ make_shared<TestingType>(configurationStrategy) };

    ASSERT_NOT_THROW_EXCEPTION_1(ClientNonBlockingConnect, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ClientNonBlockingSend, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ClientNonBlockingReceive, sockStream);

    serverThread.join();

    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostFixedSockStreamNonBlockingTesting ::ClientNonBlockingConnect(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());

    constexpr auto connectTime = GetAsynchronousConnectTime();
    for (auto i = 0; i < connectTime; ++i)
    {
        SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy.GetIP(), configurationStrategy.GetPort(), configurationStrategy) };

        SockConnector sockConnector{ configurationStrategy };

        if (sockConnector.Connect(sockStream, sockAddress))
        {
            [[maybe_unused]] const auto value = sockStream->EnableNonBlock();

            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, connectTime, "连接服务器失败。");
    }
}

void Network::BoostFixedSockStreamNonBlockingTesting ::ClientNonBlockingSend(const TestingTypeSharedPtr& sockStream)
{
    constexpr auto sendTime = GetAsynchronousSendTime();
    for (auto i = 0; i < sendTime; ++i)
    {
        if (0 < sockStream->Send(CreateMessageBuffer()))
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, sendTime, "发送消息失败。");
    }
}

void Network::BoostFixedSockStreamNonBlockingTesting ::ClientNonBlockingReceive(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());

    MessageBufferSharedPtr messageBuffer{ make_shared<MessageBuffer>(BuffBlockSize::Size512, 0, configurationStrategy.GetParserStrategy()) };
    constexpr auto receiveTime = GetAsynchronousReceiveTime();
    for (auto i = 0; i < receiveTime; ++i)
    {
        if (0 < sockStream->Receive(messageBuffer))
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, receiveTime);
    }

    VerificationMessageBuffer(messageBuffer);
}

void Network::BoostFixedSockStreamNonBlockingTesting ::ServerTest()
{
    thread clientThread{ &ClassType::ClientThread, this };

    auto configurationStrategy = GetBoostFixedServerConfigurationStrategy(GetRealOffset());
    TestingTypeSharedPtr sockStream{ make_shared<TestingType>(configurationStrategy) };

    ASSERT_NOT_THROW_EXCEPTION_1(ServerNonBlockingAcceptor, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ServerNonBlockingReceive, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ServerNonBlockingSend, sockStream);

    clientThread.join();

    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostFixedSockStreamNonBlockingTesting ::ServerNonBlockingAcceptor(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostFixedServerConfigurationStrategy(GetRealOffset());

    SockAcceptorSharedPtr sockAcceptor{ make_shared<SockAcceptor>(configurationStrategy) };
    [[maybe_unused]] const auto value = sockAcceptor->EnableNonBlock();

    constexpr auto acceptTime = GetAsynchronousAcceptTime();
    for (auto i = 0; i < acceptTime; ++i)
    {
        if (sockAcceptor->Accept(*sockStream))
        {
            [[maybe_unused]] const auto value1 = sockStream->EnableNonBlock();
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, acceptTime, "等待客户端连接失败。");
    }
}

void Network::BoostFixedSockStreamNonBlockingTesting ::ServerNonBlockingReceive(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostFixedServerConfigurationStrategy(GetRealOffset());

    MessageBufferSharedPtr messageBuffer{ make_shared<MessageBuffer>(BuffBlockSize::Size512, 0, configurationStrategy.GetParserStrategy()) };
    constexpr auto receiveTime = GetAsynchronousReceiveTime();
    for (auto i = 0; i < receiveTime; ++i)
    {
        if (0 < sockStream->Receive(messageBuffer))
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, receiveTime, "接收消息失败。");
    }

    VerificationMessageBuffer(messageBuffer);
}

void Network::BoostFixedSockStreamNonBlockingTesting ::ServerNonBlockingSend(const TestingTypeSharedPtr& sockStream)
{
    constexpr auto sendTime = GetAsynchronousSendTime();
    for (auto i = 0; i < sendTime; ++i)
    {
        if (0 < sockStream->Send(CreateMessageBuffer()))
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, sendTime);
    }
}
