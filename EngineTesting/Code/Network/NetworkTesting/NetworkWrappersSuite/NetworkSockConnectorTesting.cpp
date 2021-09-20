// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:44)

#include "NetworkSockConnectorTesting.h" 
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockStream.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockConnector.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"

using std::string;
using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, NetworkSockConnectorTesting)

namespace Network
{
	using TestingType = SockConnector;
}

void Network::NetworkSockConnectorTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::ConnectorTest);
}

void Network::NetworkSockConnectorTesting
	::ConnectorTest()
{
	ConfigurationStrategy clientConfigurationStrategy{ GetACEServerConfigurationStrategy() };
	TestingType sockConnector{ clientConfigurationStrategy };
}

