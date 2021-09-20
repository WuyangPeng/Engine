// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.3 (2019/09/05 16:21)

#ifndef RENDERING_CONTROLLERS_SUITE_POINT_CONTROLLER_TESTING_H
#define RENDERING_CONTROLLERS_SUITE_POINT_CONTROLLER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class PointControllerTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(PointControllerTesting); 

	private:
		void MainTest();
	    void InitTest();
	    void CopyTest();
	    void UpdateTest();
		void StreamTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // RENDERING_CONTROLLERS_SUITE_POINT_CONTROLLER_TESTING_H