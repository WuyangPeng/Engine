// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:45)

#include "NetworkSockInetAddressTesting.h"

#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

using std::string;
using std::to_string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, NetworkSockInetAddressTesting)

namespace Network
{
    using TestingType = SockAddress;
}

void Network::NetworkSockInetAddressTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::AddressTest);
}

void Network::NetworkSockInetAddressTesting ::AddressTest()
{
    string hostName{ "127.0.0.1" };
    constexpr uint16_t port{ 8010 };

    TestingType sockAddress{ hostName, port, GetNetworkServerConfigurationStrategy() };

    [[maybe_unused]] const auto& NetworkInetAddress = sockAddress.GetWinSockInetAddress();

    ASSERT_EQUAL(sockAddress.GetPort(), port);
    ASSERT_EQUAL(sockAddress.GetAddress(), hostName + ":" + to_string(port));
}
