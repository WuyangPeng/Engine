// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/28 16:07)

#ifndef MATHEMATICS_APPROXIMATION_SUITE_POLYNOMIAL_FIT3_POWERS_TESTING_H
#define MATHEMATICS_APPROXIMATION_SUITE_POLYNOMIAL_FIT3_POWERS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class PolynomialFit3PowersTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(PolynomialFit3PowersTesting); 

	private:
		void MainTest();	
		void FitTest();

		void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_APPROXIMATION_SUITE_POLYNOMIAL_FIT3_POWERS_TESTING_H