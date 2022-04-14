// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.3 (2019/09/04 17:56)

#ifndef RENDERING_SCENE_GRAPH_SUITE_CAMERA_MANAGE_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_CAMERA_MANAGE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class CameraManageTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(CameraManageTesting); 

	private:
		void MainTest();
	    void DepthTypeTest();

		void DoRunUnitTest() override;
	};
}

#endif // RENDERING_SCENE_GRAPH_SUITE_CAMERA_MANAGE_TESTING_H