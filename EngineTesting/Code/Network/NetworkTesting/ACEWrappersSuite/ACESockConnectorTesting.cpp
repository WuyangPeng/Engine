///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 10:54)

#include "ACESockConnectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockConnector.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketEvent.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

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

void Network::ACESockConnectorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ConnectorTest);
}

void Network::ACESockConnectorTesting::ConnectorTest()
{
    auto clientConfigurationStrategy = GetACEServerConfigurationStrategy();
    SockConnector sockConnector{ clientConfigurationStrategy };

    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    const auto sockStream = std::make_shared<SockStream>(clientConfigurationStrategy);
    const auto sockAddress = make_shared<SockAddress>(clientConfigurationStrategy.GetHost(), clientConfigurationStrategy.GetPort(), clientConfigurationStrategy);

    MAYBE_UNUSED const auto result = sockConnector.Connect(sockStream, sockAddress);
    sockConnector.AsyncConnect(testSocketEvent, sockStream, sockAddress);
}
