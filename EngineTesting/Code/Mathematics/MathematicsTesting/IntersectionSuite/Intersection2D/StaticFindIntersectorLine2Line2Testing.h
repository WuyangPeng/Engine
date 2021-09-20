// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 15:53)

#ifndef MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_LINE2_LINE2_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_LINE2_LINE2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	template <typename R>
	class StaticFindIntersectorLine2Line2;

	class StaticFindIntersectorLine2Line2Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StaticFindIntersectorLine2Line2Testing); 

	private:
		void MainTest();	
		void LineTest(); 
		void ExceptionTest(const StaticFindIntersectorLine2Line2<float>& intersector);

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_LINE2_LINE2_TESTING_H