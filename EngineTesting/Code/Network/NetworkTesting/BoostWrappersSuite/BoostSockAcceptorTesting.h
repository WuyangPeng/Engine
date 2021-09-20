// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.2.4 (2020/03/13 16:23)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_TESTING_H

#include "BoostSockTesting.h"

namespace Network
{
	class BoostSockAcceptorTesting : public BoostSockTesting
	{
	public:
            using ClassType = BoostSockAcceptorTesting;
            using ParentType = BoostSockTesting;

        public:
            explicit BoostSockAcceptorTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;

	protected:
		using TestingType = SockAcceptor;
		using TestingTypeSharedPtr = std::shared_ptr<SockAcceptor>;

	protected:
		void ClientThread();
		void DoClientThread();

		static constexpr int GetConnectTime() noexcept
		{
			return sm_ConnectTime;
		}

		static constexpr int GetAsynchronousAcceptTime() noexcept
		{
			return sm_AsynchronousAcceptTime;
		}

		static constexpr int GetSynchronizeAcceptTime() noexcept
		{
			return sm_SynchronizeAcceptTime;
		}

	private:
		// Release版本sm_AsynchronousAcceptTime值要足够大，否则测试时异步回调还未执行。
		static constexpr auto sm_ConnectTime = 100;
		static constexpr auto sm_SynchronizeAcceptTime = 1000;
		static constexpr auto sm_AsynchronousAcceptTime = 100000000;
	};
}

#endif // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_TESTING_H