///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 11:39)

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
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <thread>

using std::make_shared;
using std::thread;

Network::BoostFixedSockStreamNonBlockingTesting::BoostFixedSockStreamNonBlockingTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostFixedSockStreamNonBlockingTesting)

void Network::BoostFixedSockStreamNonBlockingTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BoostFixedSockStreamNonBlockingTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessage);
}

void Network::BoostFixedSockStreamNonBlockingTesting::StreamTest()
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

void Network::BoostFixedSockStreamNonBlockingTesting::NonBlockingStreamTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ClientTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ServerTest);
}

void Network::BoostFixedSockStreamNonBlockingTesting::ClientTest()
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

void Network::BoostFixedSockStreamNonBlockingTesting::ClientNonBlockingConnect(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());

    constexpr auto aConnectTime = GetAsynchronousConnectTime();
    for (auto i = 0; i < aConnectTime; ++i)
    {
        SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy.GetHost(), configurationStrategy.GetPort(), configurationStrategy) };

        SockConnector sockConnector{ configurationStrategy };

        if (sockConnector.Connect(sockStream, sockAddress))
        {
            MAYBE_UNUSED const auto value = sockStream->EnableNonBlock();

            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, aConnectTime, "连接服务器失败。");
    }
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Network::BoostFixedSockStreamNonBlockingTesting::ClientNonBlockingSend(const TestingTypeSharedPtr& sockStream)
{
    constexpr auto aSendTime = GetAsynchronousSendTime();
    for (auto i = 0; i < aSendTime; ++i)
    {
        if (0 < sockStream->Send(CreateMessageBuffer()))
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, aSendTime, "发送消息失败。");
    }
}

void Network::BoostFixedSockStreamNonBlockingTesting::ClientNonBlockingReceive(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());

    MessageBufferSharedPtr messageBuffer{ make_shared<MessageBuffer>(BuffBlockSize::Size512, 0, configurationStrategy.GetParserStrategy()) };
    constexpr auto aReceiveTime = GetAsynchronousReceiveTime();
    for (auto i = 0; i < aReceiveTime; ++i)
    {
        if (0 < sockStream->Receive(messageBuffer))
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, aReceiveTime);
    }

    VerificationMessageBuffer(messageBuffer);
}

void Network::BoostFixedSockStreamNonBlockingTesting::ServerTest()
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

void Network::BoostFixedSockStreamNonBlockingTesting::ServerNonBlockingAcceptor(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostFixedServerConfigurationStrategy(GetRealOffset());

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    SockAcceptorSharedPtr sockAcceptor{ make_shared<SockAcceptor>(configurationStrategy) };

#include STSTEM_WARNING_POP

    MAYBE_UNUSED const auto value = sockAcceptor->EnableNonBlock();

    constexpr auto aAcceptTime = GetAsynchronousAcceptTime();
    for (auto i = 0; i < aAcceptTime; ++i)
    {
        if (sockAcceptor->Accept(*sockStream))
        {
            MAYBE_UNUSED const auto value1 = sockStream->EnableNonBlock();
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, aAcceptTime, "等待客户端连接失败。");
    }
}

void Network::BoostFixedSockStreamNonBlockingTesting::ServerNonBlockingReceive(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostFixedServerConfigurationStrategy(GetRealOffset());

    MessageBufferSharedPtr messageBuffer{ make_shared<MessageBuffer>(BuffBlockSize::Size512, 0, configurationStrategy.GetParserStrategy()) };
    constexpr auto aReceiveTime = GetAsynchronousReceiveTime();
    for (auto i = 0; i < aReceiveTime; ++i)
    {
        if (0 < sockStream->Receive(messageBuffer))
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, aReceiveTime, "接收消息失败。");
    }

    VerificationMessageBuffer(messageBuffer);
}

void Network::BoostFixedSockStreamNonBlockingTesting::ServerNonBlockingSend(const TestingTypeSharedPtr& sockStream)
{
    constexpr auto aSendTime = GetAsynchronousSendTime();
    for (auto i = 0; i < aSendTime; ++i)
    {
        if (0 < sockStream->Send(CreateMessageBuffer()))
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, aSendTime);
    }
}

#include STSTEM_WARNING_POP