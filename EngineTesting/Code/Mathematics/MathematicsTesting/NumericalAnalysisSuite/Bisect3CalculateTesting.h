// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 13:47)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT3_CALCULATE_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT3_CALCULATE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Bisect3CalculateTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Bisect3CalculateTesting);  

	private:
		void MainTest();
		void HaveSolutionTest();
        void NoSolutionTest();
        void UnknownTest();
	
		virtual void DoRunUnitTest() override;
        
        static float FirstEquation(float x,float y,float z);
        static float SecondEquation(float x,float y,float z);
		static float ThirdEquation(float x,float y,float z);
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT3_CALCULATE_TESTING_H