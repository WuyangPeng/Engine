// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:20)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_SYNCHRONIZE_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_SYNCHRONIZE_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockAcceptorTesting.h"

namespace Network
{
	class BoostSockAcceptorSynchronizeTesting : public BoostSockAcceptorTesting
	{
	public:
            using ClassType = BoostSockAcceptorSynchronizeTesting;
            using ParentType = BoostSockAcceptorTesting;

        public:
            explicit BoostSockAcceptorSynchronizeTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		using AcceptFunction = bool(ClassType::*)(const TestingTypeSharedPtr& sockAcceptor);

	private:
		virtual void DoRunUnitTest() override;

		void MainTest();

		void AcceptorTest();

		void SynchronizeAcceptTest();

		void SynchronizeAccept1Test();
		void SynchronizeAccept2Test();
		void SynchronizeAccept3Test();
		void SynchronizeAccept4Test();
		void SynchronizeAccept5Test();
		void SynchronizeAccept6Test();

		void SynchronizeAccept(const TestingTypeSharedPtr& sockAcceptor, AcceptFunction acceptFunction);

		bool SynchronizeAcceptNoUseAddress(const TestingTypeSharedPtr& sockAcceptor);
		bool SynchronizeAcceptUseAddress(const TestingTypeSharedPtr& sockAcceptor);
	};
}

#endif // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_SYNCHRONIZE_TESTING_H