// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 17:15)

#ifndef LOG_MANAGER_LOG_TESTING_H
#define LOG_MANAGER_LOG_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class LogTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(LogTesting);

	private:
		void MainTest();
		void LoadConfigurationTest();
                void OutTest() noexcept;
		void AppenderTest();

		void DoRunUnitTest() override;
	};
}

#endif // LOG_MANAGER_LOG_TESTING_H
