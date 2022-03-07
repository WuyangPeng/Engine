// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/22 13:58)

#ifndef MATHEMATICS_OBJECTS2D_SUITE_ELLIPSE2_COEFFICIENTS_TESTING_H
#define MATHEMATICS_OBJECTS2D_SUITE_ELLIPSE2_COEFFICIENTS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Ellipse2CoefficientsTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Ellipse2CoefficientsTesting);

	private:
		void MainTest();
		void EllipseTest();
	
		void DoRunUnitTest() override;	
	};
}

#endif // MATHEMATICS_OBJECTS2D_SUITE_ELLIPSE2_COEFFICIENTS_TESTING_H