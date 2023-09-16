///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:57)

#include "SingletonTestingDetail.h"
#include "SockAcceptorTesting.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAcceptor.h"

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
    const SockAcceptor sockAcceptor0{ "127.0.0.1", GetShiftingPort(20), GetACEServerConfigurationStrategy() };
    const SockAcceptor sockAcceptor1{ GetShiftingPort(30), GetACEServerConfigurationStrategy() };
}

void Network::SockAcceptorTesting::BoostConstructionTest()
{
    const SockAcceptor sockAcceptor0{ GetShiftingPort(30), GetBoostServerConfigurationStrategy() };
    const SockAcceptor sockAcceptor1{ "127.0.0.1", GetShiftingPort(20), GetBoostServerConfigurationStrategy() };
}

void Network::SockAcceptorTesting::NetworkConstructionTest()
{
    const SockAcceptor sockAcceptor0{ GetShiftingPort(30), GetNetworkServerConfigurationStrategy() };
    const SockAcceptor sockAcceptor1{ "127.0.0.1", GetShiftingPort(20), GetNetworkServerConfigurationStrategy() };
}

void Network::SockAcceptorTesting::ACEGetACEHandleTest()
{
    SockAcceptor sockAcceptor{ "127.0.0.1", GetShiftingPort(20), GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetACEHandle();
}

void Network::SockAcceptorTesting::ACEGetBoostHandleExceptionTest()
{
    SockAcceptor sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetBoostHandle();
}

void Network::SockAcceptorTesting::ACEGetNetworkHandleExceptionTest()
{
    SockAcceptor sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetWinSocket();
}

void Network::SockAcceptorTesting::BoostGetACEHandleExceptionTest()
{
    SockAcceptor sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetACEHandle();
}

void Network::SockAcceptorTesting::BoostGetBoostHandleTest()
{
    SockAcceptor sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetBoostHandle();
}

void Network::SockAcceptorTesting::BoostGetNetworkHandleExceptionTest()
{
    SockAcceptor sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetWinSocket();
}

void Network::SockAcceptorTesting::NetworkGetACEHandleExceptionTest()
{
    SockAcceptor sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetACEHandle();
}

void Network::SockAcceptorTesting::NetworkGetBoostHandleExceptionTest()
{
    SockAcceptor sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetNetworkServerConfigurationStrategy() };
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
    SockAcceptor sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetACEHandle();
}

void Network::SockAcceptorTesting::NullGetBoostHandleExceptionTest()
{
    SockAcceptor sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetBoostHandle();
}

void Network::SockAcceptorTesting::NullGetNetworkHandleExceptionTest()
{
    SockAcceptor sockAcceptor{ "127.0.0.1", GetShiftingPort(0), GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED const auto result = sockAcceptor.GetWinSocket();
}

void Network::SockAcceptorTesting::NullConstructionTest()
{
    SockAcceptor sockAcceptor0{ "127.0.0.1", GetShiftingPort(0), GetNullServerConfigurationStrategy() };
    SockAcceptor sockAcceptor1{ GetShiftingPort(10), GetNullServerConfigurationStrategy() };
}
