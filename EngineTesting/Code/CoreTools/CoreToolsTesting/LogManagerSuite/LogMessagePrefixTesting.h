// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/05 17:15)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_PREFIX_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_PREFIX_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class LogMessagePrefixTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(LogMessagePrefixTesting);

	private:
		void MainTest();
		void TimestampTest();
		void LogLevelTest();
		void LogFilterTest();
		void NoPrefixTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_PREFIX_TESTING_H
