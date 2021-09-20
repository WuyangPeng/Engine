// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.4 (2020/03/13 16:44)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NETWORK_SOCK_ACCEPTOR_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NETWORK_SOCK_ACCEPTOR_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
	class NetworkSockAcceptorTesting : public SingletonTesting
	{
	public:
            using ClassType = NetworkSockAcceptorTesting;
            using ParentType = SingletonTesting;

        public:
            explicit NetworkSockAcceptorTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		void MainTest();

		void AcceptorTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NETWORK_SOCK_ACCEPTOR_TESTING_H