// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 15:54)

#ifndef NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_MAIN_MANAGER_TESTING_H
#define NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_MAIN_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
	class ACEMainManagerTesting : public SingletonTesting
	{
	public:
            using ClassType = ACEMainManagerTesting;
            using ParentType = SingletonTesting;

        public:
            explicit ACEMainManagerTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		void MainTest();

		void SingletonTest();
		void RunTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_MAIN_MANAGER_TESTING_H