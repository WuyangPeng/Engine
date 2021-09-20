// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 13:53)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_LINEAR_SYSTEM_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_LINEAR_SYSTEM_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class LinearSystemTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(LinearSystemTesting); 

	private:
		void MainTest();   
		void Solve2Test();
		void Solve3Test();
		void InverseTest();
		void SolveTest();
		void SolveTridiagonalTest();
		void SolveConstTridiagonalTest();
		void SolveSymmetricConjugateGradientTest();
		void SolveBandedTest();
		void InvertTest();
		
		virtual void DoRunUnitTest() override;	 
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_LINEAR_SYSTEM_TESTING_H