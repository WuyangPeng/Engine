// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.1 (2020/05/26 21:51)

#ifndef FRAMEWORK_HELPER_SUITE_MAIN_FUNCTION_TESTING_H
#define FRAMEWORK_HELPER_SUITE_MAIN_FUNCTION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

namespace Framework
{
	class MainFunctionTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = MainFunctionTesting;
		using ParentType = UnitTest;

	public:
		explicit MainFunctionTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void WinMainEntryPoint3Test();
		void WinMainEntryPoint4Test();
		void MainEntryPoint2Test();
		void GlutMainEntryPoint2Test();
		void AndroidMainEntryPoint2Test();
	};
}

#endif // FRAMEWORK_HELPER_SUITE_MAIN_FUNCTION_TESTING_H