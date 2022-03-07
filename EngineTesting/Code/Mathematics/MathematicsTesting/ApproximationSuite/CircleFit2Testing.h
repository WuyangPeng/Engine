// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 16:06)

#ifndef MATHEMATICS_APPROXIMATION_SUITE_CIRCLE_FIT2_TESTING_H
#define MATHEMATICS_APPROXIMATION_SUITE_CIRCLE_FIT2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class CircleFit2Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(CircleFit2Testing); 

	private:
		void MainTest();	
		void FitTest();

		void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_APPROXIMATION_SUITE_CIRCLE_FIT2_TESTING_H