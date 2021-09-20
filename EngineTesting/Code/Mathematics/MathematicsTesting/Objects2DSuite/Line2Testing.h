// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/22 13:58)

#ifndef MATHEMATICS_OBJECTS2D_SUITE_LINE2_TESTING_H
#define MATHEMATICS_OBJECTS2D_SUITE_LINE2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Line2Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Line2Testing);

	private:
		void MainTest();
		void LineTest();
	
		virtual void DoRunUnitTest() override;	
	};
}

#endif // MATHEMATICS_OBJECTS2D_SUITE_LINE2_TESTING_H