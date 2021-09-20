// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.3 (2019/09/05 16:18)

#ifndef RENDERING_CONTROLLERS_SUITE_IK_JOINT_TESTING_H
#define RENDERING_CONTROLLERS_SUITE_IK_JOINT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class IKJointTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(IKJointTesting); 

	private:
		void MainTest();
		void InitTest();	
		void CopyTest();
		void StreamTest();
		void UpdateTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // RENDERING_CONTROLLERS_SUITE_IK_JOINT_TESTING_H