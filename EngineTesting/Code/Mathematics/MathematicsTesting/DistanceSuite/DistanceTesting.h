// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 17:50)

#ifndef MATHEMATICS_DISTANCE_SUITE_DISTANCE_TESTING_H
#define MATHEMATICS_DISTANCE_SUITE_DISTANCE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class DistanceTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(DistanceTesting); 

	private:
		void MainTest();		
		void BaseTest();
		void StaticTest();
		void DynamicTest();
		void DerivativeTest();
		void IntervalTest();
		void BeginIntervalTest();
		void EndIntervalTest();
		void IterationIntervalTest();

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_DISTANCE_SUITE_DISTANCE_TESTING_H