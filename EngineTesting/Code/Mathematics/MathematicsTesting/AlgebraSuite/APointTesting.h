// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 17:02)

#ifndef MATHEMATICS_ALGEBRA_SUITE_A_POINT_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_A_POINT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class APointTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(APointTesting); 

	private:
		void MainTest();
		void ConstructionTest();
		void AccessTest();
		void CalculateTest();

		void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_ALGEBRA_SUITE_A_POINT_TESTING_H