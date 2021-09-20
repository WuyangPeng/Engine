// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.3 (2019/09/07 14:22)

#ifndef RENDERING_SHADERS_SUITE_ALPHA_STATE_TESTING_H
#define RENDERING_SHADERS_SUITE_ALPHA_STATE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class AlphaStateTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(AlphaStateTesting); 

	private:
		void MainTest();
	    void InitTest(); 
		void CopyTest();
		void StreamTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // RENDERING_SHADERS_SUITE_ALPHA_STATE_TESTING_H