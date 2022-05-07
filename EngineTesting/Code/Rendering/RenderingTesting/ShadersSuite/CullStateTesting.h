// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.3 (2019/09/07 14:22)

#ifndef RENDERING_SHADERS_SUITE_CULL_STATE_TESTING_H
#define RENDERING_SHADERS_SUITE_CULL_STATE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class CullStateTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(CullStateTesting); 

	private:
		void MainTest();
	    void InitTest(); 
		void CopyTest();
		void StreamTest();

		void DoRunUnitTest() override;
	};
}

#endif // RENDERING_SHADERS_SUITE_CULL_STATE_TESTING_H