///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 17:06)

#include "NetworkSockInetAddressTesting.h"

#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::string;
using std::to_string;

Network::NetworkSockInetAddressTesting::NetworkSockInetAddressTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NetworkSockInetAddressTesting)

void Network::NetworkSockInetAddressTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

namespace Network
{
    using TestingType = SockAddress;
}

void Network::NetworkSockInetAddressTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::AddressTest);
}

void Network::NetworkSockInetAddressTesting::AddressTest()
{
    string hostName{ "127.0.0.1" };
    constexpr uint16_t port{ 8010 };

    TestingType sockAddress{ hostName, port, GetNetworkServerConfigurationStrategy() };

    MAYBE_UNUSED const auto& NetworkInetAddress = sockAddress.GetWinSockInetAddress();

    ASSERT_EQUAL(sockAddress.GetPort(), port);
    ASSERT_EQUAL(sockAddress.GetAddress(), hostName + ":" + to_string(port));
}
