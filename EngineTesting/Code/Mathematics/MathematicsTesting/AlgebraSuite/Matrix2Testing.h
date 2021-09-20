// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 17:06)

#ifndef MATHEMATICS_ALGEBRA_SUITE_MATRIX2_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_MATRIX2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Matrix2Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Matrix2Testing); 

	private:
		void MainTest();
		void ConstructionTest();
		void AccessTest();
		void OperatorCalculateTest();
		void ArithmeticCalculateTest();		
		
		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_BASE_SUITE_MATRIX2_TESTING_H