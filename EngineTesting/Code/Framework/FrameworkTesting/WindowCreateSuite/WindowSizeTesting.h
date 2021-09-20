// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/03 11:36)

#ifndef FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_SIZE_TESTING_H
#define FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_SIZE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class WindowSizeTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowSizeTesting;
		using ParentType = UnitTest;

	public:
		explicit WindowSizeTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void DefaultTest();
		void RandomTest();
		void LParamTest();
		void EqualTest();
		void SetWindowSizeTest();
		void SetWindowSizeExceptionTest(int width, int height);
		void OstreamTest();
		void NegativeTest();
		void WindowSizeExceptionTest(int width, int height);
		void SetNegative(int index, int& width, int& height) noexcept;
	};
}

#endif // FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_SIZE_TESTING_H