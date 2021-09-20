// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/28 16:08)

#ifndef MATHEMATICS_APPROXIMATION_SUITE_QUADRATIC_SPHERE_FIT3_TESTING_H
#define MATHEMATICS_APPROXIMATION_SUITE_QUADRATIC_SPHERE_FIT3_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class QuadraticSphereFit3Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(QuadraticSphereFit3Testing); 

	private:
		void MainTest();	
		void FitTest();

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_APPROXIMATION_SUITE_QUADRATIC_SPHERE_FIT3_TESTING_H