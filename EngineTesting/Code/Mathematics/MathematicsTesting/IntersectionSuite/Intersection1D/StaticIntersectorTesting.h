// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/30 15:52)

#ifndef MATHEMATICS_INTERSECTION_SUITE_STATIC_INTERSECTOR_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_STATIC_INTERSECTOR_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class StaticIntersectorTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StaticIntersectorTesting); 

	private:
		void MainTest();	
		void IntersectionTypeTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // MATHEMATICS_INTERSECTION_SUITE_STATIC_INTERSECTOR_TESTING_H