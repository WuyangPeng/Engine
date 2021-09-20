// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/27 13:55)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_POLYNOMIAL_ROOTS_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_POLYNOMIAL_ROOTS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class PolynomialRootsTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(PolynomialRootsTesting); 

	private:
		void MainTest(); 
		void BaseTest();
		void OnceTest();
		void SecondaryTest();
		void ThriceTest();
		void SpecialCubicTest();
		void QuarticTest();
		void PolynomialTest();
		void AllRealPartsNegativeTest();
		void AllRealPartsPositiveTest();
		void GetRootCountTest();
		
		virtual void DoRunUnitTest() override;	 
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_POLYNOMIAL_ROOTS_TESTING_H