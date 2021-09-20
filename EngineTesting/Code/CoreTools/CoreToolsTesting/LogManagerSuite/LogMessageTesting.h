// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 17:15)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class LogMessageTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(LogMessageTesting);

	private:
		void MainTest();
		void LogLevelTest();
		void LogFilterTest();
		void MessageTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_TESTING_H
