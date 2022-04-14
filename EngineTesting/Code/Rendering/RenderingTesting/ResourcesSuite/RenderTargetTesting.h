// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-2018
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫1.0.0.0 (2018/01/26 14:05)

#ifndef RENDERING_RESOURCES_SUITE_RENDER_TARGET_TESTING_H
#define RENDERING_RESOURCES_SUITE_RENDER_TARGET_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class RenderTargetTesting : public CoreTools::UnitTest
	{
	public:
            UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(RenderTargetTesting);

 

	private:
		void MainTest();
		void BaseTest();	
		void StreamTest();		

		void DoRunUnitTest() override;
	};
}

#endif // RENDERING_RESOURCES_SUITE_RENDER_TARGET_TESTING_H