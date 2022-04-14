// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/04 18:00)

#ifndef RENDERING_SCENE_GRAPH_SUITE_PROJECTOR_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_PROJECTOR_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class ProjectorTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ProjectorTesting); 

	private:
		void MainTest();
	    void FrameTest();
	    void FrustumTest();
	    void ProjectionMatrixTest();
	    void AxesAlignBoundingBoxTest();
	    void StreamTest();

		void DoRunUnitTest() override; 
	};
}

#endif // RENDERING_SCENE_GRAPH_SUITE_PROJECTOR_TESTING_H