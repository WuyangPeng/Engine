// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:22)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_FIXED_SOCK_STREAM_SYNCHRONIZE_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_FIXED_SOCK_STREAM_SYNCHRONIZE_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockStreamTesting.h"

namespace Network
{
	class BoostFixedSockStreamSynchronizeTesting : public BoostSockStreamTesting
	{
	public:
            using ClassType = BoostFixedSockStreamSynchronizeTesting;
            using ParentType = BoostSockStreamTesting;

        public:
            explicit BoostFixedSockStreamSynchronizeTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		virtual void DoRunUnitTest() override;

		void MainTest();

		void StreamTest();

		void SynchronizeStreamTest();

		void ClientTest();
		void ServerTest();

		void ClientSynchronizeConnect(const TestingTypeSharedPtr& sockStream);
		void ClientSynchronizeSend(const TestingTypeSharedPtr& sockStream);
		void ClientSynchronizeReceive(const TestingTypeSharedPtr& sockStream);

		void ServerSynchronizeAcceptor(const TestingTypeSharedPtr& sockStream);
		void ServerSynchronizeReceive(const TestingTypeSharedPtr& sockStream);
		void ServerSynchronizeSend(const TestingTypeSharedPtr& sockStream);
	};
}

#endif // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_FIXED_SOCK_STREAM_SYNCHRONIZE_TESTING_H