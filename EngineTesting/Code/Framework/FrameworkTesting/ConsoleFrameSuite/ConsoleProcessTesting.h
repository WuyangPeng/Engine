// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.1 (2020/05/22 23:48)

#ifndef FRAMEWORK_HELPER_SUITE_CONSOLE_PROCESS_TESTING_H
#define FRAMEWORK_HELPER_SUITE_CONSOLE_PROCESS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

namespace Framework
{
	class ConsoleProcessTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = ConsoleProcessTesting;
		using ParentType = UnitTest;		

	public:
		explicit ConsoleProcessTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;	 

	private:
		void DoRunUnitTest() final;

		void MainTest();		 
	};
}

#endif // FRAMEWORK_HELPER_SUITE_CONSOLE_PROCESS_TESTING_H