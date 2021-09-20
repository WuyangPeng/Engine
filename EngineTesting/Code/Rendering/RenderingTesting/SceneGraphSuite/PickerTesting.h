// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.3 (2019/09/04 17:59)

#ifndef RENDERING_SCENE_GRAPH_SUITE_PICKER_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_PICKER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class PickerTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(PickerTesting); 

	private:
		void MainTest();
	    void BaseTest();

		virtual void DoRunUnitTest() override;

	private:
		int m_TestLoopCount;
	};
}

#endif // RENDERING_SCENE_GRAPH_SUITE_PICKER_TESTING_H