// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.4 (2020/03/13 11:32)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_CLIENT_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_CLIENT_TESTING_H

#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h" 

namespace Network
{
	class ClientTesting : public SingletonTesting
	{
	public:
            using ClassType = ClientTesting;
            using ParentType = SingletonTesting;

        public:
            explicit ClientTesting(const OStreamShared& stream);
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

		void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_CLIENT_TESTING_H