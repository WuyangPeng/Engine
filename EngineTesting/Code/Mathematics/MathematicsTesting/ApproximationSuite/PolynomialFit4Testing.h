// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 16:08)

#ifndef MATHEMATICS_APPROXIMATION_SUITE_POLYNOMIAL_FIT4_TESTING_H
#define MATHEMATICS_APPROXIMATION_SUITE_POLYNOMIAL_FIT4_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class PolynomialFit4Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(PolynomialFit4Testing); 

	private:
		void MainTest();	
		void FitTest();

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_APPROXIMATION_SUITE_POLYNOMIAL_FIT4_TESTING_H