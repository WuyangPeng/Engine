// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:22)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_STREAM_HANDLE_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_STREAM_HANDLE_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockStreamTesting.h"

namespace Network
{
	class BoostSockStreamHandleTesting : public BoostSockStreamTesting
	{
	public:
            using ClassType = BoostSockStreamHandleTesting;
            using ParentType = BoostSockStreamTesting;

        public:
            explicit BoostSockStreamHandleTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		virtual void DoRunUnitTest() override;

		void MainTest();

		void StreamTest();

		void StreamInformationTest();

		void ClientTest();
		void ServerTest();

		void ClientConnect(const TestingTypeSharedPtr& sockStream);
		void ServerAcceptor(const TestingTypeSharedPtr& sockStream);

		void ACESockStreamExceptionTest();
		void NetworkSockStreamExceptionTest();

		void ACEHandleExceptionTest();
		void SetACEHandleExceptionTest();
		void SetNetworkHandleExceptionTest();
	};
}

#endif // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_STREAM_HANDLE_TESTING_H