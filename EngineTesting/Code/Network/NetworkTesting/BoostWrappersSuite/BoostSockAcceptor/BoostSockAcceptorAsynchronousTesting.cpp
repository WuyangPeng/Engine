///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 13:35)

#include "BoostSockAcceptorAsynchronousTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketEvent.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

#include <thread>

Network::BoostSockAcceptorAsynchronousTesting::BoostSockAcceptorAsynchronousTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockAcceptorAsynchronousTesting)

void Network::BoostSockAcceptorAsynchronousTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BoostSockAcceptorAsynchronousTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::AcceptorTest);
}

void Network::BoostSockAcceptorAsynchronousTesting::AcceptorTest()
{
    std::thread serverThread{ &ClassType::BoostServerThread, this };

    const auto loopCount = GetTestLoopCount();
    for (auto loop = 0; loop < loopCount; ++loop)
    {
        ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousAcceptTest);
        ASSERT_NOT_THROW_EXCEPTION_0(ClearOffset);
    }

    BASE_MAIN_MANAGER_SINGLETON.StopContext();

    serverThread.join();
}

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAcceptTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousAccept0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousAccept1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousAccept2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousAccept3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousAccept4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousAccept5Test);
}

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAccept0Test()
{
    const auto realPort = GetRealPort();

    TestingType sockAcceptor{ realPort, GetBoostServerConfigurationStrategy(GetRealOffset()) };
    ASSERT_NOT_THROW_EXCEPTION_2(AsynchronousAccept, sockAcceptor, &ClassType::AsynchronousAcceptNoUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAccept1Test()
{
    const auto boostHostName = GetHostName();
    const auto realPort = GetRealPort();

    TestingType sockAcceptor{ boostHostName, realPort, GetBoostServerConfigurationStrategy(GetRealOffset()) };
    ASSERT_NOT_THROW_EXCEPTION_2(AsynchronousAccept, sockAcceptor, &ClassType::AsynchronousAcceptNoUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAccept2Test()
{
    TestingType sockAcceptor{ GetBoostServerConfigurationStrategy(GetRealOffset()) };
    ASSERT_NOT_THROW_EXCEPTION_2(AsynchronousAccept, sockAcceptor, &ClassType::AsynchronousAcceptNoUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAccept3Test()
{
    const auto realPort = GetRealPort();

    TestingType sockAcceptor{ realPort, GetBoostServerConfigurationStrategy(GetRealOffset()) };
    ASSERT_NOT_THROW_EXCEPTION_2(AsynchronousAccept, sockAcceptor, &ClassType::AsynchronousAcceptUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAccept4Test()
{
    const auto boostHostName = GetHostName();
    const auto realPort = GetRealPort();

    TestingType sockAcceptor{ boostHostName, realPort, GetBoostServerConfigurationStrategy(GetRealOffset()) };
    ASSERT_NOT_THROW_EXCEPTION_2(AsynchronousAccept, sockAcceptor, &ClassType::AsynchronousAcceptUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAccept5Test()
{
    TestingType sockAcceptor{ GetBoostServerConfigurationStrategy(GetRealOffset()) };
    ASSERT_NOT_THROW_EXCEPTION_2(AsynchronousAccept, sockAcceptor, &ClassType::AsynchronousAcceptUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAccept(TestingType& sockAcceptor, AcceptFunction acceptFunction)
{
    const auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    const auto testSocketEvent = TestSocketEvent::Create();

    if (acceptFunction != nullptr)
    {
        (this->*acceptFunction)(sockAcceptor, testSocketEvent);
    }

    std::thread clientThread{ &ClassType::ClientThread, this };

    constexpr auto acceptTime = GetAsynchronousAcceptTime();
    for (auto i = 0; i < acceptTime; ++i)
    {
        if (0 < testSocketEvent->GetAsyncAcceptorCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, acceptTime);
    }

    clientThread.join();
}

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAcceptNoUseAddress(TestingType& sockAcceptor, const TestSocketEventSharedPtr& testSocketManager)
{
    const auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    const auto sockStream = std::make_shared<SockStream>(configurationStrategy);

    sockAcceptor.AsyncAccept(testSocketManager, sockStream);
}

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAcceptUseAddress(TestingType& sockAcceptor, const TestSocketEventSharedPtr& testSocketManager)
{
    const auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    const auto sockStream = std::make_shared<SockStream>(configurationStrategy);
    const auto sockAddress = std::make_shared<SockAddress>(configurationStrategy);

    sockAcceptor.AsyncAccept(testSocketManager, sockStream, sockAddress);
}
