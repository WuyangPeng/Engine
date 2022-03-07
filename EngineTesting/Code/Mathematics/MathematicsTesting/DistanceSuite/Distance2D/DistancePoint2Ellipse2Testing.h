// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 17:48)

#ifndef MATHEMATICS_DISTANCE_SUITE_DISTANCE_POINT2_ELLIPSE2_TESTING_H
#define MATHEMATICS_DISTANCE_SUITE_DISTANCE_POINT2_ELLIPSE2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class DistancePoint2Ellipse2Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(DistancePoint2Ellipse2Testing); 

	private:
		void MainTest();
		void BaseTest();
		void StaticDistanceTest();
		void DynamicDistanceTest();
		void DerivativeDistanceTest();
		void IntervalDistanceTest();
		
		void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_DISTANCE_SUITE_DISTANCE_POINT2_ELLIPSE2_TESTING_H