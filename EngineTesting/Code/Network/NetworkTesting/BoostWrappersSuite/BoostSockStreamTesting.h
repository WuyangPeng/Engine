// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.2.4 (2020/03/13 16:23)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BOOST_SOCK_STREAM_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BOOST_SOCK_STREAM_TESTING_H

#include "BoostSockTesting.h"

namespace Network
{
	class TestSocketManager;
	using TestSocketManagerSharedPtr = std::shared_ptr<TestSocketManager>;

	class BoostSockStreamTesting : public BoostSockTesting
	{
	public:
            using ClassType = BoostSockStreamTesting;
            using ParentType = BoostSockTesting;

        public:
            explicit BoostSockStreamTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	protected:
		using TestingType = SockStream;
		using TestingTypeSharedPtr = std::shared_ptr<SockStream>;

	protected:
		void ServerThread();
		void DoServerThread();
		void ServerNoReceiveThread();
		void DoServerNoReceiveThread();
		void ClientThread();
		void DoClientThread();
		void ClientNoSendThread();
		void DoClientNoSendThread();
		void CreateMessage();
		void DestroyMessage();
		MessageBufferSharedPtr CreateMessageBuffer() const;
		void VerificationMessageBuffer(const MessageBufferSharedPtr& messageBuffer);

		uint64_t ClientConnect(const ClientSharedPtr& client);
		void ClientSend(const ClientSharedPtr& client, uint64_t socketID, const TestSocketManagerSharedPtr& testSocketManager);
		void ClientReceive(const ClientSharedPtr& client, const TestSocketManagerSharedPtr& testSocketManager);

		static constexpr int GetAcceptTime() noexcept
		{
			return sm_AcceptTime;
		}

		static constexpr int GetAsynchronousAcceptTime() noexcept
		{
			return sm_AsynchronousAcceptTime;
		}

		static constexpr int GetSynchronizeAcceptTime() noexcept
		{
			return sm_SynchronizeAcceptTime;
		}

		static constexpr int GetConnectTime() noexcept
		{
			return sm_ConnectTime;
		}

		static constexpr int GetAsynchronousConnectTime() noexcept
		{
			return sm_AsynchronousConnectTime;
		}

		static constexpr int GetSynchronizeConnectTime() noexcept
		{
			return sm_SynchronizeConnectTime;
		}

		static constexpr int GetSendTime() noexcept
		{
			return sm_SendTime;
		}

		static constexpr int GetSynchronizeSendTime() noexcept
		{
			return sm_SynchronizeSendTime;
		}

		static constexpr int GetAsynchronousSendTime() noexcept
		{
			return sm_AsynchronousSendTime;
		}

		static constexpr int GetReceiveTime() noexcept
		{
			return sm_ReceiveTime;
		}

		static constexpr int GetSynchronizeReceiveTime() noexcept
		{
			return sm_SynchronizeReceiveTime;
		}

		static constexpr int GetAsynchronousReceiveTime() noexcept
		{
			return sm_AsynchronousReceiveTime;
		}

	private:
		// Release版本异步回调的数值要足够大，否则测试时异步回调还未执行。
		static constexpr auto sm_AcceptTime = 100000000;
		static constexpr auto sm_SynchronizeAcceptTime = 1000;
		static constexpr auto sm_AsynchronousAcceptTime = 100000000;
		static constexpr auto sm_ConnectTime = 100;
		static constexpr auto sm_SynchronizeConnectTime = 100;
		static constexpr auto sm_AsynchronousConnectTime = 100000000;

		static constexpr auto sm_SendTime = 100000000;
		static constexpr auto sm_SynchronizeSendTime = 1000;
		static constexpr auto sm_AsynchronousSendTime = 100000000;
		static constexpr auto sm_ReceiveTime = 100;
		static constexpr auto sm_SynchronizeReceiveTime = 1000;
		static constexpr auto sm_AsynchronousReceiveTime = 100000000;
	};
}

#endif // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BOOST_SOCK_STREAM_TESTING_H