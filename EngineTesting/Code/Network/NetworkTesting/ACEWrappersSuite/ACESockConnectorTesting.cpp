///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 14:21)

#include "ACESockConnectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockConnector.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <thread>

using std::make_shared;
using std::thread;

Network::ACESockConnectorTesting::ACESockConnectorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ACESockConnectorTesting)

void Network::ACESockConnectorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

namespace Network
{
    using TestingType = SockConnector;
}

void Network::ACESockConnectorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ConnectorTest);
}

void Network::ACESockConnectorTesting::ConnectorTest()
{
    ConfigurationStrategy clientConfigurationStrategy{ GetACEServerConfigurationStrategy() };
    TestingType sockConnector{ clientConfigurationStrategy };

    TestSocketManagerSharedPtr socketManager{ make_shared<TestSocketManager>(5) };
    SockStreamSharedPtr sockStream{ make_shared<SockStream>(clientConfigurationStrategy) };
    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(clientConfigurationStrategy.GetHost(), clientConfigurationStrategy.GetPort(), clientConfigurationStrategy) };

    MAYBE_UNUSED const auto value = sockConnector.Connect(sockStream, sockAddress);
    sockConnector.AsyncConnect(socketManager, sockStream, sockAddress);
}
