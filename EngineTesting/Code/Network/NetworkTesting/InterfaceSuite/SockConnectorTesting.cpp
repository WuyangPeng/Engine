///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 15:26)

#include "SingletonTestingDetail.h"
#include "SockConnectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockConnector.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, SockConnector)

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
    TestingType connector{ GetACEServerConfigurationStrategy() };
}

void Network::SockConnectorTesting::BoostConstructionTest()
{
    TestingType connector{ GetBoostServerConfigurationStrategy() };
}

void Network::SockConnectorTesting::NetworkConstructionTest()
{
    TestingType connector{ GetNetworkServerConfigurationStrategy() };
}

void Network::SockConnectorTesting::NullTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullConstructionTest);
}

void Network::SockConnectorTesting::NullConstructionTest()
{
    TestingType connector{ GetNullServerConfigurationStrategy() };
}
