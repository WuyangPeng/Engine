// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 15:54)

#ifndef MATHEMATICS_INTERSECTION_SUITE_STATIC_TEST_INTERSECTOR_LINE2_LINE2_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_STATIC_TEST_INTERSECTOR_LINE2_LINE2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class StaticTestIntersectorLine2Line2Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StaticTestIntersectorLine2Line2Testing); 

	private:
		void MainTest();	
		void LineTest(); 

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_INTERSECTION_SUITE_STATIC_TEST_INTERSECTOR_LINE2_LINE2_TESTING_H