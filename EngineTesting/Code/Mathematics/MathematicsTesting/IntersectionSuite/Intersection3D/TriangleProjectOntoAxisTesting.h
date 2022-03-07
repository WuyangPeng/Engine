// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 15:55)

#ifndef MATHEMATICS_INTERSECTION_SUITE_TRIANGLE_PROJECT_ONTO_AXIS_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_TRIANGLE_PROJECT_ONTO_AXIS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class TriangleProjectOntoAxisTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(TriangleProjectOntoAxisTesting); 

	private:
		void MainTest();	
		void ProjectTest(); 

		void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_INTERSECTION_SUITE_TRIANGLE_PROJECT_ONTO_AXIS_TESTING_H