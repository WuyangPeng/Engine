// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/02 15:46)

#ifndef FRAMEWORK_HELPER_SUITE_MACINTOSH_MAIN_FUNCTION_HELPER_TESTING_H
#define FRAMEWORK_HELPER_SUITE_MACINTOSH_MAIN_FUNCTION_HELPER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

namespace Framework
{
	class MacintoshMainFunctionHelperTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = MacintoshMainFunctionHelperTesting;
		using ParentType = UnitTest;

	public:
		explicit MacintoshMainFunctionHelperTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void MacintoshMainFunctionHelper1Test();
	};
}

#endif // FRAMEWORK_HELPER_SUITE_MACINTOSH_MAIN_FUNCTION_HELPER_TESTING_H