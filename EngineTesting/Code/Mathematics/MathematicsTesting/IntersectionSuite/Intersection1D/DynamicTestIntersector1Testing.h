// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 15:52)

#ifndef MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_TEST_INTERSECTOR1_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_TEST_INTERSECTOR1_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	template <typename R>
	class DynamicTestIntersector1;

	class DynamicTestIntersector1Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(DynamicTestIntersector1Testing); 

	private:
		void MainTest();	
		void IntersectorTest();
		void GetFirstTimeException(const DynamicTestIntersector1<double>& intersector1);
		void GetLastTimeException(const DynamicTestIntersector1<double>& intersector1);

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_TEST_INTERSECTOR1_TESTING_H