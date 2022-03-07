// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/19 17:07)

#ifndef MATHEMATICS_ALGEBRA_UITE_POLYNOMIAL_DIVIDE_TESTING_H
#define MATHEMATICS_ALGEBRA_UITE_POLYNOMIAL_DIVIDE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class PolynomialDivideTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(PolynomialDivideTesting); 

	private:
		void MainTest();	
		void ConstructionTest();

		void DoRunUnitTest() override;		
	};
}

#endif // MATHEMATICS_ALGEBRA_UITE_POLYNOMIAL_DIVIDE_TESTING_H