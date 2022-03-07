// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:20)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_HANDLE_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_HANDLE_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockAcceptorTesting.h"

namespace Network
{
	class BoostSockAcceptorHandleTesting : public BoostSockAcceptorTesting
	{
	public:
            using ClassType = BoostSockAcceptorHandleTesting;
            using ParentType = BoostSockAcceptorTesting;

        public:
            explicit BoostSockAcceptorHandleTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		void DoRunUnitTest() override;

		void MainTest();

		void AcceptorTest();

		void AcceptorInformationTest();
		void ACEHandleExceptionTest();
		void WinSocketExceptionTest();
	};
}

#endif // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_HANDLE_TESTING_H