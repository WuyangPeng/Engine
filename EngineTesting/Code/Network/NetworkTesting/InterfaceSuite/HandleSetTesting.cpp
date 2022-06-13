///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 14:23)

#include "HandleSetTesting.h"
#include "SingletonTestingDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/Interface/HandleSet.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, HandleSet)

void Network::HandleSetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::NetworkTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
}

void Network::HandleSetTesting::ACETest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ACEConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ACEHandleTest);
}

void Network::HandleSetTesting::BoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BoostHandleTest);
    ASSERT_THROW_EXCEPTION_0(BoostGetFdSetExceptionTest);
    ASSERT_THROW_EXCEPTION_0(BoostGetACEHandleSetExceptionTest);
}

void Network::HandleSetTesting::NetworkTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkHandleTest);
    ASSERT_THROW_EXCEPTION_0(NetworkGetFdSetExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkGetACEHandleSetExceptionTest);
}

void Network::HandleSetTesting::NullTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NullHandleTest);
    ASSERT_THROW_EXCEPTION_0(NullGetFdSetExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetACEHandleSetExceptionTest);
}

void Network::HandleSetTesting::ACEConstructionTest()
{
    TestingType handleSet{ GetACEServerConfigurationStrategy() };
}

void Network::HandleSetTesting::BoostConstructionTest()
{
    TestingType handleSet{ GetBoostServerConfigurationStrategy() };
}

void Network::HandleSetTesting::NetworkConstructionTest()
{
    TestingType handleSet{ GetNetworkServerConfigurationStrategy() };
}

void Network::HandleSetTesting::NullConstructionTest()
{
    TestingType handleSet{ GetNullServerConfigurationStrategy() };
}

void Network::HandleSetTesting::ACEHandleTest()
{
    TestingType handleSet{ GetACEServerConfigurationStrategy() };

    handleSet.SetBit(nullptr);
    MAYBE_UNUSED const auto maxSet = handleSet.GetMaxSet();
    MAYBE_UNUSED const auto* fdSet = handleSet.GetFdSet();
    handleSet.Sync(nullptr);
    MAYBE_UNUSED const auto isSet = handleSet.IsSet(nullptr);
    handleSet.ClearBit(nullptr);
    MAYBE_UNUSED const auto& aceHandleSet = handleSet.GetACEHandleSet();
    MAYBE_UNUSED const auto isFdSetFull = handleSet.IsFdSetFull();
    MAYBE_UNUSED const auto isFdSetCount = handleSet.IsFdSetCount();
    MAYBE_UNUSED const auto isFdSetCountIsOne = handleSet.IsFdSetCountIsOne();
    MAYBE_UNUSED const auto select = handleSet.Select(0);
}

void Network::HandleSetTesting::BoostHandleTest()
{
    TestingType handleSet{ GetBoostServerConfigurationStrategy() };

    handleSet.SetBit(nullptr);
    MAYBE_UNUSED const auto maxSet = handleSet.GetMaxSet();
    handleSet.Sync(nullptr);
    MAYBE_UNUSED const auto isSet = handleSet.IsSet(nullptr);
    handleSet.ClearBit(nullptr);
    MAYBE_UNUSED const auto isFdSetFull = handleSet.IsFdSetFull();
    MAYBE_UNUSED const auto isFdSetCount = handleSet.IsFdSetCount();
    MAYBE_UNUSED const auto isFdSetCountIsOne = handleSet.IsFdSetCountIsOne();
    MAYBE_UNUSED const auto select = handleSet.Select(0);
}

void Network::HandleSetTesting::NetworkHandleTest()
{
    TestingType handleSet{ GetNetworkServerConfigurationStrategy() };

    handleSet.SetBit(nullptr);
    MAYBE_UNUSED const auto maxSet = handleSet.GetMaxSet();
    handleSet.Sync(nullptr);
    MAYBE_UNUSED const auto isSet = handleSet.IsSet(nullptr);
    handleSet.ClearBit(nullptr);
    MAYBE_UNUSED const auto isFdSetFull = handleSet.IsFdSetFull();
    MAYBE_UNUSED const auto isFdSetCount = handleSet.IsFdSetCount();
    MAYBE_UNUSED const auto isFdSetCountIsOne = handleSet.IsFdSetCountIsOne();
    MAYBE_UNUSED const auto select = handleSet.Select(0);
}

void Network::HandleSetTesting::NullHandleTest()
{
    TestingType handleSet{ GetNullServerConfigurationStrategy() };

    handleSet.SetBit(nullptr);
    MAYBE_UNUSED const auto maxSet = handleSet.GetMaxSet();
    handleSet.Sync(nullptr);
    MAYBE_UNUSED const auto isSet = handleSet.IsSet(nullptr);
    handleSet.ClearBit(nullptr);
    MAYBE_UNUSED const auto isFdSetFull = handleSet.IsFdSetFull();
    MAYBE_UNUSED const auto isFdSetCount = handleSet.IsFdSetCount();
    MAYBE_UNUSED const auto isFdSetCountIsOne = handleSet.IsFdSetCountIsOne();
    MAYBE_UNUSED const auto select = handleSet.Select(0);
}

void Network::HandleSetTesting::BoostGetFdSetExceptionTest()
{
    TestingType handleSet{ GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto* fdSet = handleSet.GetFdSet();
}

void Network::HandleSetTesting::NetworkGetFdSetExceptionTest()
{
    TestingType handleSet{ GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED const auto* fdSet = handleSet.GetFdSet();
}

void Network::HandleSetTesting::NullGetFdSetExceptionTest()
{
    TestingType handleSet{ GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED const auto* fdSet = handleSet.GetFdSet();
}

void Network::HandleSetTesting::BoostGetACEHandleSetExceptionTest()
{
    TestingType handleSet{ GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& aceHandleSet = handleSet.GetACEHandleSet();
}

void Network::HandleSetTesting::NetworkGetACEHandleSetExceptionTest()
{
    TestingType handleSet{ GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& aceHandleSet = handleSet.GetACEHandleSet();
}

void Network::HandleSetTesting::NullGetACEHandleSetExceptionTest()
{
    TestingType handleSet{ GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& aceHandleSet = handleSet.GetACEHandleSet();
}
