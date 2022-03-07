// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 13:11)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_ACCEPTOR_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_ACCEPTOR_TESTING_H

#include "SingletonTesting.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
	class SockAcceptorTesting : public SingletonTesting
	{
	public:
            using ClassType = SockAcceptorTesting;
            using ParentType = SingletonTesting;

        public:
            explicit SockAcceptorTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		void MainTest();

		void ACETest();
		void BoostTest();
		void NetworkTest();
		void NullTest();

		void ACEConstructionTest();
		void BoostConstructionTest();
		void NetworkConstructionTest();
		void NullConstructionTest();

		void ACEGetACEHandleTest();
		void ACEGetBoostHandleExceptionTest();
		void ACEGetNetworkHandleExceptionTest();

		void BoostGetACEHandleExceptionTest();
		void BoostGetBoostHandleTest();
		void BoostGetNetworkHandleExceptionTest();

		void NetworkGetACEHandleExceptionTest();
		void NetworkGetBoostHandleExceptionTest();
		void NetworkGetNetworkHandleTest();

		void NullGetACEHandleExceptionTest();
		void NullGetBoostHandleExceptionTest();
		void NullGetNetworkHandleExceptionTest();

		void DoRunUnitTest() override;

	private:
		int m_Port;
	};
}

#endif // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_ACCEPTOR_TESTING_H