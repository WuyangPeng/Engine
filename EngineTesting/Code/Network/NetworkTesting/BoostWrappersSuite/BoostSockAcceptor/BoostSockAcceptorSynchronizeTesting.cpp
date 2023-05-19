///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 14:02)

#include "BoostSockAcceptorSynchronizeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/Client.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

#include <thread>

Network::BoostSockAcceptorSynchronizeTesting::BoostSockAcceptorSynchronizeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockAcceptorSynchronizeTesting)

void Network::BoostSockAcceptorSynchronizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BoostSockAcceptorSynchronizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::AcceptorTest);
}

void Network::BoostSockAcceptorSynchronizeTesting::AcceptorTest()
{
    std::thread serverThread{ &ClassType::BoostServerThread, this };

    const auto loopCount = GetTestLoopCount();
    for (auto loop = 0; loop < loopCount; ++loop)
    {
        ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAcceptTest);
        ASSERT_NOT_THROW_EXCEPTION_0(ClearOffset);
    }

    BASE_MAIN_MANAGER_SINGLETON.StopContext();

    serverThread.join();
}

void Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAcceptTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAccept0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAccept1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAccept2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAccept3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAccept4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAccept5Test);
}

void Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAccept0Test()
{
    const auto realPort = GetRealPort();

    TestingType sockAcceptor{ realPort, GetBoostServerConfigurationStrategy(GetRealOffset()) };
    ASSERT_NOT_THROW_EXCEPTION_2(SynchronizeAccept, sockAcceptor, &ClassType::SynchronizeAcceptNoUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAccept1Test()
{
    const auto boostHostName = GetHostName();
    const auto realPort = GetRealPort();

    TestingType sockAcceptor{ boostHostName, realPort, GetBoostServerConfigurationStrategy(GetRealOffset()) };
    ASSERT_NOT_THROW_EXCEPTION_2(SynchronizeAccept, sockAcceptor, &ClassType::SynchronizeAcceptNoUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAccept2Test()
{
    TestingType sockAcceptor{ GetBoostServerConfigurationStrategy(GetRealOffset()) };
    ASSERT_NOT_THROW_EXCEPTION_2(SynchronizeAccept, sockAcceptor, &ClassType::SynchronizeAcceptNoUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAccept3Test()
{
    const auto realPort = GetRealPort();

    TestingType sockAcceptor{ realPort, GetBoostServerConfigurationStrategy(GetRealOffset()) };
    ASSERT_NOT_THROW_EXCEPTION_2(SynchronizeAccept, sockAcceptor, &ClassType::SynchronizeAcceptUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAccept4Test()
{
    const auto boostHostName = GetHostName();
    const auto port1 = GetRealPort();

    TestingType sockAcceptor{ boostHostName, port1, GetBoostServerConfigurationStrategy(GetRealOffset()) };
    ASSERT_NOT_THROW_EXCEPTION_2(SynchronizeAccept, sockAcceptor, &ClassType::SynchronizeAcceptUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAccept5Test()
{
    TestingType sockAcceptor{ GetBoostServerConfigurationStrategy(GetRealOffset()) };
    ASSERT_NOT_THROW_EXCEPTION_2(SynchronizeAccept, sockAcceptor, &ClassType::SynchronizeAcceptUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAccept(TestingType& sockAcceptor, AcceptFunction acceptFunction)
{
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

bool Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAcceptNoUseAddress(TestingType& sockAcceptor)
{
    const auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    SockStream sockStream{ configurationStrategy };

    return sockAcceptor.Accept(sockStream);
}

bool Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAcceptUseAddress(TestingType& sockAcceptor)
{
    const auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    SockStream sockStream{ configurationStrategy };
    SockAddress sockAddress{ configurationStrategy };

    return sockAcceptor.Accept(sockStream, sockAddress);
}
