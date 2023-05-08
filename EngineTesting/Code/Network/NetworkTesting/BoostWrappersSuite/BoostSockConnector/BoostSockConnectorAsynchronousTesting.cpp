///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 11:09)

#include "BoostSockConnectorAsynchronousTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockConnector.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <thread>

using std::make_shared;
using std::thread;

Network::BoostSockConnectorAsynchronousTesting::BoostSockConnectorAsynchronousTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockConnectorAsynchronousTesting)

void Network::BoostSockConnectorAsynchronousTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BoostSockConnectorAsynchronousTesting::MainTest() noexcept
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::ConnectorTest);
}

void Network::BoostSockConnectorAsynchronousTesting::ConnectorTest()
{
    thread serverThread{ &ClassType::BoostServerThread, this };
    constexpr auto resetCount = 10;

    const auto loopCount = GetTestLoopCount();
    for (auto loop = 0; loop < loopCount; ++loop)
    {
        ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousConnectorTest);
        ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
        if (loop % resetCount == (resetCount - 1))
        {
            ASSERT_NOT_THROW_EXCEPTION_0(ClearOffset);
        }
    }

    BASE_MAIN_MANAGER_SINGLETON.StopContext();

    serverThread.join();
}

void Network::BoostSockConnectorAsynchronousTesting::AsynchronousConnectorTest()
{
    thread serverThread{ &ClassType::ServerThread, this };

    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };

    SockStreamSharedPtr sockStream{ make_shared<SockStream>(configurationStrategy) };
    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy.GetHost(), configurationStrategy.GetPort(), configurationStrategy) };

    TestingType sockConnector{ configurationStrategy };
    sockConnector.AsyncConnect(testSocketManager, sockStream, sockAddress);

    constexpr auto connectTime = GetAsynchronousConnectTime();
    for (auto i = 0; i < connectTime; ++i)
    {
        if (0 < testSocketManager->GetAsyncConnectCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, connectTime);
    }

    serverThread.join();
}
