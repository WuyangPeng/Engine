// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.2.4 (2020/03/13 16:30)

#include "BoostFixedSockStreamAsynchronousTesting.h" 
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/SockStream.h" 
#include "Network/Interface/SockAddress.h" 
#include "Network/Interface/SockAcceptor.h"
#include "Network/Interface/SockConnector.h"
#include "Network/NetworkMessage/NullMessage.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"

#include <thread> 

using std::thread;
using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, BoostFixedSockStreamAsynchronousTesting)

void Network::BoostFixedSockStreamAsynchronousTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(CreateMessage);
	ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::StreamTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessage);
}

void Network::BoostFixedSockStreamAsynchronousTesting
	::StreamTest()
{
	thread serverThread{ &ClassType::BoostServerThread,this };

	const auto loopCount = GetTestLoopCount();
	for (auto loop = 0; loop < loopCount; ++loop)
	{
		ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousStreamTest);
		ASSERT_NOT_THROW_EXCEPTION_0(ClearOffset);
	}

	BASE_MAIN_MANAGER_SINGLETON.StopContext();

	serverThread.join();
}

void Network::BoostFixedSockStreamAsynchronousTesting
	::AsynchronousStreamTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ClientTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ServerTest);
}

void Network::BoostFixedSockStreamAsynchronousTesting
	::ClientTest()
{
	thread serverThread{ &ClassType::ServerThread,this };

	auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());
	TestingTypeSharedPtr sockStream{ make_shared<TestingType>(configurationStrategy) };

	ASSERT_NOT_THROW_EXCEPTION_1(ClientAsynchronousConnect, sockStream);
	ASSERT_NOT_THROW_EXCEPTION_1(ClientAsynchronousSend, sockStream);
	ASSERT_NOT_THROW_EXCEPTION_1(ClientAsynchronousReceive, sockStream);

	serverThread.join();

	ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostFixedSockStreamAsynchronousTesting
	::ClientAsynchronousConnect(const TestingTypeSharedPtr& sockStream)
{
	auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());

	TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };
	SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy.GetIP(),configurationStrategy.GetPort(),configurationStrategy) };

	SockConnector sockConnector{ configurationStrategy };
	sockConnector.AsyncConnect(testSocketManager, sockStream, sockAddress);

	constexpr auto connectTime = GetAsynchronousConnectTime();
	for (auto i = 0; i < connectTime; ++i)
	{
		if (0 < testSocketManager->GetAsyncConnectCount())
		{
			break;
		}

		ASSERT_UNEQUAL_FAILURE_THROW(i + 1, connectTime, "连接服务器失败。");
	}
}

void Network::BoostFixedSockStreamAsynchronousTesting
	::ClientAsynchronousSend(const TestingTypeSharedPtr& sockStream)
{
	TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };
	sockStream->AsyncSend(testSocketManager, CreateMessageBuffer());

	constexpr auto sendTime = GetAsynchronousSendTime();
	for (auto i = 0; i < sendTime; ++i)
	{
		if (0 < testSocketManager->GetAsyncSendCount())
		{
			break;
		}

		ASSERT_UNEQUAL_FAILURE_THROW(i + 1, sendTime, "发送消息失败。");
	}
}

void Network::BoostFixedSockStreamAsynchronousTesting
	::ClientAsynchronousReceive(const TestingTypeSharedPtr& sockStream)
{
	auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());

	MessageBufferSharedPtr messageBuffer{ make_shared<MessageBuffer>(BuffBlockSize::Size512,0,configurationStrategy.GetParserStrategy()) };
	TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };
	sockStream->AsyncReceive(testSocketManager, messageBuffer);

	constexpr auto receiveTime = GetAsynchronousReceiveTime();
	for (auto i = 0; i < receiveTime; ++i)
	{
		if (0 < testSocketManager->GetAsyncReceiveCount())
		{
			break;
		}

		ASSERT_UNEQUAL(i + 1, receiveTime);
	}

	VerificationMessageBuffer(messageBuffer);
}

void Network::BoostFixedSockStreamAsynchronousTesting
	::ServerTest()
{
	thread clientThread{ &ClassType::ClientThread,this };

	auto configurationStrategy = GetBoostFixedServerConfigurationStrategy(GetRealOffset());
	TestingTypeSharedPtr sockStream{ make_shared<TestingType>(configurationStrategy) };

	ASSERT_NOT_THROW_EXCEPTION_1(ServerAsynchronousAcceptor, sockStream);
	ASSERT_NOT_THROW_EXCEPTION_1(ServerAsynchronousReceive, sockStream);
	ASSERT_NOT_THROW_EXCEPTION_1(ServerAsynchronousSend, sockStream);

	clientThread.join();

	ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostFixedSockStreamAsynchronousTesting
	::ServerAsynchronousAcceptor(const TestingTypeSharedPtr& sockStream)
{
	auto configurationStrategy = GetBoostFixedServerConfigurationStrategy(GetRealOffset());

	SockAcceptorSharedPtr sockAcceptor{ make_shared<SockAcceptor>(configurationStrategy) };
	TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };

	sockAcceptor->AsyncAccept(testSocketManager, sockStream);

	constexpr auto acceptTime = GetAsynchronousAcceptTime();
	for (auto i = 0; i < acceptTime; ++i)
	{
		if (0 < testSocketManager->GetAsyncAcceptorCount())
		{
			break;
		}

		ASSERT_UNEQUAL_FAILURE_THROW(i + 1, acceptTime, "等待客户端连接失败。");
	}
}

void Network::BoostFixedSockStreamAsynchronousTesting
	::ServerAsynchronousReceive(const TestingTypeSharedPtr& sockStream)
{
	auto configurationStrategy = GetBoostFixedServerConfigurationStrategy(GetRealOffset());

	MessageBufferSharedPtr messageBuffer{ make_shared<MessageBuffer>(BuffBlockSize::Size512,0,configurationStrategy.GetParserStrategy()) };
	TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };

	sockStream->AsyncReceive(testSocketManager, messageBuffer);

	constexpr auto receiveTime = GetAsynchronousReceiveTime();
	for (auto i = 0; i < receiveTime; ++i)
	{
		if (0 < testSocketManager->GetAsyncReceiveCount())
		{
			break;
		}

		ASSERT_UNEQUAL_FAILURE_THROW(i + 1, receiveTime, "接收消息失败。");
	}

	VerificationMessageBuffer(messageBuffer);
}

void Network::BoostFixedSockStreamAsynchronousTesting
	::ServerAsynchronousSend(const TestingTypeSharedPtr& sockStream)
{
	TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };
	sockStream->AsyncSend(testSocketManager, CreateMessageBuffer());

	constexpr auto sendTime = GetAsynchronousSendTime();
	for (auto i = 0; i < sendTime; ++i)
	{
		if (0 < testSocketManager->GetAsyncSendCount())
		{
			break;
		}

		ASSERT_UNEQUAL(i + 1, sendTime);
	}
}

