// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.4 (2020/03/13 16:32)

#include "BoostFixedSockStreamSynchronizeTesting.h" 
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

#include <thread> 

using std::thread;
using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, BoostFixedSockStreamSynchronizeTesting)
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26429)
void Network::BoostFixedSockStreamSynchronizeTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(CreateMessage);
	//ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::StreamTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessage);
}

void Network::BoostFixedSockStreamSynchronizeTesting
	::StreamTest()
{
	thread serverThread{ &ClassType::BoostServerThread,this };

	const auto loopCount = GetTestLoopCount();
	for (auto loop = 0; loop < loopCount; ++loop)
	{
		ASSERT_NOT_THROW_EXCEPTION_0(SynchronizeStreamTest);
		ASSERT_NOT_THROW_EXCEPTION_0(ClearOffset);
	}

	BASE_MAIN_MANAGER_SINGLETON.StopContext();

	serverThread.join();
}

void Network::BoostFixedSockStreamSynchronizeTesting
	::SynchronizeStreamTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ClientTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ServerTest);
}

void Network::BoostFixedSockStreamSynchronizeTesting
	::ClientTest()
{
	thread serverThread{ &ClassType::ServerThread,this };

	auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());
	TestingTypeSharedPtr sockStream{ make_shared<TestingType>(configurationStrategy) };

	ASSERT_NOT_THROW_EXCEPTION_1(ClientSynchronizeConnect, sockStream);
	ASSERT_NOT_THROW_EXCEPTION_1(ClientSynchronizeSend, sockStream);
	ASSERT_NOT_THROW_EXCEPTION_1(ClientSynchronizeReceive, sockStream);

	serverThread.join();

	ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostFixedSockStreamSynchronizeTesting
	::ClientSynchronizeConnect(const TestingTypeSharedPtr& sockStream)
{
	auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());

	constexpr auto connectTime = GetSynchronizeConnectTime();
	for (auto i = 0; i < connectTime; ++i)
	{
		SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy.GetIP(),configurationStrategy.GetPort(),configurationStrategy) };

		SockConnector sockConnector{ configurationStrategy };

		if (sockConnector.Connect(sockStream, sockAddress))
		{
			break;
		}

		ASSERT_UNEQUAL_FAILURE_THROW(i + 1, connectTime, "���ӷ�����ʧ�ܡ�");
	}
}

void Network::BoostFixedSockStreamSynchronizeTesting
	::ClientSynchronizeSend(const TestingTypeSharedPtr& sockStream)
{
	constexpr auto sendTime = GetSynchronizeSendTime();
	for (auto i = 0; i < sendTime; ++i)
	{
		if (0 < sockStream->Send(CreateMessageBuffer()))
		{
			break;
		}

		ASSERT_UNEQUAL_FAILURE_THROW(i + 1, sendTime, "������Ϣʧ�ܡ�");
	}
}

void Network::BoostFixedSockStreamSynchronizeTesting
	::ClientSynchronizeReceive(const TestingTypeSharedPtr& sockStream)
{
	auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());

	MessageBufferSharedPtr messageBuffer{ make_shared<MessageBuffer>(BuffBlockSize::Size512,0,configurationStrategy.GetParserStrategy()) };
	constexpr auto receiveTime = GetSynchronizeReceiveTime();
	for (auto i = 0; i < receiveTime; ++i)
	{
		if (0 < sockStream->Receive(messageBuffer))
		{
			break;
		}

		ASSERT_UNEQUAL(i + 1, receiveTime);
	}

	VerificationMessageBuffer(messageBuffer);
}

void Network::BoostFixedSockStreamSynchronizeTesting
	::ServerTest()
{
	thread clientThread{ &ClassType::ClientThread,this };

	auto configurationStrategy = GetBoostFixedServerConfigurationStrategy(GetRealOffset());
	TestingTypeSharedPtr sockStream{ make_shared<TestingType>(configurationStrategy) };

	ASSERT_NOT_THROW_EXCEPTION_1(ServerSynchronizeAcceptor, sockStream);
	ASSERT_NOT_THROW_EXCEPTION_1(ServerSynchronizeReceive, sockStream);
	ASSERT_NOT_THROW_EXCEPTION_1(ServerSynchronizeSend, sockStream);

	clientThread.join();

	ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostFixedSockStreamSynchronizeTesting
	::ServerSynchronizeAcceptor(const TestingTypeSharedPtr& sockStream)
{
	auto configurationStrategy = GetBoostFixedServerConfigurationStrategy(GetRealOffset());

	SockAcceptorSharedPtr sockAcceptor{ make_shared<SockAcceptor>(configurationStrategy) };

	constexpr auto acceptTime = GetSynchronizeAcceptTime();
	for (auto i = 0; i < acceptTime; ++i)
	{
		if (sockAcceptor->Accept(*sockStream))
		{
			break;
		}

		ASSERT_UNEQUAL_FAILURE_THROW(i + 1, acceptTime, "�ȴ��ͻ�������ʧ�ܡ�");
	}
}

void Network::BoostFixedSockStreamSynchronizeTesting
	::ServerSynchronizeReceive(const TestingTypeSharedPtr& sockStream)
{
	auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());

	MessageBufferSharedPtr messageBuffer{ make_shared<MessageBuffer>(BuffBlockSize::Size512,0,configurationStrategy.GetParserStrategy()) };
	constexpr auto receiveTime = GetSynchronizeReceiveTime();
	for (auto i = 0; i < receiveTime; ++i)
	{
		if (0 < sockStream->Receive(messageBuffer))
		{
			break;
		}

		ASSERT_UNEQUAL_FAILURE_THROW(i + 1, receiveTime, "������Ϣʧ�ܡ�");
	}

	VerificationMessageBuffer(messageBuffer);
}

void Network::BoostFixedSockStreamSynchronizeTesting
	::ServerSynchronizeSend(const TestingTypeSharedPtr& sockStream)
{
	constexpr auto sendTime = GetSynchronizeSendTime();
	for (auto i = 0; i < sendTime; ++i)
	{
		if (0 < sockStream->Send(CreateMessageBuffer()))
		{
			break;
		}

		ASSERT_UNEQUAL(i + 1, sendTime);
	}
}

