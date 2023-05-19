///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 16:51)

#include "NetworkSockAcceptorTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketEvent.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

Network::NetworkSockAcceptorTesting::NetworkSockAcceptorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NetworkSockAcceptorTesting)

void Network::NetworkSockAcceptorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

namespace Network
{
    using TestingType = SockAcceptor;
}

void Network::NetworkSockAcceptorTesting::MainTest() noexcept
{
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::AcceptorTest);
}

void Network::NetworkSockAcceptorTesting::AcceptorTest()
{
    const std::string networkHostName{ "127.0.0.1" };
    constexpr auto networkPort = 9140 + System::GetEngineeringOffsetValue();

    TestingType sockAcceptor1{ networkPort, GetNetworkServerConfigurationStrategy() };
    TestingType sockAcceptor2{ networkHostName, networkPort, GetNetworkServerConfigurationStrategy() };
}
