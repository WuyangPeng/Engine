///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 11:34)

#include "BoostFixedSockStreamAsynchronousTesting.h"
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
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <thread>

using std::make_shared;
using std::thread;

Network::BoostFixedSockStreamAsynchronousTesting::BoostFixedSockStreamAsynchronousTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostFixedSockStreamAsynchronousTesting)

void Network::BoostFixedSockStreamAsynchronousTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BoostFixedSockStreamAsynchronousTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessage);
}

void Network::BoostFixedSockStreamAsynchronousTesting::StreamTest()
{
    thread serverThread{ &ClassType::BoostServerThread, this };

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
    thread serverThread{ &ClassType::ServerThread, this };

    auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());
    TestingTypeSharedPtr sockStream{ make_shared<TestingType>(configurationStrategy) };

    ASSERT_NOT_THROW_EXCEPTION_1(ClientAsynchronousConnect, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ClientAsynchronousSend, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ClientAsynchronousReceive, sockStream);

    serverThread.join();

    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostFixedSockStreamAsynchronousTesting::ClientAsynchronousConnect(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());

    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };
    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy.GetHost(), configurationStrategy.GetPort(), configurationStrategy) };

    SockConnector sockConnector{ configurationStrategy };
    sockConnector.AsyncConnect(testSocketManager, sockStream, sockAddress);

    constexpr auto aConnectTime = GetAsynchronousConnectTime();
    for (auto i = 0; i < aConnectTime; ++i)
    {
        if (0 < testSocketManager->GetAsyncConnectCount())
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, aConnectTime, "连接服务器失败。");
    }
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Network::BoostFixedSockStreamAsynchronousTesting::ClientAsynchronousSend(const TestingTypeSharedPtr& sockStream)
{
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };
    sockStream->AsyncSend(testSocketManager, CreateMessageBuffer());

    constexpr auto aSendTime = GetAsynchronousSendTime();
    for (auto i = 0; i < aSendTime; ++i)
    {
        if (0 < testSocketManager->GetAsyncSendCount())
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, aSendTime, "发送消息失败。");
    }
}

void Network::BoostFixedSockStreamAsynchronousTesting::ClientAsynchronousReceive(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());

    MessageBufferSharedPtr messageBuffer{ make_shared<MessageBuffer>(BuffBlockSize::Size512, 0, configurationStrategy.GetParserStrategy()) };
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };
    sockStream->AsyncReceive(testSocketManager, messageBuffer);

    constexpr auto aReceiveTime = GetAsynchronousReceiveTime();
    for (auto i = 0; i < aReceiveTime; ++i)
    {
        if (0 < testSocketManager->GetAsyncReceiveCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, aReceiveTime);
    }

    VerificationMessageBuffer(messageBuffer);
}

#include STSTEM_WARNING_POP

void Network::BoostFixedSockStreamAsynchronousTesting::ServerTest()
{
    thread clientThread{ &ClassType::ClientThread, this };

    auto configurationStrategy = GetBoostFixedServerConfigurationStrategy(GetRealOffset());
    TestingTypeSharedPtr sockStream{ make_shared<TestingType>(configurationStrategy) };

    ASSERT_NOT_THROW_EXCEPTION_1(ServerAsynchronousAcceptor, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ServerAsynchronousReceive, sockStream);
    ASSERT_NOT_THROW_EXCEPTION_1(ServerAsynchronousSend, sockStream);

    clientThread.join();

    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostFixedSockStreamAsynchronousTesting::ServerAsynchronousAcceptor(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostFixedServerConfigurationStrategy(GetRealOffset());

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    SockAcceptorSharedPtr sockAcceptor{ make_shared<SockAcceptor>(configurationStrategy) };

#include STSTEM_WARNING_POP

    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };

    sockAcceptor->AsyncAccept(testSocketManager, sockStream);

    constexpr auto aAcceptTime = GetAsynchronousAcceptTime();
    for (auto i = 0; i < aAcceptTime; ++i)
    {
        if (0 < testSocketManager->GetAsyncAcceptorCount())
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, aAcceptTime, "等待客户端连接失败。");
    }
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Network::BoostFixedSockStreamAsynchronousTesting::ServerAsynchronousReceive(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostFixedServerConfigurationStrategy(GetRealOffset());

    MessageBufferSharedPtr messageBuffer{ make_shared<MessageBuffer>(BuffBlockSize::Size512, 0, configurationStrategy.GetParserStrategy()) };
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };

    sockStream->AsyncReceive(testSocketManager, messageBuffer);

    constexpr auto aReceiveTime = GetAsynchronousReceiveTime();
    for (auto i = 0; i < aReceiveTime; ++i)
    {
        if (0 < testSocketManager->GetAsyncReceiveCount())
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, aReceiveTime, "接收消息失败。");
    }

    VerificationMessageBuffer(messageBuffer);
}

void Network::BoostFixedSockStreamAsynchronousTesting::ServerAsynchronousSend(const TestingTypeSharedPtr& sockStream)
{
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };
    sockStream->AsyncSend(testSocketManager, CreateMessageBuffer());

    constexpr auto aSendTime = GetAsynchronousSendTime();
    for (auto i = 0; i < aSendTime; ++i)
    {
        if (0 < testSocketManager->GetAsyncSendCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, aSendTime);
    }
}

#include STSTEM_WARNING_POP