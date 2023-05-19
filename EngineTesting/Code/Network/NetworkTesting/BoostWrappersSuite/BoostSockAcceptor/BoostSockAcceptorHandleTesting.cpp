///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 13:44)

#include "BoostSockAcceptorHandleTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

Network::BoostSockAcceptorHandleTesting::BoostSockAcceptorHandleTesting(const OStreamShared& stream)
    : ParentType{ stream }, increase{ 1234 }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockAcceptorHandleTesting)

void Network::BoostSockAcceptorHandleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BoostSockAcceptorHandleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::AcceptorTest);
}

void Network::BoostSockAcceptorHandleTesting::AcceptorTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AcceptorInformationTest);
    ASSERT_THROW_EXCEPTION_0(ACEHandleExceptionTest);
    ASSERT_THROW_EXCEPTION_0(WinSocketExceptionTest);
}

void Network::BoostSockAcceptorHandleTesting::AcceptorInformationTest()
{
    TestingType sockAcceptor{ GetBoostServerConfigurationStrategy(increase) };

    ASSERT_EQUAL(sockAcceptor.GetAddress(), GetHostName() + ":" + std::to_string(GetPort() + increase));
    ASSERT_EQUAL(sockAcceptor.GetPort(), GetPort() + increase);

    const auto nativeHandle = sockAcceptor.GetBoostHandle();

    ASSERT_TRUE(nativeHandle);
}

void Network::BoostSockAcceptorHandleTesting::ACEHandleExceptionTest()
{
    TestingType sockAcceptor{ GetBoostServerConfigurationStrategy() };

    MAYBE_UNUSED const auto result = sockAcceptor.GetACEHandle();
}

void Network::BoostSockAcceptorHandleTesting::WinSocketExceptionTest()
{
    TestingType sockAcceptor{ GetBoostServerConfigurationStrategy() };

    MAYBE_UNUSED const auto result = sockAcceptor.GetWinSocket();
}
