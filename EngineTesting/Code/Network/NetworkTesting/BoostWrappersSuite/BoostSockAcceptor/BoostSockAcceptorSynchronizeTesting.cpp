///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 11:04)

#include "BoostSockAcceptorSynchronizeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/Client.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <thread>

using std::make_shared;
using std::thread;

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
    thread serverThread{ &ClassType::BoostServerThread, this };

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
    ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAccept1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAccept2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAccept3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAccept4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAccept5Test);
    ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAccept6Test);
}

void Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAccept1Test()
{
    const auto port = GetRealPort();

    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(port, GetBoostServerConfigurationStrategy(GetRealOffset())) };
    ASSERT_NOT_THROW_EXCEPTION_2(SynchronizeAccept, sockAcceptor, &ClassType::SynchronizeAcceptNoUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAccept2Test()
{
    const auto hostName = GetHostName();
    const auto port = GetRealPort();

    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(hostName, port, GetBoostServerConfigurationStrategy(GetRealOffset())) };
    ASSERT_NOT_THROW_EXCEPTION_2(SynchronizeAccept, sockAcceptor, &ClassType::SynchronizeAcceptNoUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAccept3Test()
{
    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(GetBoostServerConfigurationStrategy(GetRealOffset())) };
    ASSERT_NOT_THROW_EXCEPTION_2(SynchronizeAccept, sockAcceptor, &ClassType::SynchronizeAcceptNoUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAccept4Test()
{
    const auto port = GetRealPort();

    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(port, GetBoostServerConfigurationStrategy(GetRealOffset())) };
    ASSERT_NOT_THROW_EXCEPTION_2(SynchronizeAccept, sockAcceptor, &ClassType::SynchronizeAcceptUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAccept5Test()
{
    const auto hostName = GetHostName();
    const auto port = GetRealPort();

    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(hostName, port, GetBoostServerConfigurationStrategy(GetRealOffset())) };
    ASSERT_NOT_THROW_EXCEPTION_2(SynchronizeAccept, sockAcceptor, &ClassType::SynchronizeAcceptUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAccept6Test()
{
    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(GetBoostServerConfigurationStrategy(GetRealOffset())) };
    ASSERT_NOT_THROW_EXCEPTION_2(SynchronizeAccept, sockAcceptor, &ClassType::SynchronizeAcceptUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAccept(const TestingTypeSharedPtr& sockAcceptor, AcceptFunction acceptFunction)
{
    thread clientThread{ &ClassType::ClientThread, this };

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

bool Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAcceptNoUseAddress(const TestingTypeSharedPtr& sockAcceptor)
{
    auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    SockStreamSharedPtr sockStream{ make_shared<SockStream>(configurationStrategy) };

    return sockAcceptor->Accept(*sockStream);
}

bool Network::BoostSockAcceptorSynchronizeTesting::SynchronizeAcceptUseAddress(const TestingTypeSharedPtr& sockAcceptor)
{
    auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    SockStreamSharedPtr sockStream{ make_shared<SockStream>(configurationStrategy) };
    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy) };

    return sockAcceptor->Accept(*sockStream, *sockAddress);
}

#include STSTEM_WARNING_POP