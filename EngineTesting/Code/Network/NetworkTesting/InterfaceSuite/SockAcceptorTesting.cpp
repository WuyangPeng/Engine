///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/15 10:23)

#include "SingletonTestingDetail.h"
#include "SockAcceptorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAcceptor.h"

namespace Network
{
    using TestingType = SockAcceptor;
}

Network::SockAcceptorTesting::SockAcceptorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SockAcceptorTesting)

void Network::SockAcceptorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::SockAcceptorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::NetworkTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
}

void Network::SockAcceptorTesting::ACETest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ACEConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ACEGetACEHandleTest);
    ASSERT_THROW_EXCEPTION_0(ACEGetBoostHandleExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ACEGetNetworkHandleExceptionTest);
}

void Network::SockAcceptorTesting::BoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostConstructionTest);
    ASSERT_THROW_EXCEPTION_0(BoostGetACEHandleExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BoostGetBoostHandleTest);
    ASSERT_THROW_EXCEPTION_0(BoostGetNetworkHandleExceptionTest);
}

void Network::SockAcceptorTesting::NetworkTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkConstructionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkGetACEHandleExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkGetBoostHandleExceptionTest);
}

void Network::SockAcceptorTesting::ACEConstructionTest()
{
    const TestingType sockAcceptor0{ "127.0.0.1", GetShiftingPort(20), GetACEServerConfigurationStrategy() };
    const TestingType sockAcceptor1{ GetShiftingPort(30), GetACEServerConfigurationStrategy() };
}

void Network::SockAcceptorTesting::BoostConstructionTest()
{
    const TestingType sockAcceptor0{ GetShiftingPort(30), GetBoostServerConfigurationStrategy() };
    const TestingType sockAcceptor1{ "127.0.0.1", GetShiftingPort(20), GetBoostServerConfigurationStrategy() };
}

void Network::SockAcceptorTesting::NetworkConstructionTest()
{
    const TestingType sockAcceptor0{ GetShiftingPort(30), GetNetworkServerConfigurationStrategy() };
    const TestingType sockAcceptor1{ "127.0.0.1", GetShiftingPort(20), GetNetworkServerConfigurationStrategy() };
}

void Network::SockAcceptorTesting::ACEGetACEHandleTest()
{
    TestingType sockAcceptor{ "127.0.0.1", GetShiftingPort(20), GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetACEHandle();
}

void Network::SockAcceptorTesting::ACEGetBoostHandleExceptionTest()
{
    TestingType sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetBoostHandle();
}

void Network::SockAcceptorTesting::ACEGetNetworkHandleExceptionTest()
{
    TestingType sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetWinSocket();
}

void Network::SockAcceptorTesting::BoostGetACEHandleExceptionTest()
{
    TestingType sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetACEHandle();
}

void Network::SockAcceptorTesting::BoostGetBoostHandleTest()
{
    TestingType sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetBoostHandle();
}

void Network::SockAcceptorTesting::BoostGetNetworkHandleExceptionTest()
{
    TestingType sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetWinSocket();
}

void Network::SockAcceptorTesting::NetworkGetACEHandleExceptionTest()
{
    TestingType sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetACEHandle();
}

void Network::SockAcceptorTesting::NetworkGetBoostHandleExceptionTest()
{
    TestingType sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetBoostHandle();
}

void Network::SockAcceptorTesting::NullTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullConstructionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetACEHandleExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetBoostHandleExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetNetworkHandleExceptionTest);
}

void Network::SockAcceptorTesting::NullGetACEHandleExceptionTest()
{
    TestingType sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetACEHandle();
}

void Network::SockAcceptorTesting::NullGetBoostHandleExceptionTest()
{
    TestingType sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetBoostHandle();
}

void Network::SockAcceptorTesting::NullGetNetworkHandleExceptionTest()
{
    TestingType sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetWinSocket();
}

void Network::SockAcceptorTesting::NullConstructionTest()
{
    TestingType sockAcceptor0{ "127.0.0.1", GetShiftingPort(0), GetNullServerConfigurationStrategy() };
    TestingType sockAcceptor1{ GetShiftingPort(10), GetNullServerConfigurationStrategy() };
}
