///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 10:54)

#include "ACESockAcceptorTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketEvent.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

Network::ACESockAcceptorTesting::ACESockAcceptorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ACESockAcceptorTesting)

void Network::ACESockAcceptorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::ACESockAcceptorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::AcceptorTest);
}

void Network::ACESockAcceptorTesting::AcceptorTest()
{
    const std::string aceHostName{ "127.0.0.1" };
    constexpr auto acePort = 9120 + System::GetEngineeringOffsetValue();

    SockAcceptor sockAcceptor0{ acePort - 1, GetACEServerConfigurationStrategy() };
    SockAcceptor sockAcceptor1{ aceHostName, acePort + 9, GetACEServerConfigurationStrategy() };

    const auto sockStream = std::make_shared<SockStream>(GetACEServerConfigurationStrategy());
    const auto sockAddress = std::make_shared<SockAddress>(GetACEServerConfigurationStrategy());
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();

    auto enableNonBlock = sockAcceptor0.EnableNonBlock();

    auto result = sockAcceptor0.Accept(*sockStream);
    result = sockAcceptor0.Accept(*sockStream, *sockAddress);
    sockAcceptor0.AsyncAccept(testSocketEvent, sockStream, sockAddress);
    sockAcceptor0.AsyncAccept(testSocketEvent, sockStream);

    enableNonBlock = sockAcceptor1.EnableNonBlock();

    result = sockAcceptor1.Accept(*sockStream);
    result = sockAcceptor1.Accept(*sockStream, *sockAddress);
    sockAcceptor1.AsyncAccept(testSocketEvent, sockStream, sockAddress);
    sockAcceptor1.AsyncAccept(testSocketEvent, sockStream);
}
