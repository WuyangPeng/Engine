// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/22 21:25)

#ifndef EXAMPLE_EXAMPLE_HELPER_H
#define EXAMPLE_EXAMPLE_HELPER_H

#include "Framework/WindowProcess/WindowProcess.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"

namespace Example
{
	using WindowMainFunctionHelper = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, Framework::WindowProcessInterface>;
	class ExampleHelper : public WindowMainFunctionHelper
	{
	public:
		using ClassType = ExampleHelper;
		using ParentType = WindowMainFunctionHelper; ;
		using WindowApplicationInformation = Framework::WindowApplicationInformation;

	public:
		ExampleHelper(HInstance instance, char* cmdLine, const WindowApplicationInformation& information,
					  const Framework::EnvironmentDirectory& environmentDirectory);
		virtual ~ExampleHelper();

		CLASS_INVARIANT_OVERRIDE_DECLARE;
	};
}

#endif // EXAMPLE_EXAMPLE_HELPER_H