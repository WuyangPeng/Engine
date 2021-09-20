// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/05 22:11)

#ifndef FRAMEWORK_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_H
#define FRAMEWORK_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class WindowMessageUnitTestSuiteTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowMessageUnitTestSuiteTesting;
		using ParentType = UnitTest;

	public:
		explicit WindowMessageUnitTestSuiteTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_H
