// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 13:54)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_NONITERATIVE_EIGEN3X3_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_NONITERATIVE_EIGEN3X3_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class NoniterativeEigen3x3Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(NoniterativeEigen3x3Testing); 

	private:
		void MainTest();   
		void EigenTest();
		
		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_NONITERATIVE_EIGEN3X3_TESTING_H