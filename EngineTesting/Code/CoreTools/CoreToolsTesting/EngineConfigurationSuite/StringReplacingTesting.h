// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/06 18:37)

#ifndef CORE_TOOLS_ENGINE_CONFIGURATION_SUITE_STRING_REPLACING_TESTING_H
#define CORE_TOOLS_ENGINE_CONFIGURATION_SUITE_STRING_REPLACING_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class StringReplacingTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StringReplacingTesting);

	private:
		void MainTest();
		void StringReplacingTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_ENGINE_CONFIGURATION_SUITE_STRING_REPLACING_TESTING_H