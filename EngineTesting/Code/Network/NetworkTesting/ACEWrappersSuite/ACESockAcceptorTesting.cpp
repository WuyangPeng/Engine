///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 09:42)

#include "ACESockAcceptorTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Helper/UserMacro.h"
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

    SockAcceptor sockAcceptor1{ acePort - 1, GetACEServerConfigurationStrategy() };
    SockAcceptor sockAcceptor2{ aceHostName, acePort + 9, GetACEServerConfigurationStrategy() };

    const auto sockStream = std::make_shared<SockStream>(GetACEServerConfigurationStrategy());
    const auto sockAddress = std::make_shared<SockAddress>(GetACEServerConfigurationStrategy());
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();

    auto enableNonBlock = sockAcceptor1.EnableNonBlock();

    auto result = sockAcceptor1.Accept(*sockStream);
    result = sockAcceptor1.Accept(*sockStream, *sockAddress);
    sockAcceptor1.AsyncAccept(testSocketEvent, sockStream, sockAddress);
    sockAcceptor1.AsyncAccept(testSocketEvent, sockStream);

    enableNonBlock = sockAcceptor2.EnableNonBlock();

    result = sockAcceptor2.Accept(*sockStream);
    result = sockAcceptor2.Accept(*sockStream, *sockAddress);
    sockAcceptor2.AsyncAccept(testSocketEvent, sockStream, sockAddress);
    sockAcceptor2.AsyncAccept(testSocketEvent, sockStream);
}
