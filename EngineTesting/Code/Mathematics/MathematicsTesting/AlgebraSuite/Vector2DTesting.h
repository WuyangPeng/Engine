// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 17:09)

#ifndef MATHEMATICS_BASE_SUITE_VECTOR_2D_TESTING_H
#define MATHEMATICS_BASE_SUITE_VECTOR_2D_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Vector2DTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Vector2DTesting); 

	private:
		void MainTest();
		void ConstructionTest();
		void AccessTest();
		void CalculateTest();
		void BarycentricsTest();

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_BASE_SUITE_VECTOR_2D_TESTING_H