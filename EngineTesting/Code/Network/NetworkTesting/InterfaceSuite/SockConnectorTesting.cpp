///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/15 10:27)

#include "SingletonTestingDetail.h"
#include "SockConnectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockConnector.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

Network::SockConnectorTesting::SockConnectorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SockConnectorTesting)

void Network::SockConnectorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::SockConnectorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::NetworkTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
}

void Network::SockConnectorTesting::ACETest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ACEConstructionTest);
}

void Network::SockConnectorTesting::BoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostConstructionTest);
}

void Network::SockConnectorTesting::NetworkTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkConstructionTest);
}

void Network::SockConnectorTesting::ACEConstructionTest()
{
    SockConnector connector{ GetACEServerConfigurationStrategy() };
}

void Network::SockConnectorTesting::BoostConstructionTest()
{
    SockConnector connector{ GetBoostServerConfigurationStrategy() };
}

void Network::SockConnectorTesting::NetworkConstructionTest()
{
    SockConnector connector{ GetNetworkServerConfigurationStrategy() };
}

void Network::SockConnectorTesting::NullTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullConstructionTest);
}

void Network::SockConnectorTesting::NullConstructionTest()
{
    SockConnector connector{ GetNullServerConfigurationStrategy() };
}
