// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:21)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_FIXED_SOCK_STREAM_NON_BLOCKING_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_FIXED_SOCK_STREAM_NON_BLOCKING_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockStreamTesting.h"

namespace Network
{
	class BoostFixedSockStreamNonBlockingTesting : public BoostSockStreamTesting
	{
	public:
            using ClassType = BoostFixedSockStreamNonBlockingTesting;
            using ParentType = BoostSockStreamTesting;

        public:
            explicit BoostFixedSockStreamNonBlockingTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		virtual void DoRunUnitTest() override;

		void MainTest();

		void StreamTest();

		void NonBlockingStreamTest();

		void ClientTest();
		void ServerTest();

		void ClientNonBlockingConnect(const TestingTypeSharedPtr& sockStream);
		void ClientNonBlockingSend(const TestingTypeSharedPtr& sockStream);
		void ClientNonBlockingReceive(const TestingTypeSharedPtr& sockStream);

		void ServerNonBlockingAcceptor(const TestingTypeSharedPtr& sockStream);
		void ServerNonBlockingReceive(const TestingTypeSharedPtr& sockStream);
		void ServerNonBlockingSend(const TestingTypeSharedPtr& sockStream);
	};
}

#endif // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_FIXED_SOCK_STREAM_NON_BLOCKING_TESTING_H