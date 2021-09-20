// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 16:18)

#ifndef RENDERING_CONTROLLERS_SUITE_IK_GOAL_TESTING_H
#define RENDERING_CONTROLLERS_SUITE_IK_GOAL_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class IKGoalTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(IKGoalTesting); 

	private:
		void MainTest();
		void InitTest();	
		void CopyTest();
		void StreamTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // RENDERING_CONTROLLERS_SUITE_IK_GOAL_TESTING_H