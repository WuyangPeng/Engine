// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.4 (2020/03/13 13:11)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_STREAM_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_STREAM_TESTING_H

#include "SingletonTesting.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
	class SockStreamTesting : public SingletonTesting
	{
	public:
            using ClassType = SockStreamTesting;
            using ParentType = SingletonTesting;

        public:
            explicit SockStreamTesting(const OStreamShared& stream);
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

		void ACEGetACESockStreamTest();
		void ACEGetBoostSockStreamExceptionTest();
		void ACEGetNetworkSockStreamExceptionTest();

		void BoostGetACESockStreamExceptionTest();
		void BoostGetBoostSockStreamTest();
		void BoostGetNetworkSockStreamExceptionTest();

		void NetworkGetACESockStreamExceptionTest();
		void NetworkGetBoostSockStreamExceptionTest();
		void NetworkGetNetworkSockStreamTest();

		void NullGetACESockStreamExceptionTest();
		void NullGetBoostSockStreamExceptionTest();
		void NullGetNetworkSockStreamExceptionTest();

		void ACEGetACEHandleTest();
		void ACESetACEHandleTest();
		void ACESetNetworkHandleExceptionTest();

		void BoostGetACEHandleExceptionTest();
		void BoostSetACEHandleExceptionTest();
		void BoostSetNetworkHandleExceptionTest();

		void NetworkGetACEHandleExceptionTest();
		void NetworkSetACEHandleExceptionTest();
		void NetworkSetNetworkHandleTest();

		void NullGetACEHandleExceptionTest();
		void NullSetACEHandleExceptionTest();
		void NullSetNetworkHandleExceptionTest();

		void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_STREAM_TESTING_H