// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:11)

#include "ACESockInetAddressTesting.h" 
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

using std::string;
using std::to_string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, ACESockInetAddressTesting)

namespace Network
{
	using TestingType = SockAddress;
}

void Network::ACESockInetAddressTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::AddressTest);
}

void Network::ACESockInetAddressTesting
	::AddressTest()
{
	string hostName{ "127.0.0.1" };
	uint16_t port{ 7300 };

	TestingType sockAddress{ hostName, port, GetBoostServerConfigurationStrategy() };

	ASSERT_EQUAL(sockAddress.GetPort(), port);
	ASSERT_EQUAL(sockAddress.GetAddress(), hostName + ":" + to_string(port));
}

