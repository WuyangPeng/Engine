// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/12 19:00)

#ifndef FRAMEWORK_WINDOW_API_FRAME_SUITE_WINDOW_MESSAGE_LOOP_TESTING_H
#define FRAMEWORK_WINDOW_API_FRAME_SUITE_WINDOW_MESSAGE_LOOP_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class WindowsAPIFrameBuildTesting : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowsAPIFrameBuildTesting;
		using ParentType = UnitTest;

	public:
		explicit WindowsAPIFrameBuildTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

	private:
		void MainTest(); 
	};
}

#endif // FRAMEWORK_WINDOW_API_FRAME_SUITE_WINDOW_MESSAGE_LOOP_TESTING_H