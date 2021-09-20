// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 16:58)

#ifndef CORE_TOOLS_COMMAND_SUITE_COMMAND_TESTING_H
#define CORE_TOOLS_COMMAND_SUITE_COMMAND_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class CommandTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(CommandTesting);

	private:
		void MainTest();
		void SucceedTest();
		void SetMinValueExceptionTest();
		void SetMaxValueExceptionTest();
		void SetInfValueExceptionTest();
		void SetSupValueExceptionTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_COMMAND_SUITE_COMMAND_TESTING_H