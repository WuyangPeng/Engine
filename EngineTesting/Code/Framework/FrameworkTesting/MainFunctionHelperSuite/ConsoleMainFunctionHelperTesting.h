// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/01 15:31)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_CONSOLE_MAIN_FUNCTION_HELPER_TESTING_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_CONSOLE_MAIN_FUNCTION_HELPER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class ConsoleMainFunctionHelperTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = ConsoleMainFunctionHelperTesting;
		using ParentType = UnitTest;

	public:
		explicit ConsoleMainFunctionHelperTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void ConsoleMainFunctionHelper1Test();
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_CONSOLE_MAIN_FUNCTION_HELPER_TESTING_H