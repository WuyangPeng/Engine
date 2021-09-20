// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 17:07)

#ifndef MATHEMATICS_ALGEBRA_SUITE_MATRIX_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_MATRIX_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class MatrixTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MatrixTesting); 

	private:
		void MainTest();
		void ConstructionTest();
		void AccessTest();
		void OperatorCalculateTest();
		void ArithmeticCalculateTest();
		void ProjectionTest();
		void CompareTest();
		void HomogeneousPointTest();
		void Invert3x3Test();
		
		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_ALGEBRA_SUITE_MATRIX_TESTING_H