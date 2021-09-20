// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/04 18:00)

#ifndef RENDERING_SCENE_GRAPH_SUITE_SCREEN_TARGET_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_SCREEN_TARGET_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class ScreenTargetTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ScreenTargetTesting); 

	private:
		void MainTest();
		void CameraTest();
		void TrianglesMeshTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // RENDERING_SCENE_GRAPH_SUITE_SCREEN_TARGET_TESTING_H