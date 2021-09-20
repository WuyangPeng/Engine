// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:27)

#include "BoostSockConnectorAsynchronousTesting.h" 
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/SockStream.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockConnector.h" 
#include "Network/Interface/BaseMainManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"

#include <thread>

using std::thread;
using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, BoostSockConnectorAsynchronousTesting)

void Network::BoostSockConnectorAsynchronousTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::ConnectorTest);
}

void Network::BoostSockConnectorAsynchronousTesting
	::ConnectorTest()
{
	thread serverThread{ &ClassType::BoostServerThread,this };
	constexpr auto resetCount = 10;

	const auto loopCount = GetTestLoopCount();
	for (auto loop = 0; loop < loopCount; ++loop)
	{
		ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousConnectorTest);
		ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
		if (loop % resetCount == (resetCount - 1))
		{
			ASSERT_NOT_THROW_EXCEPTION_0(ClearOffset);
		}
	}

	BASE_MAIN_MANAGER_SINGLETON.StopContext();

	serverThread.join();
}

void Network::BoostSockConnectorAsynchronousTesting
	::AsynchronousConnectorTest()
{
	thread serverThread{ &ClassType::ServerThread,this };

	auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

	TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };

	SockStreamSharedPtr sockStream{ make_shared<SockStream>(configurationStrategy) };
	SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy.GetIP(),configurationStrategy.GetPort(),configurationStrategy) };

	TestingType sockConnector{ configurationStrategy };
	sockConnector.AsyncConnect(testSocketManager, sockStream, sockAddress);

	constexpr auto connectTime = GetAsynchronousConnectTime();
	for (auto i = 0; i < connectTime; ++i)
	{
		if (0 < testSocketManager->GetAsyncConnectCount())
		{
			break;
		}

		ASSERT_UNEQUAL(i + 1, connectTime);
	}

	serverThread.join();
}



