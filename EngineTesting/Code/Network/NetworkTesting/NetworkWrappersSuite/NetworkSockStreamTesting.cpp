// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:45)

#include "NetworkSockStreamTesting.h" 
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockStream.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockConnector.h"
#include "Network/NetworkMessage/NullMessage.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"

#include <array>
#include <thread>

using std::make_shared;
using std::array;
using std::thread;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, NetworkSockStreamTesting)

namespace Network
{
	using TestingType = SockStream;
}

void Network::NetworkSockStreamTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::StreamTest);
}

void Network::NetworkSockStreamTesting
	::StreamTest()
{
	ConfigurationSubStrategy configurationSubStrategy;

	ConfigurationStrategy clientConfigurationStrategy{ WrappersStrategy::Network, ConnectStrategy::TCP, ClientStrategy::OnlySending,
													   MessageStrategy::Default, ParserStrategy::LittleEndian, OpenSSLStrategy::Default,
													   configurationSubStrategy, ConfigurationParameter{}, SocketSendMessage::Default, "127.0.0.1", 7543 };

	SockStreamSharedPtr sockStream{ make_shared<TestingType>(clientConfigurationStrategy) };
}
