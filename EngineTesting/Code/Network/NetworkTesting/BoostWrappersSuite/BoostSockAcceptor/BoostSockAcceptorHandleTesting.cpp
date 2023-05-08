///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 10:54)

#include "BoostSockAcceptorHandleTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::make_shared;
using std::to_string;

Network::BoostSockAcceptorHandleTesting::BoostSockAcceptorHandleTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    const auto hostName = GetHostName();
    const auto port = GetPort();

    TestingType sockAcceptor{ GetBoostServerConfigurationStrategy() };

    ASSERT_EQUAL(sockAcceptor.GetAddress(), hostName + ":" + to_string(port));
    ASSERT_EQUAL(sockAcceptor.GetPort(), port);

    const auto nativeHandle = sockAcceptor.GetBoostHandle();

    ASSERT_TRUE(nativeHandle);
}

void Network::BoostSockAcceptorHandleTesting::ACEHandleExceptionTest()
{
    const auto hostName = GetHostName();
    const auto port = GetPort();

    TestingType sockAcceptor{ GetBoostServerConfigurationStrategy() };

    MAYBE_UNUSED auto value = sockAcceptor.GetACEHandle();
}

void Network::BoostSockAcceptorHandleTesting::WinSocketExceptionTest()
{
    const auto hostName = GetHostName();
    const auto port = GetPort();

    TestingType sockAcceptor{ GetBoostServerConfigurationStrategy() };

    MAYBE_UNUSED const auto value = sockAcceptor.GetWinSocket();
}
