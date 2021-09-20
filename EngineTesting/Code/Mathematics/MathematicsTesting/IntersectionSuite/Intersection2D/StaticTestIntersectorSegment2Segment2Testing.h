// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 15:55)

#ifndef MATHEMATICS_INTERSECTION_SUITE_STATIC_TEST_INTERSECTOR_SEGMENT2_SEGMENT2_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_STATIC_TEST_INTERSECTOR_SEGMENT2_SEGMENT2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class StaticTestIntersectorSegment2Segment2Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StaticTestIntersectorSegment2Segment2Testing); 

	private:
		void MainTest();	
		void SegmentTest(); 

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_INTERSECTION_SUITE_STATIC_TEST_INTERSECTOR_SEGMENT2_SEGMENT2_TESTING_H