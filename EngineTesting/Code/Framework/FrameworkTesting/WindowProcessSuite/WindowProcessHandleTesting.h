// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/04 22:03)

#ifndef FRAMEWORK_WINDOW_PROCESS_SUITE_WINDOW_PROCESS_HANDLE_TESTING_H
#define FRAMEWORK_WINDOW_PROCESS_SUITE_WINDOW_PROCESS_HANDLE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class WindowProcessHandleTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowProcessHandleTesting;
		using ParentType = UnitTest;

	public:
		explicit WindowProcessHandleTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_SUITE_WINDOW_PROCESS_HANDLE_TESTING_H
