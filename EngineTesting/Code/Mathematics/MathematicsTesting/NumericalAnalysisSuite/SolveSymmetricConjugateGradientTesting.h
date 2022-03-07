// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 13:56)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class SolveSymmetricConjugateGradientTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(SolveSymmetricConjugateGradientTesting); 

	private:
		void MainTest();   
		void VariableMatrixTest();
		void SparseMatrixTest();
				
		void DoRunUnitTest() override;	
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_TESTING_H