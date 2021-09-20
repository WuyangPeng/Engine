// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 11:31)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_CACHE_CLIENT_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_CACHE_CLIENT_TESTING_H

#include "SingletonTesting.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/Interface/Server.h"
#include "Network/NetworkMessage/NetworkMessageEvent.h"

namespace Network
{
	class CacheClientTesting : public SingletonTesting
	{
	public:
            using ClassType = CacheClientTesting;
            using ParentType = SingletonTesting;

        public:
            explicit CacheClientTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		void MainTest();

		void ACETest();
		void BoostTest();
		void AsyncBoostTest();
		void NullTest();

		void CreateMessage();
		void DestroyMessage();

		void ACESendingClientTest();
		void ACEAsyncSendingClientTest();
		void ACEServerThread();
		void DoACEServerThread();

		void BoostSendingClientTest();
		void BoostAsyncSendingClientTest();
		void BoostServerThread();
		void BoostRunServerThread();
		void DoBoostServerThread();

		void NullSendingClientTest();
		void NullAsyncSendingClientTest();
		void NullServerThread();
		void DoNullServerThread();

		virtual void DoRunUnitTest() override;

	private:
		int m_Port;
		uint32_t m_MessageID;
		int m_Increase;
	};
}

#endif // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_CACHE_CLIENT_TESTING_H