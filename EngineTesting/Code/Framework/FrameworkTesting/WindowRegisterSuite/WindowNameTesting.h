// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/10 22:20)

#ifndef FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_NAME_TESTING_H
#define FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_NAME_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class WindowNameTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowNameTesting;
		using ParentType = UnitTest;

	public:
		explicit WindowNameTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void NameTest();
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_NAME_TESTING_H