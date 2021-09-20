// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.1 (2020/05/22 23:48)

#ifndef FRAMEWORK_HELPER_SUITE_CONSOLE_FRAME_BUILD_TESTING_H
#define FRAMEWORK_HELPER_SUITE_CONSOLE_FRAME_BUILD_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

namespace Framework
{
	class ConsoleFrameBuildTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = ConsoleFrameBuildTesting;
		using ParentType = UnitTest;		

	public:
		explicit ConsoleFrameBuildTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;	 

	private:
		void DoRunUnitTest() final;

		void MainTest();		 
	};
}

#endif // FRAMEWORK_HELPER_SUITE_CONSOLE_FRAME_BUILD_TESTING_H