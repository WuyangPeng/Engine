// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 17:05)

#ifndef MATHEMATICS_ALGEBRA_SUITE_AXES_ALIGN_BOUNDING_BOX_3D_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_AXES_ALIGN_BOUNDING_BOX_3D_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class AxesAlignBoundingBox3DTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(AxesAlignBoundingBox3DTesting); 

	private:
		void MainTest();	
		void ConstructionTest();
		void AccessTest();
		void IntersectionTest();

		virtual void DoRunUnitTest() override;		 
	};
}

#endif // MATHEMATICS_ALGEBRA_SUITE_AXES_ALIGN_BOUNDING_BOX_3D_TESTING_H