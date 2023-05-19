///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 16:53)

#include "NetworkSockInternetAddressTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

Network::NetworkSockInternetAddressTesting::NetworkSockInternetAddressTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NetworkSockInternetAddressTesting)

void Network::NetworkSockInternetAddressTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

namespace Network
{
    using TestingType = SockAddress;
}

void Network::NetworkSockInternetAddressTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::AddressTest);
}

void Network::NetworkSockInternetAddressTesting::AddressTest()
{
    const std::string networkHostName{ "127.0.0.1" };
    constexpr auto networkPort = 8010;

    TestingType sockAddress{ networkHostName, networkPort, GetNetworkServerConfigurationStrategy() };

    MAYBE_UNUSED const auto& networkInternetAddress = sockAddress.GetWinSockInternetAddress();

    ASSERT_EQUAL(sockAddress.GetPort(), networkPort);
    ASSERT_EQUAL(sockAddress.GetAddress(), networkHostName + ":" + std::to_string(networkPort));
}
