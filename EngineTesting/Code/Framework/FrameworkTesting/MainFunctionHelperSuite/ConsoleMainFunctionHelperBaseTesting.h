// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.1 (2020/05/31 23:24)

#ifndef FRAMEWORK_HELPER_SUITE_CONSOLE_MAIN_FUNCTION_HELPER_BASE_TESTING_H
#define FRAMEWORK_HELPER_SUITE_CONSOLE_MAIN_FUNCTION_HELPER_BASE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

namespace Framework
{
	class ConsoleMainFunctionHelperBaseTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = ConsoleMainFunctionHelperBaseTesting;
		using ParentType = UnitTest;

	public:
		explicit ConsoleMainFunctionHelperBaseTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void ConsoleMainFunctionHelperBase1Test();
	};
}

#endif // FRAMEWORK_HELPER_SUITE_CONSOLE_MAIN_FUNCTION_HELPER_BASE_TESTING_H