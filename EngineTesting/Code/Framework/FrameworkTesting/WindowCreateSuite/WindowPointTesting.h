// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/03 14:18)

#ifndef FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_POINT_TESTING_H
#define FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_POINT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class WindowPointTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowPointTesting;
		using ParentType = UnitTest;

	public:
		explicit WindowPointTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void DefaultTest() noexcept;
		void RandomTest();
		void WindowPointUseTest() noexcept;
		void LParamTest();
		void EqualTest();
		void OstreamTest();
		void ConstexprTest() noexcept;
	};
}

#endif // FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_POINT_TESTING_H