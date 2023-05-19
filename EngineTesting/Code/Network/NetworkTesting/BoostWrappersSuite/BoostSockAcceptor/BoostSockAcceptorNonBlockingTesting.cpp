///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 13:50)

#include "BoostSockAcceptorNonBlockingTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/Client.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketEvent.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

#include <thread>

Network::BoostSockAcceptorNonBlockingTesting::BoostSockAcceptorNonBlockingTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockAcceptorNonBlockingTesting)

void Network::BoostSockAcceptorNonBlockingTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BoostSockAcceptorNonBlockingTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::AcceptorTest);
}

void Network::BoostSockAcceptorNonBlockingTesting::AcceptorTest()
{
    std::thread serverThread{ &ClassType::BoostServerThread, this };

    const auto loopCount = GetTestLoopCount();
    for (auto loop = 0; loop < loopCount; ++loop)
    {
        ASSERT_NOT_THROW_EXCEPTION_0(NonBlockingTest);
        ASSERT_NOT_THROW_EXCEPTION_0(ClearOffset);
    }

    BASE_MAIN_MANAGER_SINGLETON.StopContext();

    serverThread.join();
}

void Network::BoostSockAcceptorNonBlockingTesting::NonBlockingTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NonBlocking0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(NonBlocking1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(NonBlocking2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(NonBlocking3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(NonBlocking4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(NonBlocking5Test);
}

void Network::BoostSockAcceptorNonBlockingTesting::NonBlocking0Test()
{
    const auto realPort = GetRealPort();

    TestingType sockAcceptor{ realPort, GetBoostServerConfigurationStrategy(GetRealOffset()) };
    ASSERT_NOT_THROW_EXCEPTION_2(NonBlockingAccept, sockAcceptor, &ClassType::NonBlockingAcceptNoUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorNonBlockingTesting::NonBlocking1Test()
{
    const auto boostHostName = GetHostName();
    const auto realPort = GetRealPort();

    TestingType sockAcceptor{ boostHostName, realPort, GetBoostServerConfigurationStrategy(GetRealOffset()) };
    ASSERT_NOT_THROW_EXCEPTION_2(NonBlockingAccept, sockAcceptor, &ClassType::NonBlockingAcceptNoUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorNonBlockingTesting::NonBlocking2Test()
{
    TestingType sockAcceptor{ GetBoostServerConfigurationStrategy(GetRealOffset()) };
    ASSERT_NOT_THROW_EXCEPTION_2(NonBlockingAccept, sockAcceptor, &ClassType::NonBlockingAcceptNoUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorNonBlockingTesting::NonBlocking3Test()
{
    const auto realPort = GetRealPort();

    TestingType sockAcceptor{ realPort, GetBoostServerConfigurationStrategy(GetRealOffset()) };
    ASSERT_NOT_THROW_EXCEPTION_2(NonBlockingAccept, sockAcceptor, &ClassType::NonBlockingAcceptUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorNonBlockingTesting::NonBlocking4Test()
{
    const auto boostHostName = GetHostName();
    const auto realPort = GetRealPort();

    TestingType sockAcceptor{ boostHostName, realPort, GetBoostServerConfigurationStrategy(GetRealOffset()) };
    ASSERT_NOT_THROW_EXCEPTION_2(NonBlockingAccept, sockAcceptor, &ClassType::NonBlockingAcceptUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorNonBlockingTesting::NonBlocking5Test()
{
    TestingType sockAcceptor{ GetBoostServerConfigurationStrategy(GetRealOffset()) };
    ASSERT_NOT_THROW_EXCEPTION_2(NonBlockingAccept, sockAcceptor, &ClassType::NonBlockingAcceptUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorNonBlockingTesting::NonBlockingAccept(TestingType& sockAcceptor, AcceptFunction acceptFunction)
{
    MAYBE_UNUSED const auto nonBlock = sockAcceptor.EnableNonBlock();

    std::thread clientThread{ &ClassType::ClientThread, this };

    constexpr auto acceptTime = GetSynchronizeAcceptTime();
    for (auto i = 0; i < acceptTime; ++i)
    {
        if (acceptFunction == nullptr || (this->*acceptFunction)(sockAcceptor))
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, acceptTime);
    }

    clientThread.join();
}

bool Network::BoostSockAcceptorNonBlockingTesting::NonBlockingAcceptNoUseAddress(TestingType& sockAcceptor)
{
    const auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    SockStream sockStream{ configurationStrategy };

    return sockAcceptor.Accept(sockStream);
}

bool Network::BoostSockAcceptorNonBlockingTesting::NonBlockingAcceptUseAddress(TestingType& sockAcceptor)
{
    const auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    SockStream sockStream{ configurationStrategy };
    SockAddress sockAddress{ configurationStrategy };

    return sockAcceptor.Accept(sockStream, sockAddress);
}
