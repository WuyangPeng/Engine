///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 16:19)

#include "BoostSegmentationSockStreamNonBlockingTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
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

Network::BoostSegmentationSockStreamNonBlockingTesting::BoostSegmentationSockStreamNonBlockingTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSegmentationSockStreamNonBlockingTesting)

void Network::BoostSegmentationSockStreamNonBlockingTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessage);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessage);
}

void Network::BoostSegmentationSockStreamNonBlockingTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::StreamTest);
}

void Network::BoostSegmentationSockStreamNonBlockingTesting::StreamTest()
{
    std::thread serverThread{ &ClassType::BoostServerThread, this };

    const auto loopCount = GetTestLoopCount();
    for (auto loop = 0; loop < loopCount; ++loop)
    {
        ASSERT_NOT_THROW_EXCEPTION_0(NonBlockingStreamTest);
        ASSERT_NOT_THROW_EXCEPTION_0(ClearOffset);
    }

    BASE_MAIN_MANAGER_SINGLETON.StopContext();

    serverThread.join();
}

void Network::BoostSegmentationSockStreamNonBlockingTesting::NonBlockingStreamTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ClientTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ServerTest);
}

void Network::BoostSegmentationSockStreamNonBlockingTesting::ClientTest()
{
    std::thread serverThread{ &ClassType::ServerThread, this };

    const auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());
    const auto sockStream = std::make_shared<TestingType>(configurationStrategy);

    ASSERT_NOT_THROW_EXCEPTION_1(ClientNonBlockingConnect, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ClientNonBlockingSend, *sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ClientNonBlockingReceive, *sockStream);

    serverThread.join();

    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSegmentationSockStreamNonBlockingTesting::ClientNonBlockingConnect(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    constexpr auto connectCount = GetAsynchronousConnectTime();
    for (auto i = 0; i < connectCount; ++i)
    {
        const auto sockAddress = make_shared<SockAddress>(configurationStrategy.GetHost(), configurationStrategy.GetPort(), configurationStrategy);

        if (SockConnector sockConnector{ configurationStrategy };
            sockConnector.Connect(sockStream, sockAddress))
        {
            MAYBE_UNUSED const auto result = sockStream->EnableNonBlock();

            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, connectCount, "连接服务器失败。");
    }
}

void Network::BoostSegmentationSockStreamNonBlockingTesting::ClientNonBlockingSend(TestingType& sockStream)
{
    constexpr auto sendCount = GetAsynchronousSendTime();
    for (auto i = 0; i < sendCount; ++i)
    {
        if (0 < sockStream.Send(CreateMessageBuffer()))
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, sendCount, "发送消息失败。");
    }
}

void Network::BoostSegmentationSockStreamNonBlockingTesting::ClientNonBlockingReceive(TestingType& sockStream)
{
    const auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    const auto messageBuffer = std::make_shared<MessageBuffer>(BuffBlockSize::Size512, 0, configurationStrategy.GetParserStrategy());
    constexpr auto receiveCount = GetAsynchronousReceiveTime();
    for (auto i = 0; i < receiveCount; ++i)
    {
        if (0 < sockStream.Receive(messageBuffer))
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, receiveCount);
    }

    VerificationMessageBuffer(*messageBuffer);
}

void Network::BoostSegmentationSockStreamNonBlockingTesting::ServerTest()
{
    std::thread clientThread{ &ClassType::ClientThread, this };

    const auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());
    TestingType sockStream{ configurationStrategy };

    ASSERT_NOT_THROW_EXCEPTION_1(ServerNonBlockingAcceptor, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ServerNonBlockingReceive, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ServerNonBlockingSend, sockStream);

    clientThread.join();

    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSegmentationSockStreamNonBlockingTesting::ServerNonBlockingAcceptor(TestingType& sockStream)
{
    const auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    SockAcceptor sockAcceptor{ configurationStrategy };

    MAYBE_UNUSED const auto nonBlock = sockAcceptor.EnableNonBlock();

    constexpr auto acceptCount = GetAsynchronousAcceptTime();
    for (auto i = 0; i < acceptCount; ++i)
    {
        if (sockAcceptor.Accept(sockStream))
        {
            MAYBE_UNUSED const auto value1 = sockStream.EnableNonBlock();
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, acceptCount, "等待客户端连接失败。");
    }
}

void Network::BoostSegmentationSockStreamNonBlockingTesting::ServerNonBlockingReceive(TestingType& sockStream)
{
    const auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    const auto messageBuffer = std::make_shared<MessageBuffer>(BuffBlockSize::Size512, 0, configurationStrategy.GetParserStrategy());
    constexpr auto receiveCount = GetAsynchronousReceiveTime();
    for (auto i = 0; i < receiveCount; ++i)
    {
        if (0 < sockStream.Receive(messageBuffer))
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, receiveCount, "接收消息失败。");
    }

    VerificationMessageBuffer(*messageBuffer);
}

void Network::BoostSegmentationSockStreamNonBlockingTesting::ServerNonBlockingSend(TestingType& sockStream)
{
    constexpr auto sendCount = GetAsynchronousSendTime();
    for (auto i = 0; i < sendCount; ++i)
    {
        if (0 < sockStream.Send(CreateMessageBuffer()))
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, sendCount);
    }
}
