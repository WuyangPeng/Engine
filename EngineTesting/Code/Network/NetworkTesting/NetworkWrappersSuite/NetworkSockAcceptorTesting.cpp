///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 16:59)

#include "NetworkSockAcceptorTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::make_shared;
using std::string;
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
    string hostName{ "127.0.0.1" };
    const auto aPort = boost::numeric_cast<uint16_t>(9140 + System::GetEngineeringOffsetValue());

    TestingType sockAcceptor1{ aPort, GetNetworkServerConfigurationStrategy() };
    TestingType sockAcceptor2{ hostName, aPort, GetNetworkServerConfigurationStrategy() };
}
