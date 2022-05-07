// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/30 15:55)

#ifndef MATHEMATICS_INTERSECTION_SUITE_STATIC_TEST_INTERSECTOR_LINE2_SEGMENT2_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_STATIC_TEST_INTERSECTOR_LINE2_SEGMENT2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class StaticTestIntersectorLine2Segment2Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StaticTestIntersectorLine2Segment2Testing); 

	private:
		void MainTest();	
		void SegmentTest(); 

		void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_INTERSECTION_SUITE_STATIC_TEST_INTERSECTOR_LINE2_SEGMENT2_TESTING_H