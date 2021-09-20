// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/06 22:24)

#ifndef WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_TESTING_HELPER_H
#define WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_TESTING_HELPER_H

#include "SuiteWindowMessage.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"

namespace Framework
{
	using TestingHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, WindowProcessTesting>;

	class TestingHelper final : public TestingHelperBase
	{
	public:
		using ClassType = TestingHelper;
		using ParentType = TestingHelperBase; 

	public:
		TestingHelper(HInstance instance, const char* commandLine, const WindowApplicationInformation& information,
					  const EnvironmentDirectory& environmentDirectory);

		CLASS_INVARIANT_FINAL_DECLARE;
	};
}

#endif // WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_TESTING_HELPER_H
