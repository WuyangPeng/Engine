// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 13:55)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_POLAR_DECOMPOSITION_VALUE_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_POLAR_DECOMPOSITION_VALUE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class PolarDecompositionValueTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(PolarDecompositionValueTesting); 

	private:
		void MainTest();   
		void PolarDecompositionValueTest();
		
		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_POLAR_DECOMPOSITION_VALUE_TESTING_H