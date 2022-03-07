// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/22 13:57)

#ifndef MATHEMATICS_OBJECTS2D_SUITE_ARC2_TESTING_H
#define MATHEMATICS_OBJECTS2D_SUITE_ARC2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Arc2Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Arc2Testing);

	private:
		void MainTest();
		void Arc2Test();
	
		void DoRunUnitTest() override;	
	};
}

#endif // MATHEMATICS_OBJECTS2D_SUITE_ARC2_TESTING_H