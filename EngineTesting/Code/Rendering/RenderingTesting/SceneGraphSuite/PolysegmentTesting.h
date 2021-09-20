// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.3 (2019/09/04 18:00)

#ifndef RENDERING_SCENE_GRAPH_SUITE_POLYSEGMENT_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_POLYSEGMENT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class PolysegmentTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(PolysegmentTesting); 

	private:
		void MainTest();
		void InitTest();
		void CopyTest();
		void TransformTest();
		void StreamTest();
		void FileTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // RENDERING_SCENE_GRAPH_SUITE_POLYSEGMENT_TESTING_H