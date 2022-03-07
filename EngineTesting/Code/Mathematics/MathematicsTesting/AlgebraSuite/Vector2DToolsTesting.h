// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/19 17:09)

#ifndef MATHEMATICS_BASE_SUITE_VECTOR_2D_TOOLS_TESTING_H
#define MATHEMATICS_BASE_SUITE_VECTOR_2D_TOOLS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Vector2ToolsTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Vector2ToolsTesting); 

	private:
		void MainTest();
		void DistanceTest();
		void ProductTest();
		void ProjectionTest();
		void PerpTest();
		void CompareTest();
		void OtherCalculateTest();		

		void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_BASE_SUITE_VECTOR_2D_TOOLS_TESTING_H