// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 15:54)

#ifndef NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_ACCEPTOR_TESTING_H
#define NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_ACCEPTOR_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
	class ACESockAcceptorTesting : public SingletonTesting
	{
	public:
            using ClassType = ACESockAcceptorTesting;
            using ParentType = SingletonTesting;

        public:
            explicit ACESockAcceptorTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		void MainTest();

		void AcceptorTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_ACCEPTOR_TESTING_H