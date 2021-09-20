// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 15:57)

#ifndef NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_STREAM_TESTING_H
#define NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_STREAM_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
	class ACESockStreamTesting : public SingletonTesting
	{
	public:
            using ClassType = ACESockStreamTesting;
            using ParentType = SingletonTesting;

        public:
            explicit ACESockStreamTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		void MainTest();

		void StreamTest();

		void ACEServerThread();
		void DoACEServerThread();

		virtual void DoRunUnitTest() override;

	private:
		int m_Port;
	};
}

#endif // NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_STREAM_TESTING_H