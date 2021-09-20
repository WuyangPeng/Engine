// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/03 16:18)

#ifndef FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H
#define FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H

#include "System/Window/Flags/WindowFlags.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class WindowCreateHandleTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowCreateHandleTesting;
		using ParentType = UnitTest;

	public:
		explicit WindowCreateHandleTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H
