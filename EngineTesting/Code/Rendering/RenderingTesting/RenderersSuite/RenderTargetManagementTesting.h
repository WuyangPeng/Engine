// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 10:06)

#ifndef RENDERING_RENDERERS_SUITE_RENDER_TARGET_MANAGEMENT_TESTING_H
#define RENDERING_RENDERERS_SUITE_RENDER_TARGET_MANAGEMENT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class RenderTargetManagementTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(RenderTargetManagementTesting); 

	private:
		void MainTest();	 
		 
		void DoRunUnitTest() override;
	};
}

#endif // RENDERING_RENDERERS_SUITE_RENDER_TARGET_MANAGEMENT_TESTING_H