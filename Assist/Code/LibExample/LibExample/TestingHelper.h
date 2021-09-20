// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/09/29 23:37)

#ifndef LIB_EXAMPLE_TESTING_HELPER_H
#define LIB_EXAMPLE_TESTING_HELPER_H

#include "Framework/WindowProcess/WindowProcess.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"

namespace LibExample
{
	using WindowMainFunctionHelper = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, Framework::WindowProcessInterface>;
	class TestingHelper : public WindowMainFunctionHelper
	{
	public:
		using ClassType = TestingHelper;
		using ParentType = WindowMainFunctionHelper;			    ;
		using WindowApplicationInformation = Framework::WindowApplicationInformation;

	public:
		TestingHelper(HInstance hInstance,char* lpCmdLine,const WindowApplicationInformation& information,
                          const Framework::EnvironmentDirectory& environmentDirectory);
          

		CLASS_INVARIANT_OVERRIDE_DECLARE;
	};
}

#endif // LIB_EXAMPLE_TESTING_HELPER_H