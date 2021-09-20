// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/03 09:29)

#ifndef FRAMEWORK_WINDOW_TESTING_TESTING_HELPER_H
#define FRAMEWORK_WINDOW_TESTING_TESTING_HELPER_H

#include "FrameworkTestingWindowMessage.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"

namespace Framework
{
	using BaseType = WindowMainFunctionHelper<WindowsAPIFrameBuild, FrameworkHandle>;

	class TestingHelper final : public BaseType
	{
	public:
		using ClassType = TestingHelper;
		using ParentType = BaseType;

	public:
		TestingHelper(HInstance instance, const char* commandLine, const WindowApplicationInformation& information,
					  const EnvironmentDirectory& environmentDirectory);

		CLASS_INVARIANT_FINAL_DECLARE;
	};
}

#endif // FRAMEWORK_WINDOW_TESTING_TESTING_HELPER_H
