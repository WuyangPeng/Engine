// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 13:47)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT2_ROOT_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT2_ROOT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Bisect2RootTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Bisect2RootTesting); 

	private:
		void MainTest();
        void HaveSolutionTest();
        void NoSolutionXTest();
        void NoSolutionYTest();
        void UnknownTest();
		
		void DoRunUnitTest() override;		
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT2_ROOT_TESTING_H