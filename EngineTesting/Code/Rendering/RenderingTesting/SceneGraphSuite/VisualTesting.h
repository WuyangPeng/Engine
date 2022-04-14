// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/04 19:01)

#ifndef RENDERING_SCENE_GRAPH_SUITE_VISUAL_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_VISUAL_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class VisualTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(VisualTesting); 

	private:
		void MainTest();
		void InitTest();
		void CopyTest();
		void TransformTest();
		void StreamTest();
		void FileTest();

		void DoRunUnitTest() override;
	};
}

#endif // RENDERING_SCENE_GRAPH_SUITE_VISUAL_TESTING_H