// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.3 (2019/09/03 13:26)

#ifndef RENDERING_DATA_TYPES_SUITE_UTILITY_TESTING_H
#define RENDERING_DATA_TYPES_SUITE_UTILITY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class UtilityTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(UtilityTesting); 

	private:
		void MainTest();
	    void ReflectXTest();
	    void ReflectYTest();

		virtual void DoRunUnitTest() override; 
	};
}

#endif // RENDERING_DATA_TYPES_SUITE_UTILITY_TESTING_H