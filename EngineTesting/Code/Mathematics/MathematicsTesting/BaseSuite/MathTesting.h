// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 09:46)

#ifndef MATHEMATICS_BASE_SUITE_MATH_TESTING_H
#define MATHEMATICS_BASE_SUITE_MATH_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class MathTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MathTesting); 

	private:
		void MainTest();	
		void ConstantTest();
		void TrigonometricTest();
		void BaseMathTest();
		void LogTest();
		void PowTest();
		void TruncationTest();
		void ApproximateTest();

		// Constant≤‚ ‘
		void FloatConstantTest();
		void DoubleConstantTest();

		// Trigonometric≤‚ ‘
		void FloatTrigonometricTest();
		void DoubleTrigonometricTest();
		void TrigonometricBoundaryTest();

		// BaseMath≤‚ ‘
		void FloatBaseMathTest();
		void DoubleBaseMathTest();
		void BaseMathBoundaryTest();

		// Log≤‚ ‘
		void FloatLogTest();
		void DoubleLogTest();

		// Pow≤‚ ‘
		void FloatPowTest();
		void DoublePowTest();
		void PowBoundaryTest();

		// Truncation≤‚ ‘
		void FloatTruncationTest();
		void DoubleTruncationTest();		

		virtual void DoRunUnitTest() override;
	};
}

#endif // MATHEMATICS_BASE_SUITE_MATH_TESTING_H