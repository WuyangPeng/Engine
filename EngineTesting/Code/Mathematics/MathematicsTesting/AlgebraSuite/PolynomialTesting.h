// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 17:07)

#ifndef MATHEMATICS_ALGEBRA_UITE_POLYNOMIAL_TESTING_H
#define MATHEMATICS_ALGEBRA_UITE_POLYNOMIAL_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class PolynomialTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(PolynomialTesting); 

	private:
		void MainTest();	
		void ConstructionTest();
		void AccessTest();
		void UpdateOperatorTest();
		void OperationTest();
		void CalculateTest();

		virtual void DoRunUnitTest() override;		
	};
}

#endif // MATHEMATICS_ALGEBRA_UITE_POLYNOMIAL_TESTING_H