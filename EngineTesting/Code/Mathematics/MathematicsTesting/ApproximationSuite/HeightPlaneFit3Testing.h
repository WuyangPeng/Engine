// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 16:07)

#ifndef MATHEMATICS_APPROXIMATION_SUITE_HEIGHT_PLANE_TESTING_H
#define MATHEMATICS_APPROXIMATION_SUITE_HEIGHT_PLANE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class HeightPlaneFit3Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(HeightPlaneFit3Testing); 

	private:
		void MainTest();	
		void FitTest();

		void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_APPROXIMATION_SUITE_HEIGHT_PLANE_TESTING_H