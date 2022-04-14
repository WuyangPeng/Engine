// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.3 (2019/09/05 14:53)

#ifndef RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TESTING_H
#define RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class ControlledObjectTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ControlledObjectTesting); 

	private:
		void MainTest();
	    void InitTest();
	    void CopyTest();
		void StreamTest();

		void DoRunUnitTest() override;
	};
}

#endif // RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TESTING_H