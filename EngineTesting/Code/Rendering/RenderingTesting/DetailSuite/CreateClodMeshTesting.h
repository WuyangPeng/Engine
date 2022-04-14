// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/06 16:40)

#ifndef RENDERING_DETAIL_SUITE_CREATE_CLOD_MESH_TESTING_H
#define RENDERING_DETAIL_SUITE_CREATE_CLOD_MESH_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class CreateClodMeshTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(CreateClodMeshTesting); 

	private:
		void MainTest();
		void CreateTrianglesMeshFile();
	    void InitTest();	 

		void DoRunUnitTest() override;
	};
}

#endif // RENDERING_DETAIL_SUITE_CREATE_CLOD_MESH_TESTING_H