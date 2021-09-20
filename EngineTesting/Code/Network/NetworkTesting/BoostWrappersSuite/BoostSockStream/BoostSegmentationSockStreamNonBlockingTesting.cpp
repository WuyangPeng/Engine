// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.2.4 (2020/03/13 16:34)

#include "BoostSegmentationSockStreamNonBlockingTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
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

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, BoostSegmentationSockStreamNonBlockingTesting)

void Network::BoostSegmentationSockStreamNonBlockingTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessage);
}

void Network::BoostSegmentationSockStreamNonBlockingTesting ::StreamTest()
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

void Network::BoostSegmentationSockStreamNonBlockingTesting ::NonBlockingStreamTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ClientTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ServerTest);
}

void Network::BoostSegmentationSockStreamNonBlockingTesting ::ClientTest()
{
    thread serverThread{ &ClassType::ServerThread, this };

    auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());
    TestingTypeSharedPtr sockStream{ make_shared<TestingType>(configurationStrategy) };

    ASSERT_NOT_THROW_EXCEPTION_1(ClientNonBlockingConnect, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ClientNonBlockingSend, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ClientNonBlockingReceive, sockStream);

    serverThread.join();

    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSegmentationSockStreamNonBlockingTesting ::ClientNonBlockingConnect(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    constexpr auto connectTime = GetAsynchronousConnectTime();
    for (auto i = 0; i < connectTime; ++i)
    {
        SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy.GetIP(), configurationStrategy.GetPort(), configurationStrategy) };

        SockConnector sockConnector{ configurationStrategy };

        if (sockConnector.Connect(sockStream, sockAddress))
        {
            [[maybe_unused]] auto value = sockStream->EnableNonBlock();

            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, connectTime, "���ӷ�����ʧ�ܡ�");
    }
}

void Network::BoostSegmentationSockStreamNonBlockingTesting ::ClientNonBlockingSend(const TestingTypeSharedPtr& sockStream)
{
    constexpr auto sendTime = GetAsynchronousSendTime();
    for (auto i = 0; i < sendTime; ++i)
    {
        if (0 < sockStream->Send(CreateMessageBuffer()))
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, sendTime, "������Ϣʧ�ܡ�");
    }
}

void Network::BoostSegmentationSockStreamNonBlockingTesting ::ClientNonBlockingReceive(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

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

void Network::BoostSegmentationSockStreamNonBlockingTesting ::ServerTest()
{
    thread clientThread{ &ClassType::ClientThread, this };

    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());
    TestingTypeSharedPtr sockStream{ make_shared<TestingType>(configurationStrategy) };

    ASSERT_NOT_THROW_EXCEPTION_1(ServerNonBlockingAcceptor, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ServerNonBlockingReceive, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ServerNonBlockingSend, sockStream);

    clientThread.join();

    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSegmentationSockStreamNonBlockingTesting ::ServerNonBlockingAcceptor(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    SockAcceptorSharedPtr sockAcceptor{ make_shared<SockAcceptor>(configurationStrategy) };
    [[maybe_unused]] auto value = sockAcceptor->EnableNonBlock();

    constexpr auto acceptTime = GetAsynchronousAcceptTime();
    for (auto i = 0; i < acceptTime; ++i)
    {
        if (sockAcceptor->Accept(sockStream))
        {
            [[maybe_unused]] auto value1 = sockStream->EnableNonBlock();
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, acceptTime, "�ȴ��ͻ�������ʧ�ܡ�");
    }
}

void Network::BoostSegmentationSockStreamNonBlockingTesting ::ServerNonBlockingReceive(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    MessageBufferSharedPtr messageBuffer{ make_shared<MessageBuffer>(BuffBlockSize::Size512, 0, configurationStrategy.GetParserStrategy()) };
    constexpr auto receiveTime = GetAsynchronousReceiveTime();
    for (auto i = 0; i < receiveTime; ++i)
    {
        if (0 < sockStream->Receive(messageBuffer))
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, receiveTime, "������Ϣʧ�ܡ�");
    }

    VerificationMessageBuffer(messageBuffer);
}

void Network::BoostSegmentationSockStreamNonBlockingTesting ::ServerNonBlockingSend(const TestingTypeSharedPtr& sockStream)
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
