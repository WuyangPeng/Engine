// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:25)

#include "BoostSockAcceptorHandleTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

using std::make_shared;
using std::to_string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, BoostSockAcceptorHandleTesting)

void Network::BoostSockAcceptorHandleTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::AcceptorTest);
}

void Network::BoostSockAcceptorHandleTesting ::AcceptorTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AcceptorInformationTest);
    ASSERT_THROW_EXCEPTION_0(ACEHandleExceptionTest);
    ASSERT_THROW_EXCEPTION_0(WinSocketExceptionTest);
}

void Network::BoostSockAcceptorHandleTesting ::AcceptorInformationTest()
{
    const auto hostName = GetHostName();
    const auto port = GetPort();

    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(GetBoostServerConfigurationStrategy()) };

    ASSERT_EQUAL(sockAcceptor->GetAddress(), hostName + ":" + to_string(port));
    ASSERT_EQUAL(sockAcceptor->GetPort(), port);

    auto nativeHandle = sockAcceptor->GetBoostHandle();

    ASSERT_TRUE(nativeHandle);
}

void Network::BoostSockAcceptorHandleTesting ::ACEHandleExceptionTest()
{
    const auto hostName = GetHostName();
    const auto port = GetPort();

    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(GetBoostServerConfigurationStrategy()) };

    [[maybe_unused]] auto value = sockAcceptor->GetACEHandle();
}

void Network::BoostSockAcceptorHandleTesting ::WinSocketExceptionTest()
{
    const auto hostName = GetHostName();
    const auto port = GetPort();

    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(GetBoostServerConfigurationStrategy()) };

    [[maybe_unused]] auto value = sockAcceptor->GetWinSocket();
}
