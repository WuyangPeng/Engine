// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:27)

#include "BoostSockAcceptorSynchronizeTesting.h" 
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/Client.h"
#include "Network/Interface/SockStream.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

#include <thread>

using std::thread;
using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, BoostSockAcceptorSynchronizeTesting)

void Network::BoostSockAcceptorSynchronizeTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::AcceptorTest);
}

void Network::BoostSockAcceptorSynchronizeTesting
	::AcceptorTest()
{
	thread serverThread{ &ClassType::BoostServerThread,this };

	const auto loopCount = GetTestLoopCount();
	for (auto loop = 0; loop < loopCount; ++loop)
	{
		ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAcceptTest);
		ASSERT_NOT_THROW_EXCEPTION_0(ClearOffset);
	}

	BASE_MAIN_MANAGER_SINGLETON.StopContext();

	serverThread.join();
}

void Network::BoostSockAcceptorSynchronizeTesting
	::SynchronizeAcceptTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAccept1Test);
	ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAccept2Test);
	ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAccept3Test);
	ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAccept4Test);
	ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAccept5Test);
	ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeAccept6Test);
}

void Network::BoostSockAcceptorSynchronizeTesting
	::SynchronizeAccept1Test()
{
	const auto port = GetRealPort();

	TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(port,GetBoostServerConfigurationStrategy(GetRealOffset())) };
	ASSERT_NOT_THROW_EXCEPTION_2(SynchronizeAccept, sockAcceptor, &ClassType::SynchronizeAcceptNoUseAddress);
	ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorSynchronizeTesting
	::SynchronizeAccept2Test()
{
	const auto hostName = GetHostName();
	const auto port = GetRealPort();

	TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(hostName,port,GetBoostServerConfigurationStrategy(GetRealOffset())) };
	ASSERT_NOT_THROW_EXCEPTION_2(SynchronizeAccept, sockAcceptor, &ClassType::SynchronizeAcceptNoUseAddress);
	ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorSynchronizeTesting
	::SynchronizeAccept3Test()
{
	TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(GetBoostServerConfigurationStrategy(GetRealOffset())) };
	ASSERT_NOT_THROW_EXCEPTION_2(SynchronizeAccept, sockAcceptor, &ClassType::SynchronizeAcceptNoUseAddress);
	ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorSynchronizeTesting
	::SynchronizeAccept4Test()
{
	const auto port = GetRealPort();

	TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(port,GetBoostServerConfigurationStrategy(GetRealOffset())) };
	ASSERT_NOT_THROW_EXCEPTION_2(SynchronizeAccept, sockAcceptor, &ClassType::SynchronizeAcceptUseAddress);
	ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorSynchronizeTesting
	::SynchronizeAccept5Test()
{
	const auto hostName = GetHostName();
	const auto port = GetRealPort();

	TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(hostName,port,GetBoostServerConfigurationStrategy(GetRealOffset())) };
	ASSERT_NOT_THROW_EXCEPTION_2(SynchronizeAccept, sockAcceptor, &ClassType::SynchronizeAcceptUseAddress);
	ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorSynchronizeTesting
	::SynchronizeAccept6Test()
{
	TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(GetBoostServerConfigurationStrategy(GetRealOffset())) };
	ASSERT_NOT_THROW_EXCEPTION_2(SynchronizeAccept, sockAcceptor, &ClassType::SynchronizeAcceptUseAddress);
	ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorSynchronizeTesting
	::SynchronizeAccept(const TestingTypeSharedPtr& sockAcceptor, AcceptFunction acceptFunction)
{
	thread clientThread{ &ClassType::ClientThread,this };

	constexpr auto acceptTime = GetSynchronizeAcceptTime();
	for (auto i = 0; i < acceptTime; ++i)
	{
		if ((this->*acceptFunction)(sockAcceptor))
		{
			break;
		}

		ASSERT_UNEQUAL(i + 1, acceptTime);
	}

	clientThread.join();
}

bool Network::BoostSockAcceptorSynchronizeTesting
	::SynchronizeAcceptNoUseAddress(const TestingTypeSharedPtr& sockAcceptor)
{
	auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

	SockStreamSharedPtr sockStream{ make_shared<SockStream>(configurationStrategy) };

	return sockAcceptor->Accept(sockStream);
}

bool Network::BoostSockAcceptorSynchronizeTesting
	::SynchronizeAcceptUseAddress(const TestingTypeSharedPtr& sockAcceptor)
{
	auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

	SockStreamSharedPtr sockStream{ make_shared<SockStream>(configurationStrategy) };
	SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy) };

	return sockAcceptor->Accept(sockStream, sockAddress);
}





