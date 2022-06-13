///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 10:40)

#include "BoostSockAcceptorAsynchronousTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

#include <thread>

using std::make_shared;
using std::thread;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, BoostSockAcceptorAsynchronousTesting)

void Network::BoostSockAcceptorAsynchronousTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::AcceptorTest);
}

void Network::BoostSockAcceptorAsynchronousTesting::AcceptorTest()
{
    thread serverThread{ &ClassType::BoostServerThread, this };

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
    ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousAccept1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousAccept2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousAccept3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousAccept4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousAccept5Test);
    ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousAccept6Test);
}

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAccept1Test()
{
    const auto port = GetRealPort();

    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(port, GetBoostServerConfigurationStrategy(GetRealOffset())) };
    ASSERT_NOT_THROW_EXCEPTION_2(AsynchronousAccept, sockAcceptor, &ClassType::AsynchronousAcceptNoUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAccept2Test()
{
    const auto hostName = GetHostName();
    const auto port = GetRealPort();

    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(hostName, port, GetBoostServerConfigurationStrategy(GetRealOffset())) };
    ASSERT_NOT_THROW_EXCEPTION_2(AsynchronousAccept, sockAcceptor, &ClassType::AsynchronousAcceptNoUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAccept3Test()
{
    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(GetBoostServerConfigurationStrategy(GetRealOffset())) };
    ASSERT_NOT_THROW_EXCEPTION_2(AsynchronousAccept, sockAcceptor, &ClassType::AsynchronousAcceptNoUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAccept4Test()
{
    const auto port = GetRealPort();

    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(port, GetBoostServerConfigurationStrategy(GetRealOffset())) };
    ASSERT_NOT_THROW_EXCEPTION_2(AsynchronousAccept, sockAcceptor, &ClassType::AsynchronousAcceptUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAccept5Test()
{
    const auto hostName = GetHostName();
    const auto port = GetRealPort();

    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(hostName, port, GetBoostServerConfigurationStrategy(GetRealOffset())) };
    ASSERT_NOT_THROW_EXCEPTION_2(AsynchronousAccept, sockAcceptor, &ClassType::AsynchronousAcceptUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAccept6Test()
{
    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(GetBoostServerConfigurationStrategy(GetRealOffset())) };
    ASSERT_NOT_THROW_EXCEPTION_2(AsynchronousAccept, sockAcceptor, &ClassType::AsynchronousAcceptUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAccept(const TestingTypeSharedPtr& sockAcceptor, AcceptFunction acceptFunction)
{
    auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    auto testSocketManager = TestSocketManager::Create(GetMessageID());

    if (acceptFunction != nullptr)
    {
        (this->*acceptFunction)(sockAcceptor, testSocketManager);
    }

    thread clientThread{ &ClassType::ClientThread, this };

    constexpr auto acceptTime = GetAsynchronousAcceptTime();
    for (auto i = 0; i < acceptTime; ++i)
    {
        if (0 < testSocketManager->GetAsyncAcceptorCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, acceptTime);
    }

    clientThread.join();
}

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAcceptNoUseAddress(const TestingTypeSharedPtr& sockAcceptor, const TestSocketManagerSharedPtr& testSocketManager)
{
    auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    SockStreamSharedPtr sockStream{ make_shared<SockStream>(configurationStrategy) };

    sockAcceptor->AsyncAccept(testSocketManager, sockStream);
}

void Network::BoostSockAcceptorAsynchronousTesting::AsynchronousAcceptUseAddress(const TestingTypeSharedPtr& sockAcceptor, const TestSocketManagerSharedPtr& testSocketManager)
{
    auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    SockStreamSharedPtr sockStream{ make_shared<SockStream>(configurationStrategy) };
    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy) };

    sockAcceptor->AsyncAccept(testSocketManager, sockStream, sockAddress);
}

#include STSTEM_WARNING_POP