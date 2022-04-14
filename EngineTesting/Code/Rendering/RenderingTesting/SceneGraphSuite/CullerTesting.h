// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/04 17:59)

#ifndef RENDERING_SCENE_GRAPH_SUITE_CULLER_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_CULLER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class CullerTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(CullerTesting); 

	private:
		void MainTest();
	    void CameraTest();
	    void PlaneTest();
	    void SpatialPtrTest();
	    void VisibleTest();

		void DoRunUnitTest() override; 
	};
}

#endif // RENDERING_SCENE_GRAPH_SUITE_CULLER_TESTING_H