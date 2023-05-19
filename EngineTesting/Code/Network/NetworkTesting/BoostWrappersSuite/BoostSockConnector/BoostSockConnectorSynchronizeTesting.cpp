///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 14:23)

#include "BoostSockConnectorSynchronizeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockConnector.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

#include <thread>

Network::BoostSockConnectorSynchronizeTesting::BoostSockConnectorSynchronizeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockConnectorSynchronizeTesting)

void Network::BoostSockConnectorSynchronizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BoostSockConnectorSynchronizeTesting::MainTest() noexcept
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::ConnectorTest);
}

void Network::BoostSockConnectorSynchronizeTesting::ConnectorTest()
{
    std::thread serverThread{ &ClassType::BoostServerThread, this };

    const auto loopCount = GetTestLoopCount();
    for (auto loop = 0; loop < loopCount; ++loop)
    {
        ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeConnectorTest);
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

void Network::BoostSockConnectorSynchronizeTesting::SynchronizeConnectorTest()
{
    std::thread serverThread{ &ClassType::ServerThread, this };

    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    const auto sockStream = std::make_shared<SockStream>(configurationStrategy);
    const auto sockAddress = make_shared<SockAddress>(configurationStrategy.GetHost(), configurationStrategy.GetPort(), configurationStrategy);

    TestingType sockConnector{ configurationStrategy };

    constexpr auto connectTime = GetSynchronizeConnectTime();
    for (auto i = 0; i < connectTime; ++i)
    {
        if (sockConnector.Connect(sockStream, sockAddress))
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, connectTime);
    }

    serverThread.join();
}
