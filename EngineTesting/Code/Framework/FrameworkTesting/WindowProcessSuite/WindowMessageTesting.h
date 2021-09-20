// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/04 15:52)

#ifndef FRAMEWORK_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_TESTING_H
#define FRAMEWORK_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class WindowMessageTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowMessageTesting;
		using ParentType = UnitTest;

	public:
		explicit WindowMessageTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_TESTING_H
