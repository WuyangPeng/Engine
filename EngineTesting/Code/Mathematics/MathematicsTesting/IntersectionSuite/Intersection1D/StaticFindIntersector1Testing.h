// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 15:52)

#ifndef MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR1_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR1_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class StaticFindIntersector1Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StaticFindIntersector1Testing); 

	private:
		void MainTest();	
		void IntersectorTest();

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR1_TESTING_H