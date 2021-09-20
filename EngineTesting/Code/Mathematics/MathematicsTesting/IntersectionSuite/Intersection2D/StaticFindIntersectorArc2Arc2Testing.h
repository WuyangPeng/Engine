// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 15:53)

#ifndef MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_ARC2_ARC2_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_ARC2_ARC2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	template <typename R>
	class StaticFindIntersectorArc2Arc2;

	class StaticFindIntersectorArc2Arc2Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StaticFindIntersectorArc2Arc2Testing); 

	private:
		void MainTest();	
		void SameTest();
		void EmptyTest();
		void PointTest();
		void ExceptionTest(const StaticFindIntersectorArc2Arc2<float>& intersector);

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_TESTING_H