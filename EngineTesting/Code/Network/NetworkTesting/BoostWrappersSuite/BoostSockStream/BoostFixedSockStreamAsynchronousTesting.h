// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.4 (2020/03/13 16:21)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_FIXED_SOCK_STREAM_ASYNCHRONOUS_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_FIXED_SOCK_STREAM_ASYNCHRONOUS_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockStreamTesting.h"

namespace Network
{
	class BoostFixedSockStreamAsynchronousTesting : public BoostSockStreamTesting
	{
	public:
            using ClassType = BoostFixedSockStreamAsynchronousTesting;
            using ParentType = BoostSockStreamTesting;

        public:
            explicit BoostFixedSockStreamAsynchronousTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		void DoRunUnitTest() override;

		void MainTest();

		void StreamTest();

		void AsynchronousStreamTest();

		void ClientTest();
		void ServerTest();

		void ClientAsynchronousConnect(const TestingTypeSharedPtr& sockStream);
		void ClientAsynchronousSend(const TestingTypeSharedPtr& sockStream);
		void ClientAsynchronousReceive(const TestingTypeSharedPtr& sockStream);

		void ServerAsynchronousAcceptor(const TestingTypeSharedPtr& sockStream);
		void ServerAsynchronousReceive(const TestingTypeSharedPtr& sockStream);
		void ServerAsynchronousSend(const TestingTypeSharedPtr& sockStream);
	};
}

#endif // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_FIXED_SOCK_STREAM_ASYNCHRONOUS_TESTING_H