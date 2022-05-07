// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/27 13:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT1_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT1_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Bisect1Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Bisect1Testing); 

	private:
		void MainTest();
		void HaveSolutionTest();
        void NoSolutionTest();
        void UnknownTest();
	
		void DoRunUnitTest() override;
        
        static double FirstEquation(double value);
        static float SecondEquation(float value);
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT1_TESTING_H