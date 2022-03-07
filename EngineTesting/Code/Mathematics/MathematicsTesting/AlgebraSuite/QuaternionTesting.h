// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 17:08)

#ifndef MATHEMATICS_ALGEBRA_SUITE_QUATERNION_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_QUATERNION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class QuaternionTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(QuaternionTesting); 

	private:
		void MainTest();	
		void ConstructionTest();
		void AccessTest();
		void OperatorCalculateTest();
		void ArithmeticCalculateTest();
		void ClosestCalculateTest();
		void FactorCalculateTest();
		void ConstraintsClosestCalculateTest();
		void CompareTest();
		
		void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_ALGEBRA_SUITE_QUATERNION_TESTING_H