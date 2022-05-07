// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/30 15:51)

#ifndef MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_FIND_INTERSECTOR1_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_FIND_INTERSECTOR1_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	template <typename R>
	class DynamicFindIntersector1;

	class DynamicFindIntersector1Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(DynamicFindIntersector1Testing); 

	private:
		void MainTest();	
		void IntersectorTest();
		void GetFirstTimeException(const DynamicFindIntersector1<double>& intersector1);
		void GetLastTimeException(const DynamicFindIntersector1<double>& intersector1);

		void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_FIND_INTERSECTOR1_TESTING_H