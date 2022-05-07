// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/22 13:57)

#ifndef MATHEMATICS_OBJECTS2D_SUITE_CIRCLE2_TESTING_H
#define MATHEMATICS_OBJECTS2D_SUITE_CIRCLE2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Circle2Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Circle2Testing);

	private:
		void MainTest();
		void CircleTest();
	
		void DoRunUnitTest() override;	
	};
}

#endif // MATHEMATICS_OBJECTS2D_SUITE_CIRCLE2_TESTING_H