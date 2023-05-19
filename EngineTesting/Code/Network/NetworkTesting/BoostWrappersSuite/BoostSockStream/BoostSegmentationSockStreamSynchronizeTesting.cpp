///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 16:29)

#include "BoostSegmentationSockStreamSynchronizeTesting.h"
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

Network::BoostSegmentationSockStreamSynchronizeTesting::BoostSegmentationSockStreamSynchronizeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSegmentationSockStreamSynchronizeTesting)

void Network::BoostSegmentationSockStreamSynchronizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessage);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessage);
}

void Network::BoostSegmentationSockStreamSynchronizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::StreamTest);
}

void Network::BoostSegmentationSockStreamSynchronizeTesting::StreamTest()
{
    std::thread serverThread{ &ClassType::BoostServerThread, this };

    const auto loopCount = GetTestLoopCount();
    for (auto loop = 0; loop < loopCount; ++loop)
    {
        ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeStreamTest);
        ASSERT_NOT_THROW_EXCEPTION_0(ClearOffset);
    }

    BASE_MAIN_MANAGER_SINGLETON.StopContext();

    serverThread.join();
}

void Network::BoostSegmentationSockStreamSynchronizeTesting::SynchronizeStreamTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ClientTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ServerTest);
}

void Network::BoostSegmentationSockStreamSynchronizeTesting::ClientTest()
{
    std::thread serverThread{ &ClassType::ServerThread, this };

    const auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());
    const auto sockStream = std::make_shared<TestingType>(configurationStrategy);

    ASSERT_NOT_THROW_EXCEPTION_1(ClientSynchronizeConnect, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ClientSynchronizeSend, *sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ClientSynchronizeReceive, *sockStream);

    serverThread.join();

    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSegmentationSockStreamSynchronizeTesting::ClientSynchronizeConnect(const TestingTypeSharedPtr& sockStream)
{
    const auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    constexpr auto connectCount = GetSynchronizeConnectTime();
    for (auto i = 0; i < connectCount; ++i)
    {
        const auto sockAddress = make_shared<SockAddress>(configurationStrategy.GetHost(), configurationStrategy.GetPort(), configurationStrategy);

        if (SockConnector sockConnector{ configurationStrategy };
            sockConnector.Connect(sockStream, sockAddress))
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, connectCount, "连接服务器失败。");
    }
}

void Network::BoostSegmentationSockStreamSynchronizeTesting::ClientSynchronizeSend(TestingType& sockStream)
{
    constexpr auto sendCount = GetSynchronizeSendTime();
    for (auto i = 0; i < sendCount; ++i)
    {
        if (0 < sockStream.Send(CreateMessageBuffer()))
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, sendCount, "发送消息失败。");
    }
}

void Network::BoostSegmentationSockStreamSynchronizeTesting::ClientSynchronizeReceive(TestingType& sockStream)
{
    const auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    const auto messageBuffer = std::make_shared<MessageBuffer>(BuffBlockSize::Size512, 0, configurationStrategy.GetParserStrategy());
    constexpr auto receiveCount = GetSynchronizeReceiveTime();
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

void Network::BoostSegmentationSockStreamSynchronizeTesting::ServerTest()
{
    std::thread clientThread{ &ClassType::ClientThread, this };

    const auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());
    TestingType sockStream{ configurationStrategy };

    ASSERT_NOT_THROW_EXCEPTION_1(ServerSynchronizeAcceptor, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ServerSynchronizeReceive, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ServerSynchronizeSend, sockStream);

    clientThread.join();

    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSegmentationSockStreamSynchronizeTesting::ServerSynchronizeAcceptor(TestingType& sockStream)
{
    const auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    SockAcceptor sockAcceptor{ configurationStrategy };

    constexpr auto acceptCount = GetSynchronizeAcceptTime();
    for (auto i = 0; i < acceptCount; ++i)
    {
        if (sockAcceptor.Accept(sockStream))
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, acceptCount, "等待客户端连接失败。");
    }
}

void Network::BoostSegmentationSockStreamSynchronizeTesting::ServerSynchronizeReceive(TestingType& sockStream)
{
    const auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    const auto messageBuffer = std::make_shared<MessageBuffer>(BuffBlockSize::Size512, 0, configurationStrategy.GetParserStrategy());
    constexpr auto receiveCount = GetSynchronizeReceiveTime();
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

void Network::BoostSegmentationSockStreamSynchronizeTesting::ServerSynchronizeSend(TestingType& sockStream)
{
    constexpr auto sendCount = GetSynchronizeSendTime();
    for (auto i = 0; i < sendCount; ++i)
    {
        if (0 < sockStream.Send(CreateMessageBuffer()))
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, sendCount);
    }
}
