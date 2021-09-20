// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 17:08)

#ifndef MATHEMATICS_ALGEBRA_SUITE_VECTOR_2D_INFORMATION_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_VECTOR_2D_INFORMATION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Vector2DInformationTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Vector2DInformationTesting); 

	private:
		void MainTest();	
		void DimensionTest();
		void AxesAlignBoundingBoxTest();
		void DirectionTest();
		void ExtremeTest();

		virtual void DoRunUnitTest() override;	 
	};
}

#endif // MATHEMATICS_ALGEBRA_SUITE_VECTOR_2D_INFORMATION_TESTING_H