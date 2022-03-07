// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:20)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_NON_BLOCKING_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_NON_BLOCKING_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockAcceptorTesting.h"

namespace Network
{
	class BoostSockAcceptorNonBlockingTesting : public BoostSockAcceptorTesting
	{
	public:
            using ClassType = BoostSockAcceptorNonBlockingTesting;
            using ParentType = BoostSockAcceptorTesting;

        public:
            explicit BoostSockAcceptorNonBlockingTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		using AcceptFunction = bool(ClassType::*)(const TestingTypeSharedPtr& sockAcceptor);

	private:
		void DoRunUnitTest() override;

		void MainTest();

		void AcceptorTest();

		void NonBlockingTest();

		void NonBlocking1Test();
		void NonBlocking2Test();
		void NonBlocking3Test();
		void NonBlocking4Test();
		void NonBlocking5Test();
		void NonBlocking6Test();

		void NonBlockingAccept(const TestingTypeSharedPtr& sockAcceptor, AcceptFunction acceptFunction);

		bool NonBlockingAcceptNoUseAddress(const TestingTypeSharedPtr& sockAcceptor);
		bool NonBlockingAcceptUseAddress(const TestingTypeSharedPtr& sockAcceptor);
	};
}

#endif // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_NON_BLOCKING_TESTING_H