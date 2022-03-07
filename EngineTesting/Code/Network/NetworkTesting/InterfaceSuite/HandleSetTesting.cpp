// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 13:16)

#include "HandleSetTesting.h"
#include "SingletonTestingDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/Interface/HandleSet.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, HandleSet)

void Network::HandleSetTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
    //	ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::NetworkTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
}

void Network::HandleSetTesting ::ACETest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ACEConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ACEHandleTest);
}

void Network::HandleSetTesting ::BoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BoostHandleTest);
    ASSERT_THROW_EXCEPTION_0(BoostGetFdSetExceptionTest);
    ASSERT_THROW_EXCEPTION_0(BoostGetACEHandleSetExceptionTest);
}

void Network::HandleSetTesting ::NetworkTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkHandleTest);
    //ASSERT_THROW_EXCEPTION_0(NetworkGetFdSetExceptionTest);
   // ASSERT_THROW_EXCEPTION_0(NetworkGetACEHandleSetExceptionTest);
}

void Network::HandleSetTesting ::NullTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NullHandleTest);
   // ASSERT_THROW_EXCEPTION_0(NullGetFdSetExceptionTest);
 //   ASSERT_THROW_EXCEPTION_0(NullGetACEHandleSetExceptionTest);
}

void Network::HandleSetTesting ::ACEConstructionTest()
{
    TestingType handleSet{ GetACEServerConfigurationStrategy() };
}

void Network::HandleSetTesting ::BoostConstructionTest()
{
    TestingType handleSet{ GetBoostServerConfigurationStrategy() };
}

void Network::HandleSetTesting ::NetworkConstructionTest()
{
    TestingType handleSet{ GetNetworkServerConfigurationStrategy() };
}

void Network::HandleSetTesting ::NullConstructionTest()
{
    TestingType handleSet{ GetNullServerConfigurationStrategy() };
}

void Network::HandleSetTesting ::ACEHandleTest() noexcept
{
    // 	TestingType handleSet{ GetACEServerConfigurationStrategy() };
    //
    // 	handleSet.SetBit(nullptr);
    // 	handleSet.GetMaxSet();
    // 	handleSet.GetFdSet();
    // 	handleSet.Sync(nullptr);
    // 	handleSet.IsSet(nullptr);
    // 	handleSet.ClearBit(nullptr);
    // 	handleSet.GetACEHandleSet();
    // 	handleSet.IsFdSetFull();
    // 	handleSet.IsFdSetCount();
    // 	handleSet.IsFdSetCountIsOne();
    // 	handleSet.Select(0);
}

void Network::HandleSetTesting ::BoostHandleTest() noexcept
{
    // 	TestingType handleSet{ GetBoostServerConfigurationStrategy() };
    //
    // 	handleSet.SetBit(nullptr);
    // 	handleSet.GetMaxSet();
    // 	handleSet.Sync(nullptr);
    // 	handleSet.IsSet(nullptr);
    // 	handleSet.ClearBit(nullptr);
    // 	handleSet.IsFdSetFull();
    // 	handleSet.IsFdSetCount();
    // 	handleSet.IsFdSetCountIsOne();
    // 	handleSet.Select(0);
}

void Network::HandleSetTesting ::NetworkHandleTest() noexcept
{
    // 	TestingType handleSet{ GetNetworkServerConfigurationStrategy() };
    //
    // 	handleSet.SetBit(nullptr);
    // 	handleSet.GetMaxSet();
    // 	handleSet.Sync(nullptr);
    // 	handleSet.IsSet(nullptr);
    // 	handleSet.ClearBit(nullptr);
    // 	handleSet.IsFdSetFull();
    // 	handleSet.IsFdSetCount();
    // 	handleSet.IsFdSetCountIsOne();
    // 	handleSet.Select(0);
}

void Network::HandleSetTesting ::NullHandleTest() noexcept
{
    // 	TestingType handleSet{ GetNullServerConfigurationStrategy() };
    //
    // 	handleSet.SetBit(nullptr);
    // 	handleSet.GetMaxSet();
    // 	handleSet.Sync(nullptr);
    // 	handleSet.IsSet(nullptr);
    // 	handleSet.ClearBit(nullptr);
    // 	handleSet.IsFdSetFull();
    // 	handleSet.IsFdSetCount();
    // 	handleSet.IsFdSetCountIsOne();
    // 	handleSet.Select(0);
}

void Network::HandleSetTesting ::BoostGetFdSetExceptionTest() noexcept
{
    // 	TestingType handleSet{ GetBoostServerConfigurationStrategy() };
    // 	handleSet.GetFdSet();
}

void Network::HandleSetTesting ::NetworkGetFdSetExceptionTest() noexcept
{
    // 	TestingType handleSet{ GetNetworkServerConfigurationStrategy() };
    // 	handleSet.GetFdSet();
}

void Network::HandleSetTesting ::NullGetFdSetExceptionTest() noexcept
{
    // 	TestingType handleSet{ GetNullServerConfigurationStrategy() };
    // 	handleSet.GetFdSet();
}

void Network::HandleSetTesting ::BoostGetACEHandleSetExceptionTest() noexcept
{
    // 	TestingType handleSet{ GetBoostServerConfigurationStrategy() };
    // 	handleSet.GetACEHandleSet();
}

void Network::HandleSetTesting ::NetworkGetACEHandleSetExceptionTest() noexcept
{
    // 	TestingType handleSet{ GetNetworkServerConfigurationStrategy() };
    // 	handleSet.GetACEHandleSet();
}

void Network::HandleSetTesting ::NullGetACEHandleSetExceptionTest() noexcept
{
    // 	TestingType handleSet{ GetNullServerConfigurationStrategy() };
    // 	handleSet.GetACEHandleSet();
}
