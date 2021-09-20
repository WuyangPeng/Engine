// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/07 10:58)

#ifndef FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_REGISTER_PARAMETER_TESTING_H
#define FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_REGISTER_PARAMETER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class WindowRegisterParameterTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowRegisterParameterTesting;
		using ParentType = UnitTest;

	public:
		explicit WindowRegisterParameterTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_REGISTER_PARAMETER_TESTING_H
