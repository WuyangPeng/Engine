// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/04 11:09)

#ifndef FRAMEWORK_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_LOOP_TESTING_H
#define FRAMEWORK_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_LOOP_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class WindowMessageLoopTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowMessageLoopTesting;
		using ParentType = UnitTest;

	public:
		explicit WindowMessageLoopTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void WindowMessageLoop1Test();
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_LOOP_TESTING_H