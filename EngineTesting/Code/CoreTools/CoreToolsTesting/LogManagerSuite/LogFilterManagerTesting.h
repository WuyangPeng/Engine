// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 17:14)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_LOG_FILTER_MANAGER_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_LOG_FILTER_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class LogFilterManagerTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(LogFilterManagerTesting);

	private:
		void MainTest();
		void ValidTest();
		void GetLogFilterTypeTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_SUITE_LOG_FILTER_MANAGER_TESTING_H