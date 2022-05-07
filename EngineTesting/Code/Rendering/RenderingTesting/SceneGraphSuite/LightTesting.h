// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.3 (2019/09/04 17:59)

#ifndef RENDERING_SCENE_GRAPH_SUITE_LIGHT_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_LIGHT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class LightTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(LightTesting); 

	private:
		void MainTest();
	    void BaseTest();
	    void CalculateTest();
	    void CopyTest();
	    void StreamTest();

		void DoRunUnitTest() override; 
	};
}

#endif // RENDERING_SCENE_GRAPH_SUITE_LIGHT_TESTING_H