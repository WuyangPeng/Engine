// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.4 (2020/03/13 16:20)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_CONNECTOR_ASYNCHRONOUS_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_CONNECTOR_ASYNCHRONOUS_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockConnectorTesting.h"

namespace Network
{
	class BoostSockConnectorAsynchronousTesting : public BoostSockConnectorTesting
	{
	public:
            using ClassType = BoostSockConnectorAsynchronousTesting;
            using ParentType = BoostSockConnectorTesting;

        public:
            explicit BoostSockConnectorAsynchronousTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		virtual void DoRunUnitTest() override;

		void MainTest();

		void ConnectorTest();

		void AsynchronousConnectorTest();
	};
}

#endif // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_CONNECTOR_ASYNCHRONOUS_TESTING_H