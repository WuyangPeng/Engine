///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 14:13)

#include "BoostSockConnectorAsynchronousTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockConnector.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketEvent.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

#include <thread>

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
    std::thread serverThread{ &ClassType::BoostServerThread, this };

    const auto loopCount = GetTestLoopCount();
    for (auto loop = 0; loop < loopCount; ++loop)
    {
        ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousConnectorTest);
        ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);

        if (constexpr auto resetCount = 10;
            loop % resetCount == (resetCount - 1))
        {
            ASSERT_NOT_THROW_EXCEPTION_0(ClearOffset);
        }
    }

    BASE_MAIN_MANAGER_SINGLETON.StopContext();

    serverThread.join();
}

void Network::BoostSockConnectorAsynchronousTesting::AsynchronousConnectorTest()
{
    std::thread serverThread{ &ClassType::ServerThread, this };

    const auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    const auto testSocketManager = std::make_shared<TestSocketEvent>();

    const auto sockStream = std::make_shared<SockStream>(configurationStrategy);
    const auto sockAddress = make_shared<SockAddress>(configurationStrategy.GetHost(), configurationStrategy.GetPort(), configurationStrategy);

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
