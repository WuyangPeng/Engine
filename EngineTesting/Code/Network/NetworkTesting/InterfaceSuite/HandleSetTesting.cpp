///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:57)

#include "HandleSetTesting.h"
#include "SingletonTestingDetail.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/HandleSet.h"

Network::HandleSetTesting::HandleSetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, HandleSetTesting)

void Network::HandleSetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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
    HandleSet handleSet{ GetACEServerConfigurationStrategy() };
}

void Network::HandleSetTesting::BoostConstructionTest()
{
    HandleSet handleSet{ GetBoostServerConfigurationStrategy() };
}

void Network::HandleSetTesting::NetworkConstructionTest()
{
    HandleSet handleSet{ GetNetworkServerConfigurationStrategy() };
}

void Network::HandleSetTesting::NullConstructionTest()
{
    HandleSet handleSet{ GetNullServerConfigurationStrategy() };
}

void Network::HandleSetTesting::ACEHandleTest()
{
    HandleSet handleSet{ GetACEServerConfigurationStrategy() };

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
    HandleSet handleSet{ GetBoostServerConfigurationStrategy() };

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
    HandleSet handleSet{ GetNetworkServerConfigurationStrategy() };

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
    HandleSet handleSet{ GetNullServerConfigurationStrategy() };

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
    HandleSet handleSet{ GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto* fdSet = handleSet.GetFdSet();
}

void Network::HandleSetTesting::NetworkGetFdSetExceptionTest()
{
    HandleSet handleSet{ GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED const auto* fdSet = handleSet.GetFdSet();
}

void Network::HandleSetTesting::NullGetFdSetExceptionTest()
{
    HandleSet handleSet{ GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED const auto* fdSet = handleSet.GetFdSet();
}

void Network::HandleSetTesting::BoostGetACEHandleSetExceptionTest()
{
    const HandleSet handleSet{ GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& aceHandleSet = handleSet.GetACEHandleSet();
}

void Network::HandleSetTesting::NetworkGetACEHandleSetExceptionTest()
{
    const HandleSet handleSet{ GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& aceHandleSet = handleSet.GetACEHandleSet();
}

void Network::HandleSetTesting::NullGetACEHandleSetExceptionTest()
{
    const HandleSet handleSet{ GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& aceHandleSet = handleSet.GetACEHandleSet();
}
