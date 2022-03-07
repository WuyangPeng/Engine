// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/23 09:56)

#ifndef MATHEMATICS_RATIONAL_SUITE_INTEGER_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_INTEGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class IntegerTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(IntegerTesting); 

	private:
		void MainTest();
		void ConstructionTest();
		void CalculateTest();
		void CompareTest();
		void UtilitiesTest();

		// Construction≤‚ ‘
		void PositiveTest();
		void NegativeTest();
		void ZeroTest();

		// Calculate≤‚ ‘
		void ReverseTest();
		void AbsoluteValueTest();
	    void AddTest();
		void MinusTest();
		void MultiplyTest();
		void DivideTest();
		void LeftShiftTest();
		void RightShiftTest();
		void SignTest();	

		// Utilities≤‚ ‘
		void BlockTest();
		void BitTest();
		void ConversionTest();

		void DoRunUnitTest() override;	 
	};
}

#endif // MATHEMATICS_RATIONAL_SUITE_INTEGER_TESTING_H