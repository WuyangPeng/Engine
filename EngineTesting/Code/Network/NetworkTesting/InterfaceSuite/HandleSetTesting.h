// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.4 (2020/03/13 11:32)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_HANDLE_SET_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_HANDLE_SET_TESTING_H

#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h" 

namespace Network
{
	class HandleSetTesting : public SingletonTesting
	{
	public:
            using ClassType = HandleSetTesting;
            using ParentType = SingletonTesting;

        public:
            explicit HandleSetTesting(const OStreamShared& stream);
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

		void ACEHandleTest();
		void BoostHandleTest();
		void NetworkHandleTest();
		void NullHandleTest();

		void BoostGetFdSetExceptionTest();
		void NetworkGetFdSetExceptionTest();
		void NullGetFdSetExceptionTest();

		void BoostGetACEHandleSetExceptionTest();
		void NetworkGetACEHandleSetExceptionTest();
		void NullGetACEHandleSetExceptionTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_HANDLE_SET_TESTING_H