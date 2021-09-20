// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/05 17:15)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_POSTFIX_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_POSTFIX_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class LogMessagePostfixTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(LogMessagePostfixTesting);

	private:
		void MainTest();

		void PostfixFunctionDescribedTest();
		void NoPostfixTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_POSTFIX_TESTING_H
