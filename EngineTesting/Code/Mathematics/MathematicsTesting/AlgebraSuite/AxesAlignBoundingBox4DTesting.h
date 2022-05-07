// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/19 17:05)

#ifndef MATHEMATICS_BASE_SUITE_AXES_ALIGN_BOUNDING_BOX_4D_TESTING_H
#define MATHEMATICS_BASE_SUITE_AXES_ALIGN_BOUNDING_BOX_4D_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class AxesAlignBoundingBox4DTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(AxesAlignBoundingBox4DTesting); 

	private:
		void MainTest();	
		void ConstructionTest();

		void DoRunUnitTest() override;		
	};
}

#endif // MATHEMATICS_BASE_SUITE_AXES_ALIGN_BOUNDING_BOX_4D_TESTING_H