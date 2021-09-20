// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:15)

#ifndef CORE_TOOLS_STATE_MACHINE_SUITE_STATE_MACHINE_TESTING_H
#define CORE_TOOLS_STATE_MACHINE_SUITE_STATE_MACHINE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class StateMachineTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StateMachineTesting);

	private:
		void MainTest();
		void PlayerTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_STATE_MACHINE_SUITE_STATE_MACHINE_TESTING_H