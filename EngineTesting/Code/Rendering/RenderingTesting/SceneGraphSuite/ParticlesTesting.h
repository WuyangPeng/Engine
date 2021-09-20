// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/04 17:59)

#ifndef RENDERING_SCENE_GRAPH_SUITE_PARTICLES_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_PARTICLES_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class ParticlesTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ParticlesTesting); 

	private:
		void MainTest();
		void CreateTrianglesMeshFile();
		void InitTest();
		void CopyTest();
		void TransformTest();
		void StreamTest();
		void FileTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // RENDERING_SCENE_GRAPH_SUITE_PARTICLES_TESTING_H