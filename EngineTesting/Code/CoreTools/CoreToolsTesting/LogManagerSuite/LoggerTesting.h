// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 17:14)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class LoggerTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(LoggerTesting);

	private:
		void MainTest();
		void BaseTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_TESTING_H
