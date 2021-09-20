// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/22 15:32)

#ifndef MATHEMATICS_OBJECTS3D_SUITE_ELLIPSE3_TESTING_H
#define MATHEMATICS_OBJECTS3D_SUITE_ELLIPSE3_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Ellipse3Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Ellipse3Testing); 

	private:
		void MainTest();
		void EllipseTest();
	
		virtual void DoRunUnitTest() override;	 
	};
}

#endif // MATHEMATICS_OBJECTS3D_SUITE_ELLIPSE3_TESTING_H