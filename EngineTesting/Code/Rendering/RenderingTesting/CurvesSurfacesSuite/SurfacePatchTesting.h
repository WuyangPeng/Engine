// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 16:59)

#ifndef RENDERING_CURVES_SURFACES_SUITE_SURFACE_PATCH_TESTING_H
#define RENDERING_CURVES_SURFACES_SUITE_SURFACE_PATCH_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class SurfacePatchTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(SurfacePatchTesting); 

	private:
		void MainTest();
		void ParameterTest();
		void DerivativesTest();

		void DoRunUnitTest() override;
	};
}

#endif // RENDERING_CURVES_SURFACES_SUITE_SURFACE_PATCH_TESTING_H