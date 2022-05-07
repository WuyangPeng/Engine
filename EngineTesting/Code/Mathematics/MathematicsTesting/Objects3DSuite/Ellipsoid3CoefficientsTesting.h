// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/22 15:32)

#ifndef MATHEMATICS_OBJECTS2D_SUITE_ELLIPSOID2_COEFFICIENTS_TESTING_H
#define MATHEMATICS_OBJECTS2D_SUITE_ELLIPSOID2_COEFFICIENTS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Ellipsoid3CoefficientsTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Ellipsoid3CoefficientsTesting); 

	private:
		void MainTest();
		void EllipsoidTest();
	
		void DoRunUnitTest() override;	 
	};
}

#endif // MATHEMATICS_OBJECTS2D_SUITE_ELLIPSOID2_COEFFICIENTS_TESTING_H