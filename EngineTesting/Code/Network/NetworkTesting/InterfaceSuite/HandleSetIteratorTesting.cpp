///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 14:22)

#include "HandleSetIteratorTesting.h"
#include "SingletonTestingDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/Interface/HandleSet.h"
#include "Network/Interface/HandleSetIterator.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, HandleSetIterator)

void Network::HandleSetIteratorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::NetworkTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
}

void Network::HandleSetIteratorTesting::ACETest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ACEConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ACEOperatorTest);
}

void Network::HandleSetIteratorTesting::BoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostConstructionTest);
    ASSERT_THROW_EXCEPTION_0(BoostOperatorExceptionTest);
}

void Network::HandleSetIteratorTesting::NetworkTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkConstructionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkOperatorExceptionTest);
}

void Network::HandleSetIteratorTesting::NullTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullConstructionTest);
    ASSERT_THROW_EXCEPTION_0(NullOperatorExceptionTest);
}

void Network::HandleSetIteratorTesting::ACEConstructionTest()
{
    TestingType handleSetIterator{ GetACEServerConfigurationStrategy(), HandleSet(GetACEServerConfigurationStrategy()) };
}

void Network::HandleSetIteratorTesting::BoostConstructionTest()
{
    TestingType handleSetIterator{ GetBoostServerConfigurationStrategy(), HandleSet(GetBoostServerConfigurationStrategy()) };
}

void Network::HandleSetIteratorTesting::NetworkConstructionTest()
{
    TestingType handleSetIterator{ GetNetworkServerConfigurationStrategy(), HandleSet(GetNetworkServerConfigurationStrategy()) };
}

void Network::HandleSetIteratorTesting::NullConstructionTest()
{
    TestingType handleSetIterator{ GetNullServerConfigurationStrategy(), HandleSet(GetNullServerConfigurationStrategy()) };
}

void Network::HandleSetIteratorTesting::ACEOperatorTest()
{
    TestingType handleSetIterator{ GetACEServerConfigurationStrategy(), HandleSet(GetACEServerConfigurationStrategy()) };
    MAYBE_UNUSED auto value = handleSetIterator.operator()();
}

void Network::HandleSetIteratorTesting::BoostOperatorExceptionTest()
{
    TestingType handleSetIterator{ GetBoostServerConfigurationStrategy(), HandleSet(GetBoostServerConfigurationStrategy()) };
    MAYBE_UNUSED auto value = handleSetIterator.operator()();
}

void Network::HandleSetIteratorTesting::NetworkOperatorExceptionTest()
{
    TestingType handleSetIterator{ GetNetworkServerConfigurationStrategy(), HandleSet(GetNetworkServerConfigurationStrategy()) };
    MAYBE_UNUSED auto value = handleSetIterator.operator()();
}

void Network::HandleSetIteratorTesting::NullOperatorExceptionTest()
{
    TestingType handleSetIterator{ GetNullServerConfigurationStrategy(), HandleSet(GetNullServerConfigurationStrategy()) };
    MAYBE_UNUSED auto value = handleSetIterator.operator()();
}
