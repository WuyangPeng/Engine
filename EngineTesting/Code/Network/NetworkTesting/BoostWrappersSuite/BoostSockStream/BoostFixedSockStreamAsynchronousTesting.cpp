///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/18 14:33)

#include "BoostFixedSockStreamAsynchronousTesting.h"
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
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketEvent.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

#include <thread>

Network::BoostFixedSockStreamAsynchronousTesting::BoostFixedSockStreamAsynchronousTesting(const OStreamShared& stream)
    : ParentType{ stream, 2021 }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostFixedSockStreamAsynchronousTesting)

void Network::BoostFixedSockStreamAsynchronousTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessage);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessage);
}

void Network::BoostFixedSockStreamAsynchronousTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::StreamTest);
}

void Network::BoostFixedSockStreamAsynchronousTesting::StreamTest()
{
    std::thread serverThread{ &ClassType::BoostServerThread, this };

    const auto loopCount = GetTestLoopCount();
    for (auto loop = 0; loop < loopCount; ++loop)
    {
        ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousStreamTest);
        ASSERT_NOT_THROW_EXCEPTION_0(ClearOffset);
    }

    BASE_MAIN_MANAGER_SINGLETON.StopContext();

    serverThread.join();
}

void Network::BoostFixedSockStreamAsynchronousTesting::AsynchronousStreamTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ClientTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ServerTest);
}

void Network::BoostFixedSockStreamAsynchronousTesting::ClientTest()
{
    std::thread serverThread{ &ClassType::ServerThread, this };

    const auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());
    const auto sockStream = std::make_shared<TestingType>(configurationStrategy);

    ASSERT_NOT_THROW_EXCEPTION_1(ClientAsynchronousConnect, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ClientAsynchronousSend, *sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ClientAsynchronousReceive, *sockStream);

    serverThread.join();

    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostFixedSockStreamAsynchronousTesting::ClientAsynchronousConnect(const TestingTypeSharedPtr& sockStream)
{
    const auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());

    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    const auto sockAddress = make_shared<SockAddress>(configurationStrategy.GetHost(), configurationStrategy.GetPort(), configurationStrategy);

    SockConnector sockConnector{ configurationStrategy };
    sockConnector.AsyncConnect(testSocketEvent, sockStream, sockAddress);

    constexpr auto aConnectTime = GetAsynchronousConnectTime();
    for (auto i = 0; i < aConnectTime; ++i)
    {
        if (0 < testSocketEvent->GetAsyncConnectCount())
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, aConnectTime, "���ӷ�����ʧ�ܡ�");
    }
}

void Network::BoostFixedSockStreamAsynchronousTesting::ClientAsynchronousSend(TestingType& sockStream)
{
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    sockStream.AsyncSend(testSocketEvent, CreateMessageBuffer());

    constexpr auto sendCount = GetAsynchronousSendTime();
    for (auto i = 0; i < sendCount; ++i)
    {
        if (0 < testSocketEvent->GetAsyncSendCount())
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, sendCount, "������Ϣʧ�ܡ�");
    }
}

void Network::BoostFixedSockStreamAsynchronousTesting::ClientAsynchronousReceive(TestingType& sockStream)
{
    const auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());

    const auto messageBuffer = std::make_shared<MessageBuffer>(BuffBlockSize::Size512, 0, configurationStrategy.GetParserStrategy());
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    sockStream.AsyncReceive(testSocketEvent, messageBuffer);

    constexpr auto receiveCount = GetAsynchronousReceiveTime();
    for (auto i = 0; i < receiveCount; ++i)
    {
        if (0 < testSocketEvent->GetAsyncReceiveCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, receiveCount);
    }

    VerificationMessageBuffer(*messageBuffer);
}

void Network::BoostFixedSockStreamAsynchronousTesting::ServerTest()
{
    std::thread clientThread{ &ClassType::ClientThread, this };

    const auto configurationStrategy = GetBoostFixedServerConfigurationStrategy(GetRealOffset());
    const auto sockStream = std::make_shared<TestingType>(configurationStrategy);

    ASSERT_NOT_THROW_EXCEPTION_1(ServerAsynchronousAcceptor, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ServerAsynchronousReceive, *sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ServerAsynchronousSend, *sockStream);

    clientThread.join();

    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostFixedSockStreamAsynchronousTesting::ServerAsynchronousAcceptor(const TestingTypeSharedPtr& sockStream)
{
    const auto configurationStrategy = GetBoostFixedServerConfigurationStrategy(GetRealOffset());

    SockAcceptor sockAcceptor{ configurationStrategy };

    const auto testSocketEvent = std::make_shared<TestSocketEvent>();

    sockAcceptor.AsyncAccept(testSocketEvent, sockStream);

    constexpr auto aAcceptTime = GetAsynchronousAcceptTime();
    for (auto i = 0; i < aAcceptTime; ++i)
    {
        if (0 < testSocketEvent->GetAsyncAcceptorCount())
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, aAcceptTime, "�ȴ��ͻ�������ʧ�ܡ�");
    }
}

void Network::BoostFixedSockStreamAsynchronousTesting::ServerAsynchronousReceive(TestingType& sockStream)
{
    const auto configurationStrategy = GetBoostFixedServerConfigurationStrategy(GetRealOffset());

    const auto messageBuffer = std::make_shared<MessageBuffer>(BuffBlockSize::Size512, 0, configurationStrategy.GetParserStrategy());
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();

    sockStream.AsyncReceive(testSocketEvent, messageBuffer);

    constexpr auto receiveCount = GetAsynchronousReceiveTime();
    for (auto i = 0; i < receiveCount; ++i)
    {
        if (0 < testSocketEvent->GetAsyncReceiveCount())
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, receiveCount, "������Ϣʧ�ܡ�");
    }

    VerificationMessageBuffer(*messageBuffer);
}

void Network::BoostFixedSockStreamAsynchronousTesting::ServerAsynchronousSend(TestingType& sockStream)
{
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    sockStream.AsyncSend(testSocketEvent, CreateMessageBuffer());

    constexpr auto sendCount = GetAsynchronousSendTime();
    for (auto i = 0; i < sendCount; ++i)
    {
        if (0 < testSocketEvent->GetAsyncSendCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, sendCount);
    }
}
