// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/12 19:11)

#ifndef FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_MESSAGE_LOOP_TESTING_H
#define FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_MESSAGE_LOOP_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class AndroidMessageLoopTesting : public CoreTools::UnitTest
	{
	public:
		using ClassType = AndroidMessageLoopTesting;
		using ParentType = UnitTest;

	public:
		explicit AndroidMessageLoopTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;
		void MainTest();		
	};
}

#endif // FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_MESSAGE_LOOP_TESTING_H
