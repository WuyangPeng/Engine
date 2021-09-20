// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:44)

#include "NetworkSockAcceptorTesting.h" 
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"

using std::string;
using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, NetworkSockAcceptorTesting)

namespace Network
{
	using TestingType = SockAcceptor;
}

void Network::NetworkSockAcceptorTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::AcceptorTest);
}

void Network::NetworkSockAcceptorTesting
	::AcceptorTest()
{
	string hostName{ "127.0.0.1" };
	uint16_t port{ 9140 };

	TestingType sockAcceptor1{ port,GetNetworkServerConfigurationStrategy() };
	TestingType sockAcceptor2{ hostName,port,GetNetworkServerConfigurationStrategy() };
}

