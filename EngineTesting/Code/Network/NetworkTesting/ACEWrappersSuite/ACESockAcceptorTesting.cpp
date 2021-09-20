// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:11)

#include "ACESockAcceptorTesting.h" 
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"

using std::string;
using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, ACESockAcceptorTesting)

namespace Network
{
	using TestingType = SockAcceptor;
}

void Network::ACESockAcceptorTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::AcceptorTest);
}

void Network::ACESockAcceptorTesting
	::AcceptorTest()
{
	string hostName{ "127.0.0.1" };
	uint16_t port{ 9120 };

#ifdef _DEBUG
	port += 4;
#endif // _DEBUG

#ifdef BUILDING_NETWORK_STATIC
	port += 2;
#endif // BUILDING_NETWORK_STATIC

#ifdef _WIN64
	port += 1;
#endif // _WIN64

	TestingType sockAcceptor1{ port,GetACEServerConfigurationStrategy() };
	TestingType sockAcceptor2{ hostName,port + 10,GetACEServerConfigurationStrategy() };

	SockStreamSharedPtr sockStream{ make_shared<SockStream>(GetACEServerConfigurationStrategy()) };
	SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(GetACEServerConfigurationStrategy()) };
	SocketManagerSharedPtr socketManager{ make_shared<TestSocketManager>(5) };

// 	sockAcceptor1.EnableNonBlock();
// 
// 	sockAcceptor1.Accept(sockStream);
// 	sockAcceptor1.Accept(sockStream, sockAddress);
// 	sockAcceptor1.AsyncAccept(socketManager, sockStream, sockAddress);
// 	sockAcceptor1.AsyncAccept(socketManager, sockStream);
// 
// 	sockAcceptor2.EnableNonBlock();
// 
// 	sockAcceptor2.Accept(sockStream);
// 	sockAcceptor2.Accept(sockStream, sockAddress);
// 	sockAcceptor2.AsyncAccept(socketManager, sockStream, sockAddress);
// 	sockAcceptor2.AsyncAccept(socketManager, sockStream);
}

