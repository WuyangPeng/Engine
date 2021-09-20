// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:20)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_ASYNCHRONOUS_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_ASYNCHRONOUS_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockAcceptorTesting.h"

namespace Network
{
	class TestSocketManager;
	using TestSocketManagerSharedPtr = std::shared_ptr<TestSocketManager>;

	class BoostSockAcceptorAsynchronousTesting : public BoostSockAcceptorTesting
	{
	public:
            using ClassType = BoostSockAcceptorAsynchronousTesting;
            using ParentType = BoostSockAcceptorTesting;

        public:
            explicit BoostSockAcceptorAsynchronousTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		using AcceptFunction = void(ClassType::*)(const TestingTypeSharedPtr& sockAcceptor, const TestSocketManagerSharedPtr& testSocketManager);

	private:
		virtual void DoRunUnitTest() override;

		void MainTest();

		void AcceptorTest();

		void AsynchronousAcceptTest();

		void AsynchronousAccept1Test();
		void AsynchronousAccept2Test();
		void AsynchronousAccept3Test();
		void AsynchronousAccept4Test();
		void AsynchronousAccept5Test();
		void AsynchronousAccept6Test();

		void AsynchronousAccept(const TestingTypeSharedPtr& sockAcceptor, AcceptFunction acceptFunction);

		void AsynchronousAcceptNoUseAddress(const TestingTypeSharedPtr& sockAcceptor, const TestSocketManagerSharedPtr& testSocketManager);
		void AsynchronousAcceptUseAddress(const TestingTypeSharedPtr& sockAcceptor, const TestSocketManagerSharedPtr& testSocketManager);
	};
}

#endif // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_ASYNCHRONOUS_TESTING_H