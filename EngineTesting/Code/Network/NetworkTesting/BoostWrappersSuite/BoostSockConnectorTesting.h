// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.2.4 (2020/03/13 16:23)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BOOST_SOCK_CONNECTOR_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BOOST_SOCK_CONNECTOR_TESTING_H

#include "BoostSockTesting.h"

namespace Network
{
	class BoostSockConnectorTesting : public BoostSockTesting
	{
	public:
            using ClassType = BoostSockConnectorTesting;
            using ParentType = BoostSockTesting;

        public:
            explicit BoostSockConnectorTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	protected:
		using TestingType = SockConnector;
		using TestingTypeSharedPtr = std::shared_ptr<SockConnector>;

	protected:
		void ServerThread();
		void DoServerThread();

		static constexpr int GetAcceptTime() noexcept
		{
			return sm_AcceptTime;
		}

		static constexpr int GetAsynchronousConnectTime() noexcept
		{
			return sm_AsynchronousConnectTime;
		}

		static constexpr int GetSynchronizeConnectTime() noexcept
		{
			return sm_SynchronizeConnectTime;
		}

	private:
		// Release版本sm_AcceptTime和sm_AsynchronousConnectTime值要足够大，否则测试时异步回调还未执行。
		static constexpr auto sm_AcceptTime = 100000000;
		static constexpr auto sm_SynchronizeConnectTime = 100;
		static constexpr auto sm_AsynchronousConnectTime = 100000000;
	};
}

#endif // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BOOST_SOCK_CONNECTOR_TESTING_H